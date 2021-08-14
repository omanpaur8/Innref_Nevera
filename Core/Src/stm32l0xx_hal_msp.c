/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32l0xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization
  *                      and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
extern void BSP_MotorControl_StepClockHandler(uint8_t deviceId); 
extern void BSP_MotorControl_FlagInterruptHandler(void);
///ButtonHandler defined in main.c
extern void ButtonHandler(void);
/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */
/**
  * @brief PWM MSP Initialization 
  * @param[in] htim_pwm PWM handle pointer
  * @retval None
  */
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  if(htim_pwm->Instance == BSP_MOTOR_CONTROL_BOARD_PWM_REF)
  {
    /* Peripheral clock enable */
    __BSP_MOTOR_CONTROL_BOARD_CLCK_ENABLE_PWM_REF();
  
    /* GPIO clock enable -----------------------------------------------------*/
    /* already done in STSPIN220 GPIO initialization function */
  
    /* Configure STSPIN220 - PWM for REF pin ---------------------------------*/
    GPIO_InitStruct.Pin = BSP_MOTOR_CONTROL_BOARD_PIN_PWM_REF;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
    GPIO_InitStruct.Alternate = BSP_MOTOR_CONTROL_BOARD_AF_PWM_REF;
    HAL_GPIO_Init(BSP_MOTOR_CONTROL_BOARD_PORT_PWM_REF, &GPIO_InitStruct);
  }
}

/**
  * @brief PWM MSP De-Initialization
  * @param[in] htim_pwm PWM handle pointer
  * @retval None
  */
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* htim_pwm)
{
  if(htim_pwm->Instance == BSP_MOTOR_CONTROL_BOARD_PWM_REF)
  {
    /* Peripheral clock disable */
    __BSP_MOTOR_CONTROL_BOARD_CLCK_DISABLE_PWM_REF();
    
    /* GPIO Deconfiguration */
    HAL_GPIO_DeInit(BSP_MOTOR_CONTROL_BOARD_PORT_PWM_REF,\
      BSP_MOTOR_CONTROL_BOARD_PIN_PWM_REF);
  }
}

/**
  * @brief TIM MSP Initialization
  * @param[in] htim TIM handle pointer
  * @retval None
  */
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  if(htim->Instance == BSP_MOTOR_CONTROL_BOARD_TIM_STCK)
  {
    /* Peripheral clock enable -----------------------------------------------*/
    __BSP_MOTOR_CONTROL_BOARD_CLCK_ENABLE_TIM_STCK();
    
    /* GPIO clock enable -----------------------------------------------------*/
    /* already done in STSPIN220 GPIO initialization function */
  
    /* Configure STSPIN220 - TIMER for STCK pin ------------------------------*/
    GPIO_InitStruct.Pin = BSP_MOTOR_CONTROL_BOARD_PIN_TIM_STCK_MODE3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
    GPIO_InitStruct.Alternate = BSP_MOTOR_CONTROL_BOARD_AF_TIM_STCK;
    HAL_GPIO_Init(BSP_MOTOR_CONTROL_BOARD_PORT_TIM_STCK_MODE3, &GPIO_InitStruct);
      
    /* Enable the timer interrupt & set priority -----------------------------*/
    HAL_NVIC_SetPriority(BSP_MOTOR_CONTROL_BOARD_IRQn_TIM_STCK,\
      BSP_MOTOR_CONTROL_BOARD_PRIORITY_TIM_STCK,\
      0);
    HAL_NVIC_EnableIRQ(BSP_MOTOR_CONTROL_BOARD_IRQn_TIM_STCK);
  }
}

/**
  * @brief TIM MSP DeInitialization
  * @param[in] htim TIM handle pointer
  * @retval None
  */
void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == BSP_MOTOR_CONTROL_BOARD_TIM_STCK)
  {
    /* Peripheral clock disable ----------------------------------------------*/
    __BSP_MOTOR_CONTROL_BOARD_CLCK_DISABLE_TIM_STCK();
    
    /* GPIO clock disable ----------------------------------------------------*/
    /* do not disable as the clock is likely used for other HW resources */
  
    /* STCK pin GPIO deinitialization ----------------------------------------*/
    HAL_GPIO_DeInit(BSP_MOTOR_CONTROL_BOARD_PORT_TIM_STCK_MODE3,\
      BSP_MOTOR_CONTROL_BOARD_PIN_TIM_STCK_MODE3);
      
    /* Disable the timer interrupt -------------------------------------------*/
    HAL_NVIC_DisableIRQ(BSP_MOTOR_CONTROL_BOARD_IRQn_TIM_STCK);
  }
}

/**
  * @brief  Output Compare callback in non blocking mode 
  * @param  htim : TIM OC handle
  * @retval None
  */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
  if((htim->Instance == BSP_MOTOR_CONTROL_BOARD_TIM_STCK)&&\
     (htim->Channel == BSP_MOTOR_CONTROL_BOARD_HAL_ACT_CHAN_TIM_STCK))
    {
      BSP_MotorControl_StepClockHandler(0);
    }
}

/**
  * @brief External Line Callback 
  * @param[in] GPIO_Pin pin number
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == BSP_MOTOR_CONTROL_BOARD_PIN_EN_AND_FAULT)
  {
    BSP_MotorControl_FlagInterruptHandler();
  }
  if (GPIO_Pin == KEY_BUTTON_PIN)
  {
    ButtonHandler();
  }
 }
/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
