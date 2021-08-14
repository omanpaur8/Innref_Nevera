/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "distancia.h"
#include "com_ceit.h"
#include "captura.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
stDistancia stdistancia;
stComCEIT stcomceit;
stCaptura stcaptura;
stMotor stmotor;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static volatile uint16_t gLastError;
uint8_t Char_USART5, garb=1, Cont_USART5=0;
uint8_t Data_CALIB_OK[8] = {0x01,0x08,0x11,0x81,0x02,0x4F,0x4B,0xF9};
// España 5 parrillas
//uint8_t DataRX[RX_DATA_SIZE] ={0x5,0x1A,0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA};

// España 4 parrillas
//uint8_t DataRX[RX_DATA_SIZE] ={0x4,0x1A,0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA};

// Innref todo agua
//uint8_t DataRX[RX_DATA_SIZE] ={0x5,0x22,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA};

// Innref todo coca
//uint8_t DataRX[RX_DATA_SIZE] ={0x5,0x22,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
//										0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
//										0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
//										0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
//										0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA};

uint8_t DataRX[RX_DATA_SIZE] ={0x5,0x22,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
										0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
										0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0x3D,0x00,0xFF,0xFF,0xFF,0xFF,
										0x35,0x00,0x35,0x00,0x35,0x00,0x35,0x00,0x35,0x00,0x35,0x00,0x35,0x00,0x35,0x00,0x35,0x00,0xFF,0xFF,
										0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0x44,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static void MyFlagInterruptHandler(void);
void ButtonHandler(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//----------Interrupt USART----------------------------------
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//USART CEIT-------------------
	if (huart->Instance == USART5) {
		HAL_UART_Receive_IT(&huart5, &Char_USART5, 1);
		if(garb){
			if(Char_USART5 == 1){
				garb = 0;
				stcomceit.Rx_Buffer[0] = Char_USART5;
				Cont_USART5++;
			}
		}else{
			if (Char_USART5 != 250) {
				if (Cont_USART5 < 5){
					stcomceit.Rx_Buffer[Cont_USART5] = Char_USART5;
					Cont_USART5++;
				}else if (stcomceit.Rx_Buffer[CMD] == GET_DATA) {
					stcomceit.Rx_Buffer[Cont_USART5] = Char_USART5;
					HAL_UART_Transmit(&huart2, stcomceit.Rx_Buffer, sizeof(stcomceit.Rx_Buffer), 1000);
					Cont_USART5 = 0;
					stcomceit.xRxDoneFlag = true;
					garb = 1;
				}else if (stcomceit.Rx_Buffer[CMD] == CONFIG){
					stcomceit.Rx_Data[Cont_USART5-5] = Char_USART5;
					Cont_USART5++;
				}
			}
			else if (Char_USART5 == 250) {
				stcomceit.Rx_Data[Cont_USART5-5] = Char_USART5;
				Cont_USART5 = 0;
				stcomceit.xRxDoneFlag = true;
				garb = 1;
				HAL_UART_Transmit(&huart2, stcomceit.Rx_Buffer, sizeof(stcomceit.Rx_Buffer), 1000);
				HAL_UART_Transmit(&huart2, stcomceit.Rx_Data, sizeof(stcomceit.Rx_Data), 1000);
			}
		}
	}

}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t sensorOK, respuesta, data=0,i,j;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_USART5_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart5, &Char_USART5, 1);
  Iniciar_EstrucCaptura(&stcaptura);
  Iniciar_EstrucComCEIT(&stcomceit);
  Iniciar_EstrucDistancia(&stdistancia);
  Iniciar_EstrucMotor(&stmotor);
  for(i=0; i<RX_DATA_SIZE;i++)
  {
	  stcomceit.Rx_Data[i] = DataRX[i];
  }
  ConfigParrillas(&stcaptura, &stcomceit, &stmotor, &stdistancia);
  Ordenar(&stmotor,&stdistancia);
  IniciarSensores(&stdistancia);
  MyMotorInit();

//  calib_motor5();
  calib_motor();
  calib_motor2();
  calib_motor4();
  calib_motor5();
  calib_motor3();

