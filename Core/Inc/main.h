/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "x_nucleo_ihmxx.h"
#include "..\Components\stspin220\stspin220.h"
#include "x_nucleo_ihm06a1_stm32l0xx.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void MyErrorHandler(uint16_t error);
void BloqueMotor(void);
void MyMotorInit(void);
void EnableMotors(uint8_t opc);
void calib_motor(void);
void calib_motor2(void);
void calib_motor3(void);
void calib_motor4(void);
void calib_motor5(void);
void calib_motor6(void);
void stopMotor(void);
void sensorsTest(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VL53_XSHUT_1_Pin GPIO_PIN_14
#define VL53_XSHUT_1_GPIO_Port GPIOC
#define DRV_FCA_6_Pin GPIO_PIN_15
#define DRV_FCA_6_GPIO_Port GPIOC
#define DRV_FCB_6_Pin GPIO_PIN_0
#define DRV_FCB_6_GPIO_Port GPIOH
#define DRV_RES_6_Pin GPIO_PIN_1
#define DRV_RES_6_GPIO_Port GPIOH
#define DRV_EN_6_Pin GPIO_PIN_0
#define DRV_EN_6_GPIO_Port GPIOC
#define VL53_XSHUT_6_Pin GPIO_PIN_2
#define VL53_XSHUT_6_GPIO_Port GPIOC
#define DRV_FCA_5_Pin GPIO_PIN_3
#define DRV_FCA_5_GPIO_Port GPIOC
#define DRV_FCB_5_Pin GPIO_PIN_0
#define DRV_FCB_5_GPIO_Port GPIOA
#define DRV_RES_5_Pin GPIO_PIN_1
#define DRV_RES_5_GPIO_Port GPIOA
#define DRV_EN_5_Pin GPIO_PIN_4
#define DRV_EN_5_GPIO_Port GPIOA
#define VL53_XSHUT_5_Pin GPIO_PIN_5
#define VL53_XSHUT_5_GPIO_Port GPIOA
#define DRV_FCA_4_Pin GPIO_PIN_7
#define DRV_FCA_4_GPIO_Port GPIOA
#define DRV_FCB_4_Pin GPIO_PIN_4
#define DRV_FCB_4_GPIO_Port GPIOC
#define DRV_RES_4_Pin GPIO_PIN_5
#define DRV_RES_4_GPIO_Port GPIOC
#define DRV_EN_4_Pin GPIO_PIN_0
#define DRV_EN_4_GPIO_Port GPIOB
#define VL53_XSHUT_4_Pin GPIO_PIN_1
#define VL53_XSHUT_4_GPIO_Port GPIOB
#define VL53_XSHUT_3_Pin GPIO_PIN_10
#define VL53_XSHUT_3_GPIO_Port GPIOB
#define DRV_RES_3_Pin GPIO_PIN_12
#define DRV_RES_3_GPIO_Port GPIOB
#define DRV_EN_3_Pin GPIO_PIN_13
#define DRV_EN_3_GPIO_Port GPIOB
#define DRV_FCB_3_Pin GPIO_PIN_14
#define DRV_FCB_3_GPIO_Port GPIOB
#define DRV_FCA_3_Pin GPIO_PIN_15
#define DRV_FCA_3_GPIO_Port GPIOB
#define VL53_XSHUT_2_Pin GPIO_PIN_6
#define VL53_XSHUT_2_GPIO_Port GPIOC
#define DRV_FCB_2_Pin GPIO_PIN_9
#define DRV_FCB_2_GPIO_Port GPIOC
#define DRV_MOD4_Pin GPIO_PIN_8
#define DRV_MOD4_GPIO_Port GPIOA
#define DRV_RES_2_Pin GPIO_PIN_9
#define DRV_RES_2_GPIO_Port GPIOA
#define DRV_EN_2_Pin GPIO_PIN_10
#define DRV_EN_2_GPIO_Port GPIOA
#define DRV_FCA_2_Pin GPIO_PIN_11
#define DRV_FCA_2_GPIO_Port GPIOA
#define DRV_FCB_1_Pin GPIO_PIN_12
#define DRV_FCB_1_GPIO_Port GPIOA
#define DRV_FCA_1_Pin GPIO_PIN_15
#define DRV_FCA_1_GPIO_Port GPIOA
#define GPIO_EXP_1_Pin GPIO_PIN_10
#define GPIO_EXP_1_GPIO_Port GPIOC
#define GPIO_EXP_2_Pin GPIO_PIN_11
#define GPIO_EXP_2_GPIO_Port GPIOC
#define DRV_MOD1_Pin GPIO_PIN_4
#define DRV_MOD1_GPIO_Port GPIOB
#define DRV_RES_1_Pin GPIO_PIN_5
#define DRV_RES_1_GPIO_Port GPIOB
#define DRV_MOD2_Pin GPIO_PIN_6
#define DRV_MOD2_GPIO_Port GPIOB
#define DRV_EN_1_Pin GPIO_PIN_7
#define DRV_EN_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
