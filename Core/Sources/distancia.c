/*************************************************************************************************************
 *
 *                Proyecto Parrillas Versión 2.0
 *
 **************************************************************************************************************
 * FileName:        estructuras.h
 * Processor:       STM32L073
 * Compiler:        STM32CubeIDE
 * Company:         INNREF S.A.S.
 *
 *
 * Author(s)               		Date       		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Lucas Forero			 		27/03/2020  	Creación
 * Omar Parra					2020-2021		Edición
 ********************************************************************/

/*********************************************************************
IMPORTANT NOTE:
Funciones para el bloque Distancia.

*********************************************************************
*
* 						Archivos Cabecera
*
*********************************************************************/
#include "distancia.h"

/*********************************************************************
*
* 						Declaración de Variables
*
*********************************************************************/


/*********************************************************************
*
* 						Funciones
*
*********************************************************************/
//***************************************************************************************
/****************************************************************************************
Función:  				uint8_t BloqueDistancia(stDistancia *pstdistancia)
Entradas:         		pstdistancia: Apuntador a la estructura de datos de Distancia 
Salidas:          		0 -> Si la lectura fue exitosa
						1 -> Si no se detectó el sensor
						2 -> Si la lectura de distancia falló
Descripción:  		    Ejecuta el proceso principal del bloque Distancia
Notas y Cambios:  
****************************************************************************************/
uint8_t BloqueDistancia(stDistancia *pstdistancia)
{
	uint8_t sensorOK, configOK, col;
	uint16_t d1,d2,d3,d4,d5;
	int status;
	
	//Verificar si hay solicitud de lectura
	if(pstdistancia->bandDistancia == true)
	{
		col = pstdistancia->posSensor[pstdistancia->contParrilla];

		if(pstdistancia->bandInicio[pstdistancia->contParrilla] == 0){
			sensorOK = VL53L1_StartMeasurement( &(pstdistancia->VL53L1_DEV[pstdistancia->contParrilla]) );
			pstdistancia->bandInicio[pstdistancia->contParrilla] = 1;
		}else{
			sensorOK = 0;
		}

		if(sensorOK == 0)
		{

			status=VL53L1_WaitMeasurementDataReady( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			status= VL53L1_GetRangingMeasurementData(&pstdistancia->VL53L1_DEV[pstdistancia->contParrilla], &pstdistancia->RangingData);
			status = VL53L1_ClearInterruptAndStartMeasurement( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			d1 = pstdistancia->RangingData.RangeMilliMeter;

			status=VL53L1_WaitMeasurementDataReady( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			status= VL53L1_GetRangingMeasurementData(&pstdistancia->VL53L1_DEV[pstdistancia->contParrilla], &pstdistancia->RangingData);
			status = VL53L1_ClearInterruptAndStartMeasurement( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			d2 = pstdistancia->RangingData.RangeMilliMeter;

			status=VL53L1_WaitMeasurementDataReady( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			status= VL53L1_GetRangingMeasurementData(&pstdistancia->VL53L1_DEV[pstdistancia->contParrilla], &pstdistancia->RangingData);
			status = VL53L1_ClearInterruptAndStartMeasurement( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			d3 = pstdistancia->RangingData.RangeMilliMeter;

			status=VL53L1_WaitMeasurementDataReady( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			status= VL53L1_GetRangingMeasurementData(&pstdistancia->VL53L1_DEV[pstdistancia->contParrilla], &pstdistancia->RangingData);
			status = VL53L1_ClearInterruptAndStartMeasurement( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			d4 = pstdistancia->RangingData.RangeMilliMeter;

			status=VL53L1_WaitMeasurementDataReady( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			status= VL53L1_GetRangingMeasurementData(&pstdistancia->VL53L1_DEV[pstdistancia->contParrilla], &pstdistancia->RangingData);
			status = VL53L1_ClearInterruptAndStartMeasurement( &pstdistancia->VL53L1_DEV[pstdistancia->contParrilla] );
			d5 = pstdistancia->RangingData.RangeMilliMeter;


			
				if(status == VL53L1_ERROR_NONE)
				{
					pstdistancia->datosDistancia[pstdistancia->contParrilla][col] = d1;
					pstdistancia->datosDistancia2[pstdistancia->contParrilla][col][0] = d1;
					pstdistancia->datosDistancia2[pstdistancia->contParrilla][col][1] = d2;
					pstdistancia->datosDistancia2[pstdistancia->contParrilla][col][2] = d3;
					pstdistancia->datosDistancia2[pstdistancia->contParrilla][col][3] = d4;
					pstdistancia->datosDistancia2[pstdistancia->contParrilla][col][4] = d5;

					//Reiniciar bandera de solicitud de lectura
					pstdistancia->bandDistancia = false;
					pstdistancia->senStatus[pstdistancia->contParrilla][col] = 0;
					return (uint8_t)0;
				}
				else
				{
					pstdistancia->senStatus[pstdistancia->contParrilla][col] = 2;
					return (uint8_t)2;
				}
		}
		else
		{
			pstdistancia->senStatus[pstdistancia->contParrilla][col] = 1;
			return (uint8_t)1;
		}
	}
	else
	{
		return (uint8_t)4;
	}
}

/****************************************************************************************
Función:  				char Iniciar_Sensores(stDistancia *pstdistancia)
Entradas:         		pstdistancia: Apuntador a la estructura de datos de Distancia
Salidas:          		N/A
Descripción:  		    Esta función inicia y configura los sesores
Notas y Cambios:
****************************************************************************************/
int IniciarSensores(stDistancia *pstdistancia)
{
	int sensor;
	uint8_t newI2C = 0x52;
	uint16_t wordData;
	VL53L1_UserRoi_t roiConfig;
	roiConfig.TopLeftX = 7;
	roiConfig.TopLeftY = 10;
	roiConfig.BotRightX = 10;
	roiConfig.BotRightY = 7;
	int status;

	for(sensor=0; sensor<pstdistancia->SenHab; sensor++){
		pstdistancia->contParrilla = sensor;
		EnableSensors(pstdistancia);
		pstdistancia->VL53L1_DEV[sensor].comms_speed_khz = 400;
		pstdistancia->VL53L1_DEV[sensor].I2cHandle = &hi2c1;
		pstdistancia->VL53L1_DEV[sensor].comms_type = 1;
		pstdistancia->VL53L1_DEV[sensor].I2cDevAddr=0x52; /* default ToF sensor I2C address*/
		VL53L1_RdWord(&pstdistancia->VL53L1_DEV[sensor], 0x010F, &wordData);
//		printf("VL53L1X: %02X\n\r", wordData);
		newI2C = pstdistancia->VL53L1_DEV[sensor].I2cDevAddr + (sensor+1)*2;
		status = VL53L1_SetDeviceAddress(&pstdistancia->VL53L1_DEV[sensor], newI2C);
		pstdistancia->VL53L1_DEV[sensor].I2cDevAddr=newI2C;
		VL53L1_RdWord(&pstdistancia->VL53L1_DEV[sensor], 0x010F, &wordData);
//		printf("VL53L1X: %02X\n\r", wordData);
		/* Device Initialization and setting */
		status = VL53L1_WaitDeviceBooted(&pstdistancia->VL53L1_DEV[sensor]);
		status = VL53L1_DataInit(&pstdistancia->VL53L1_DEV[sensor]);
		status = VL53L1_StaticInit(&pstdistancia->VL53L1_DEV[sensor]);
		status = VL53L1_SetDistanceMode(&pstdistancia->VL53L1_DEV[sensor], VL53L1_DISTANCEMODE_SHORT);
		status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(&pstdistancia->VL53L1_DEV[sensor], 50000);
		status = VL53L1_SetInterMeasurementPeriodMilliSeconds(&pstdistancia->VL53L1_DEV[sensor], 55);
		status = VL53L1_SetUserROI(&pstdistancia->VL53L1_DEV[sensor], &roiConfig);
	}


	return 1;
}

//****************************************************************************************
/****************************************************************************************
Función:  				uint8_t EnableSensors(stDistancia *pstdistancia)
Entradas:         		pstdistancia: Apuntador a la estructura de datos de Distancia
Salidas:          		0
Descripción:  		    Habilita los sensores secuencialmente para su configuración
Notas y Cambios:
****************************************************************************************/
uint8_t EnableSensors(stDistancia *pstdistancia)
{
	switch(pstdistancia->contParrilla)
	{
	case 0:
		HAL_GPIO_WritePin(VL53_XSHUT_1_GPIO_Port, VL53_XSHUT_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_2_GPIO_Port, VL53_XSHUT_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_3_GPIO_Port, VL53_XSHUT_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_4_GPIO_Port, VL53_XSHUT_4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_5_GPIO_Port, VL53_XSHUT_5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_6_GPIO_Port, VL53_XSHUT_6_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(VL53_XSHUT_1_GPIO_Port, VL53_XSHUT_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_2_GPIO_Port, VL53_XSHUT_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_3_GPIO_Port, VL53_XSHUT_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_4_GPIO_Port, VL53_XSHUT_4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_5_GPIO_Port, VL53_XSHUT_5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_6_GPIO_Port, VL53_XSHUT_6_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(VL53_XSHUT_1_GPIO_Port, VL53_XSHUT_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_2_GPIO_Port, VL53_XSHUT_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_3_GPIO_Port, VL53_XSHUT_3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_4_GPIO_Port, VL53_XSHUT_4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_5_GPIO_Port, VL53_XSHUT_5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_6_GPIO_Port, VL53_XSHUT_6_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(VL53_XSHUT_1_GPIO_Port, VL53_XSHUT_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_2_GPIO_Port, VL53_XSHUT_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_3_GPIO_Port, VL53_XSHUT_3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_4_GPIO_Port, VL53_XSHUT_4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_5_GPIO_Port, VL53_XSHUT_5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_6_GPIO_Port, VL53_XSHUT_6_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(VL53_XSHUT_1_GPIO_Port, VL53_XSHUT_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_2_GPIO_Port, VL53_XSHUT_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_3_GPIO_Port, VL53_XSHUT_3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_4_GPIO_Port, VL53_XSHUT_4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_5_GPIO_Port, VL53_XSHUT_5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_6_GPIO_Port, VL53_XSHUT_6_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(VL53_XSHUT_1_GPIO_Port, VL53_XSHUT_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_2_GPIO_Port, VL53_XSHUT_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_3_GPIO_Port, VL53_XSHUT_3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_4_GPIO_Port, VL53_XSHUT_4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_5_GPIO_Port, VL53_XSHUT_5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_6_GPIO_Port, VL53_XSHUT_6_Pin, GPIO_PIN_SET);
		break;
	default:
		HAL_GPIO_WritePin(VL53_XSHUT_1_GPIO_Port, VL53_XSHUT_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VL53_XSHUT_2_GPIO_Port, VL53_XSHUT_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_3_GPIO_Port, VL53_XSHUT_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_4_GPIO_Port, VL53_XSHUT_4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_5_GPIO_Port, VL53_XSHUT_5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VL53_XSHUT_6_GPIO_Port, VL53_XSHUT_6_Pin, GPIO_PIN_RESET);
		break;
	}
	HAL_Delay(30);

	return (uint8_t)0;
}

//***************************************************************************************
/****************************************************************************************
Función:  				void Convertir4Cif(uint16_t numero, uint8_t *mil, uint8_t *centena,	uint8_t *decena, uint8_t *unidad)
Entradas:
Salidas:
Descripción:  		    Esta función convierte de uint16_t a decimal
Notas y Cambios:
****************************************************************************************/
void Convertir4Cif(uint16_t numero, uint8_t *mil, uint8_t *centena,	uint8_t *decena, uint8_t *unidad) {
	uint16_t temp = 0;

	*unidad = 0;
	*decena = 0;
	*centena = 0;
	*mil = 0;

	temp = numero;

	if (numero < 9999) {
		*mil = temp / 1000;
		temp = temp - *mil * 1000;
		*centena = temp / 100;
		temp = temp - *centena * 100;
		*decena = temp / 10;
		temp = temp - *decena * 10;
		*unidad = temp;
		*mil = *mil + 48;
		*centena = *centena + 48;
		*decena = *decena + 48;
		*unidad = *unidad + 48;
	}
	else {
		*mil = 255;
		*centena = 255;
		*decena = 255;
		*unidad = 255;
	}
}