//  calib_motor6();
  EnableMotors(7);
  HAL_UART_Transmit(&huart5, Data_CALIB_OK, 8 , 200);
  HAL_UART_Transmit(&huart2, Data_CALIB_OK, 8 , 200);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
//		sensorsTest();

	 /* Código máquinas de estado */
	  BloqueCOM_CEIT(&stcomceit);
	  BloqueCaptura(&stcaptura, &stcomceit, &stmotor, &stdistancia);
	  BloqueMotor();
	  /* Bloque distancia */
	  if(stdistancia.bandDistancia){
		  stdistancia.contParrilla = stdistancia.sensor[stdistancia.contDistancia];
//		  VL53L1_StartMeasurement( &stdistancia.VL53L1_DEV[stdistancia.contParrilla] );
		  sensorOK = BloqueDistancia(&stdistancia);
		  stdistancia.bandDistancia = false;
		  stdistancia.contDistancia++;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void BloqueMotor(void) {
	uint8_t unidad, decena, centena, mil;
	uint8_t i,j;

	/* Bloque motor */
	if(stmotor.bandMotor){
		if(stmotor.posMotor < stmotor.MaxPosMotor){
			/* Go next stop */
			BSP_MotorControl_GoTo(MOTOR_ID, stmotor.recorrido[stmotor.posMotor]);
			BSP_MotorControl_WaitWhileActive(MOTOR_ID);

			stmotor.posMotor++;
			stmotor.bandMotor = false;
		}else if(stmotor.posMotor <= stmotor.MaxPosMotor+2){
			stmotor.bandMotor = true;
			stmotor.posMotor++;
		} else {
			/* GO HOME */
			BSP_MotorControl_GoTo(MOTOR_ID, stmotor.recorrido[0]);
			BSP_MotorControl_WaitWhileActive(MOTOR_ID);
			/* Disable the power bridges */
			BSP_MotorControl_CmdDisable(MOTOR_ID);
			/* Turn off power bridges when motor is stopped */
			BSP_MotorControl_SetStopMode(MOTOR_ID, HIZ_MODE);
			stmotor.posMotor = stmotor.posInicial;
			stmotor.bandMotor = false;
	//				for(i=1; i<6; i++)
	//				{
	//					HAL_UART_Transmit(&huart5, (uint8_t*)"S", strlen("S"), 20);
	//					HAL_UART_Transmit(&huart5, &i, sizeof(centena), 50);
	//					HAL_UART_Transmit(&huart5, (uint8_t*)"X", strlen("S"), 20);
	//					HAL_UART_Transmit(&huart5, (uint8_t*)";", strlen(";"), 20);
	//					for(j=0; j<stdistancia.cantFilas[i-1]; j++)
	//					{
	//						  Convertir4Cif(stdistancia.datosDistancia[i-1][j], &mil, &centena, &decena, &unidad);
	//						  HAL_UART_Transmit(&huart5, &mil, sizeof(centena), 50);
	//						  HAL_UART_Transmit(&huart5, &centena, sizeof(centena), 50);
	//						  HAL_UART_Transmit(&huart5, &decena, sizeof(decena), 50);
	//						  HAL_UART_Transmit(&huart5, &unidad, sizeof(unidad), 50);
	//						  HAL_UART_Transmit(&huart5, (uint8_t*)";", strlen(";"), 20);
	//					}
	//					HAL_UART_Transmit(&huart5, (uint8_t*)"\n", strlen("\n"), 20);
	//
	//				}
			for(i=1; i<6; i++){
				HAL_UART_Transmit(&huart2, (uint8_t*)"S", strlen("S"), 20);
				HAL_UART_Transmit(&huart2, &i, sizeof(i), 50);
				HAL_UART_Transmit(&huart2, (uint8_t*)"X", strlen("S"), 20);
				HAL_UART_Transmit(&huart2, (uint8_t*)";", strlen(";"), 20);
				for(j=0; j<stdistancia.cantFilas[i-1]; j++){
					  Convertir4Cif(stdistancia.datosDistancia[i-1][j], &mil, &centena, &decena, &unidad);
					  HAL_UART_Transmit(&huart2, &mil, sizeof(centena), 50);
					  HAL_UART_Transmit(&huart2, &centena, sizeof(centena), 50);
					  HAL_UART_Transmit(&huart2, &decena, sizeof(decena), 50);
					  HAL_UART_Transmit(&huart2, &unidad, sizeof(unidad), 50);
					  HAL_UART_Transmit(&huart2, (uint8_t*)";", strlen(";"), 20);
				}
				HAL_UART_Transmit(&huart2, (uint8_t*)"\n", strlen("\n"), 20);
			}
	//				  calib_motor5();
			  calib_motor();
			  calib_motor2();
			  calib_motor4();
			  calib_motor5();
			  calib_motor3();
			//  calib_motor6();
			  EnableMotors(7);
			  HAL_UART_Transmit(&huart5, Data_CALIB_OK, 8 , 200);
			  HAL_UART_Transmit(&huart2, Data_CALIB_OK, 8 , 200);
		}
	}
}

void MyMotorInit(void) {

	uint32_t myFreqPwm;
//----- Init of the Motor control library
	/* Set the STSPIN220 library to use 1 device */
	BSP_MotorControl_SetNbDevices(BSP_MOTOR_CONTROL_BOARD_ID_STSPIN220, 1);
	/* When BSP_MotorControl_Init is called with NULL pointer,                  */
	/* the STSPIN220 parameters are set with the predefined values from file    */
	/* stspin220_target_config.h, otherwise the parameters are set using the    */
	/* initDeviceParameters structure values.                                   */
	//BSP_MotorControl_Init(BSP_MOTOR_CONTROL_BOARD_ID_STSPIN220, &initDeviceParameters);
	BSP_MotorControl_Init(BSP_MOTOR_CONTROL_BOARD_ID_STSPIN220, NULL);
	/* Attach the function MyFlagInterruptHandler (defined below) to the flag interrupt */
	BSP_MotorControl_AttachFlagInterrupt(MyFlagInterruptHandler);
	/* Attach the function MyErrorHandler (defined below) to the error Handler*/
	BSP_MotorControl_AttachErrorHandler(MyErrorHandler);
//----- Configure Button for user interaction
	/* Set Systick Interrupt priority highest to ensure no lock by using HAL_Delay */
	HAL_NVIC_SetPriority(SysTick_IRQn, 0x0, 0x0);
	/* Get the PWM frequency used for the VREFA and VREFB voltage generation */
	myFreqPwm = BSP_MotorControl_GetBridgeInputPwmFreq(0);

	/* Select step mode */
	switch (AJUSTE_REL_PASOS){
	case 1:
		/* Increase acceleration microstep/s^2*/
		BSP_MotorControl_SetAcceleration(MOTOR_ID, 65535);
		/* Increase deceleration microstep/s^2 */
		BSP_MotorControl_SetDeceleration(MOTOR_ID, 65535);
		/* Increase speed microstep/s */
		BSP_MotorControl_SetMaxSpeed(MOTOR_ID, 25000);//25000
		break;
	case 2:
		BSP_MotorControl_SelectStepMode(MOTOR_ID, STEP_MODE_1_16);
		/*Increase the Run and accelerating torque */
		BSP_MotorControl_SetTorque(0, RUN_TORQUE, 40);
		BSP_MotorControl_SetTorque(0, ACC_TORQUE, 90);
		/* Increase acceleration microstep/s^2 */
		BSP_MotorControl_SetAcceleration(MOTOR_ID, 65535);
		/* Increase deceleration microstep/s^2 */
		BSP_MotorControl_SetDeceleration(MOTOR_ID, 65535);
		/* Increase speed to microstep/s */
		BSP_MotorControl_SetMaxSpeed(MOTOR_ID, 15000);
		break;
	case 4:
		BSP_MotorControl_SelectStepMode(MOTOR_ID, STEP_MODE_1_8);
		/*Increase the Run and accelerating torque */
		BSP_MotorControl_SetTorque(0, RUN_TORQUE, 40);
		BSP_MotorControl_SetTorque(0, ACC_TORQUE, 60);
		/* Increase acceleration microstep/s^2 */
		BSP_MotorControl_SetAcceleration(MOTOR_ID, 65535);
		/* Increase deceleration microstep/s^2 */
		BSP_MotorControl_SetDeceleration(MOTOR_ID, 65535);
		/* Increase speed microstep/s */
		BSP_MotorControl_SetMaxSpeed(MOTOR_ID, 7600);
		break;
	case 8:
		BSP_MotorControl_SelectStepMode(MOTOR_ID, STEP_MODE_1_4);
		/* Increase the Run and accelerating torque */
		BSP_MotorControl_SetTorque(0, RUN_TORQUE, 80);
		BSP_MotorControl_SetTorque(0, ACC_TORQUE, 80);
		/* Increase acceleration microstep/s^2 */
		BSP_MotorControl_SetAcceleration(MOTOR_ID, 65535);
		/* Increase deceleration microstep/s^2 */
		BSP_MotorControl_SetDeceleration(MOTOR_ID, 65535);
		/* Increase speed microstep/s */
		BSP_MotorControl_SetMaxSpeed(MOTOR_ID, 31000);
		break;
	default:
		/* Increase acceleration microstep/s^2 */
		BSP_MotorControl_SetAcceleration(MOTOR_ID, 65535);
		/* Increase deceleration microstep/s^2 */
		BSP_MotorControl_SetDeceleration(MOTOR_ID, 65535);
		/* Increase speed microstep/s */
		BSP_MotorControl_SetMaxSpeed(MOTOR_ID, 25000);
		break;
	}
}

void EnableMotors(uint8_t opc)
{
	switch(opc)
	{
		case 1:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_SET);
			break;
		default:
			HAL_GPIO_WritePin(DRV_EN_1_GPIO_Port, DRV_EN_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_1_GPIO_Port, DRV_RES_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_2_GPIO_Port, DRV_EN_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_2_GPIO_Port, DRV_RES_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_3_GPIO_Port, DRV_EN_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_3_GPIO_Port, DRV_RES_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_4_GPIO_Port, DRV_EN_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_4_GPIO_Port, DRV_RES_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_5_GPIO_Port, DRV_EN_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_5_GPIO_Port, DRV_RES_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_EN_6_GPIO_Port, DRV_EN_6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(DRV_RES_6_GPIO_Port, DRV_RES_6_Pin, GPIO_PIN_RESET);
			break;
	}
}


void calib_motor(void) {
	int32_t pos;

	EnableMotors(1);
	//-----Set Home position according FCA
	if (HAL_GPIO_ReadPin(DRV_FCA_1_GPIO_Port, DRV_FCA_1_Pin) == GPIO_PIN_SET) {
		//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_1_GPIO_Port, DRV_FCA_1_Pin) == GPIO_PIN_SET);

		stopMotor();

	} else {
		//-----Move device FORWARD till get to FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, FORWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_1_GPIO_Port, DRV_FCA_1_Pin)== GPIO_PIN_RESET);

		//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_1_GPIO_Port, DRV_FCA_1_Pin) == GPIO_PIN_SET);
	}
	if(AJUSTE_INICIAL>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	if(AJUSTE_INICIAL_M1>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL_M1);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL_M1);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	stopMotor();
	/* Get current position */
	pos = BSP_MotorControl_GetPosition(MOTOR_ID);
	/* Set the current position to be the Home position */
	BSP_MotorControl_SetHome(MOTOR_ID, pos);
	HAL_Delay(T_STOP);
	if(CALIB)
	{
	//-----Move device BACKWARD till found FC2 and mark the position
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, 7889 * 45/AJUSTE_REL_PASOS);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCB_1_GPIO_Port, DRV_FCB_1_Pin) == GPIO_PIN_RESET);

		stopMotor();
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);
		/* Set the current position to be the Home position */
		BSP_MotorControl_SetMark(MOTOR_ID, pos);
	//----- Go Home
		/* Request to go to Home */
		BSP_MotorControl_GoHome(MOTOR_ID);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);
		stopMotor();
	}
}

void calib_motor2(void) {
	int32_t pos;

	EnableMotors(2);
	//-----Set Home position according FC1
	if (HAL_GPIO_ReadPin(DRV_FCA_2_GPIO_Port, DRV_FCA_2_Pin) == GPIO_PIN_SET) {
		//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_2_GPIO_Port, DRV_FCA_2_Pin) == GPIO_PIN_SET);

		stopMotor();

	} else {
		//-----Move device FORWARD till get to FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, FORWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_2_GPIO_Port, DRV_FCA_2_Pin)== GPIO_PIN_RESET);

		//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_2_GPIO_Port, DRV_FCA_2_Pin)
				== GPIO_PIN_SET);
	}
	if(AJUSTE_INICIAL>=0)
	{
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL);
	}else
	{
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	if(AJUSTE_INICIAL_M2>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL_M2);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL_M2);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
//	BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *5);

	stopMotor();
	/* Get current position */
	pos = BSP_MotorControl_GetPosition(MOTOR_ID);
	/* Set the current position to be the Home position */
	BSP_MotorControl_SetHome(MOTOR_ID, pos);

	HAL_Delay(T_STOP);

	if(CALIB)
	{
	//-----Move device BACKWARD till found FC2 and mark the position
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, 7889 * 45/AJUSTE_REL_PASOS);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCB_2_GPIO_Port, DRV_FCB_2_Pin) == GPIO_PIN_RESET);
		stopMotor();

		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);

		/* Set the current position to be the Home position */
		BSP_MotorControl_SetMark(MOTOR_ID, pos);

	//----- Go Home
		/* Request to go to Home */
		BSP_MotorControl_GoHome(MOTOR_ID);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);

		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);

		stopMotor();
	}
}

void calib_motor3(void) {
	int32_t pos;

	EnableMotors(3);
////-------------------------------------------------------------------------------------------------
	//-----Set Home position according FC1
	if (HAL_GPIO_ReadPin(DRV_FCA_3_GPIO_Port, DRV_FCA_3_Pin) == GPIO_PIN_SET) {
//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_3_GPIO_Port, DRV_FCA_3_Pin) == GPIO_PIN_SET);
		stopMotor();
	} else {
//-----Move device FORWARD till get to FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, FORWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_3_GPIO_Port, DRV_FCA_3_Pin)== GPIO_PIN_RESET);
//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_3_GPIO_Port, DRV_FCA_3_Pin)
				== GPIO_PIN_SET);
	}
	if(AJUSTE_INICIAL>=0)
	{
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL);
	}else
	{
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	if(AJUSTE_INICIAL_M3>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL_M3);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL_M3);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	stopMotor();
	/* Get current position */
	pos = BSP_MotorControl_GetPosition(MOTOR_ID);

	/* Set the current position to be the Home position */
	BSP_MotorControl_SetHome(MOTOR_ID, pos);

	HAL_Delay(T_STOP);

	if(CALIB)
	{
	//-----Move device BACKWARD till found FC2 and mark the position
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, 7889 * 45/AJUSTE_REL_PASOS);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCB_3_GPIO_Port, DRV_FCB_3_Pin) == GPIO_PIN_RESET);

		stopMotor();

		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);

		/* Set the current position to be the Home position */
		BSP_MotorControl_SetMark(MOTOR_ID, pos);

	//----- Go Home
		/* Request to go to Home */
		BSP_MotorControl_GoHome(MOTOR_ID);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);
		stopMotor();
	}
}

void calib_motor4(void) {
	int32_t pos;

	EnableMotors(4);
////-------------------------------------------------------------------------------------------------
	//-----Set Home position according FC1
	if (HAL_GPIO_ReadPin(DRV_FCA_4_GPIO_Port, DRV_FCA_4_Pin) == GPIO_PIN_SET) {
//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_4_GPIO_Port, DRV_FCA_4_Pin) == GPIO_PIN_SET);

		stopMotor();

	} else {
//-----Move device FORWARD till get to FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, FORWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_4_GPIO_Port, DRV_FCA_4_Pin)== GPIO_PIN_RESET);

//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_4_GPIO_Port, DRV_FCA_4_Pin)
				== GPIO_PIN_SET);
	}
	if(AJUSTE_INICIAL>=0)
	{
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL);
	}else
	{
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	if(AJUSTE_INICIAL_M4>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL_M4);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL_M4);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	stopMotor();

	/* Get current position */
	pos = BSP_MotorControl_GetPosition(MOTOR_ID);

	/* Set the current position to be the Home position */
	BSP_MotorControl_SetHome(MOTOR_ID, pos);

	HAL_Delay(T_STOP);
	if(CALIB)
	{
	//-----Move device BACKWARD till found FC2 and mark the position
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, 7889 * 45/AJUSTE_REL_PASOS);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCB_4_GPIO_Port, DRV_FCB_4_Pin) == GPIO_PIN_RESET);

		stopMotor();
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);

		/* Set the current position to be the Home position */
		BSP_MotorControl_SetMark(MOTOR_ID, pos);

	//----- Go Home
		/* Request to go to Home */
		BSP_MotorControl_GoHome(MOTOR_ID);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);
		stopMotor();
	}
}

void calib_motor5(void) {
	int32_t pos;

	EnableMotors(5);
////-------------------------------------------------------------------------------------------------
	//-----Set Home position according FC1
	if (HAL_GPIO_ReadPin(DRV_FCA_5_GPIO_Port, DRV_FCA_5_Pin) == GPIO_PIN_SET) {
//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_5_GPIO_Port, DRV_FCA_5_Pin) == GPIO_PIN_SET);

		stopMotor();

	} else {
//-----Move device FORWARD till get to FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, FORWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_5_GPIO_Port, DRV_FCA_5_Pin)== GPIO_PIN_RESET);

//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_5_GPIO_Port, DRV_FCA_5_Pin)
				== GPIO_PIN_SET);
	}
	if(AJUSTE_INICIAL>=0)
	{
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL);
	}else
	{
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	if(AJUSTE_INICIAL_M5>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL_M5);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL_M5);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	stopMotor();
	/* Get current position */
	pos = BSP_MotorControl_GetPosition(MOTOR_ID);
	/* Set the current position to be the Home position */
	BSP_MotorControl_SetHome(MOTOR_ID, pos);

	HAL_Delay(T_STOP);
	if(CALIB)
	{
	//-----Move device BACKWARD till found FC2 and mark the position
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, 7889 * 45/AJUSTE_REL_PASOS);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCB_5_GPIO_Port, DRV_FCB_5_Pin) == GPIO_PIN_RESET);

		stopMotor();
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);
		/* Set the current position to be the Home position */
		BSP_MotorControl_SetMark(MOTOR_ID, pos);
	//----- Go Home
		/* Request to go to Home */
		BSP_MotorControl_GoHome(MOTOR_ID);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);
		stopMotor();
	}
}

void calib_motor6(void) {
	int32_t pos;

	EnableMotors(6);
////-------------------------------------------------------------------------------------------------
	//-----Set Home position according FC1
	if (HAL_GPIO_ReadPin(DRV_FCA_6_GPIO_Port, DRV_FCA_6_Pin) == GPIO_PIN_SET) {
//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_6_GPIO_Port, DRV_FCA_6_Pin) == GPIO_PIN_SET);

		stopMotor();

	} else {
//-----Move device FORWARD till get to FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, FORWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_6_GPIO_Port, DRV_FCA_6_Pin)== GPIO_PIN_RESET);

//-----Move device BACKWARD till get far from FC1
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCA_6_GPIO_Port, DRV_FCA_6_Pin) == GPIO_PIN_SET);
	}
	if(AJUSTE_INICIAL>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL);
	}
	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
	if(AJUSTE_INICIAL_M5>=0) {
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *AJUSTE_INICIAL_M6);
	}else {
		BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *-AJUSTE_INICIAL_M6);
	}
	stopMotor();
	/* Get current position */
	pos = BSP_MotorControl_GetPosition(MOTOR_ID);
	/* Set the current position to be the Home position */
	BSP_MotorControl_SetHome(MOTOR_ID, pos);

	if(CALIB)
	{
	//-----Move device BACKWARD till found FC2 and mark the position
		BSP_MotorControl_Move(MOTOR_ID, BACKWARD, 7889 * 45/AJUSTE_REL_PASOS);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		do {
			BSP_MotorControl_Run(MOTOR_ID, BACKWARD);
			HAL_Delay(T_FC);
		} while (HAL_GPIO_ReadPin(DRV_FCB_6_GPIO_Port, DRV_FCB_6_Pin) == GPIO_PIN_RESET);

		stopMotor();
		/* Get current position */
		pos = BSP_MotorControl_GetPosition(MOTOR_ID);
		/* Set the current position to be the Home position */
		BSP_MotorControl_SetMark(MOTOR_ID, pos);
		//----- Go Home
		/* Request to go to Home */
		BSP_MotorControl_GoHome(MOTOR_ID);
		BSP_MotorControl_WaitWhileActive(MOTOR_ID);
		stopMotor();
	}
}

void stopMotor(void){
	/* Request soft stop */
	BSP_MotorControl_SoftStop(MOTOR_ID);
	/* Disable the power bridges */
	BSP_MotorControl_CmdDisable(MOTOR_ID);
	/* Wait for 0.5 second */
	HAL_Delay(T_STOP);
	/* Turn off power bridges when motor is stopped */
	BSP_MotorControl_SetStopMode(MOTOR_ID, HIZ_MODE);
}

void sensorsTest(void){
	int i;
	static VL53L1_RangingMeasurementData_t RangingData;
	int status;
	uint8_t buff[50];

	for (i=0;i<5;i++){
//			HAL_UART_Transmit(&huart5, &i, sizeof(i), 50);
		status = VL53L1_StartMeasurement(&stdistancia.VL53L1_DEV[i]);
		status = VL53L1_WaitMeasurementDataReady(&stdistancia.VL53L1_DEV[i]);
		if(!status)
		{
			status = VL53L1_GetRangingMeasurementData(&stdistancia.VL53L1_DEV[i], &RangingData);
			if(status==0){
//					HAL_UART_Transmit(&huart5, &i, sizeof(i), 50);
				sprintf( (char*)buff, "S%d, %d, %d, %.2f, %.2f\n\r",i , RangingData.RangeStatus, RangingData.RangeMilliMeter,
							   ( RangingData.SignalRateRtnMegaCps / 65536.0 ), RangingData.AmbientRateRtnMegaCps / 65336.0 );
				HAL_UART_Transmit( &huart5, buff, strlen( (char*)buff ), 0xFFFF );
			}
			status = VL53L1_ClearInterruptAndStartMeasurement(&stdistancia.VL53L1_DEV[i]);
		}
//			HAL_Delay(3000);
	}
	HAL_UART_Transmit(&huart5, (uint8_t*)"\n", strlen("\n"), 20);
//	BSP_MotorControl_Move(MOTOR_ID, BACKWARD, STEP_1MM *60);
//	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
//
//	BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *60);
////	BSP_MotorControl_Move(MOTOR_ID, FORWARD, STEP_1MM *3);
//	BSP_MotorControl_WaitWhileActive(MOTOR_ID);
//	/* Request soft stop */
//	BSP_MotorControl_SoftStop(MOTOR_ID);
//
//	/* Disable the power bridges */
//	BSP_MotorControl_CmdDisable(MOTOR_ID);
//
//	/* Wait for 0.5 second */
//	HAL_Delay(T_STOP);
//
//	/* Turn off power bridges when motor is stopped */
//	BSP_MotorControl_SetStopMode(MOTOR_ID, HIZ_MODE);
}


/**
 * @brief  This function is the User handler for the flag interrupt
 * @param  None
 * @retval None
 */
void MyFlagInterruptHandler(void) {
	//When EN pin is forced low by a failure, configure the GPIO as an ouput low
	BSP_MotorControl_CmdDisable(0);
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  error number of the error
 * @retval None
 */
void MyErrorHandler(uint16_t error) {
	/* Backup error number */
	gLastError = error;

	/* Infinite loop */
	while (1) {
	}
}

/**
 * @brief  This function is executed in case of button press and it changes the
 * current direction of the motor
 * @param  None
 * @retval None
 */
void ButtonHandler(void) {
	if (BSP_MotorControl_GetDirection(0) != BACKWARD) {
		BSP_MotorControl_SetDirection(0, BACKWARD);
	} else {
		BSP_MotorControl_SetDirection(0, FORWARD);
	}
	/* Let 200 ms before clearing the IT for key debouncing */
	HAL_Delay(200);
//	__HAL_GPIO_EXTI_CLEAR_IT(KEY_BUTTON_PIN);
//	HAL_NVIC_ClearPendingIRQ(KEY_BUTTON_EXTI_IRQn);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
