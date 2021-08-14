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
Funciones para inicialización de las estructuras de datos de los diferentes bloques.

*********************************************************************
*
* 						Archivos Cabecera
*
*********************************************************************/
#include "estructuras.h"

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
Función:  						char Iniciar_EstrucCaptura(stCaptura *pstcaptura)
Entradas:         				pstcaptura: Apuntador a la estructura de datos de Captura
Salidas:          				N/A
Descripción:  		    		Esta función inicia la Estructura de Datos del Bloque Captura
Notas y Cambios:  
****************************************************************************************/
char Iniciar_EstrucCaptura(stCaptura *pstcaptura)
{
	int i,j;

	pstcaptura->CAP_State = CAP_ESPERAR;
	pstcaptura->filaActual = 0;
	pstcaptura->Distancia = 34;  // Profundidad dada en cm
	
	for(i = 0; i < MAX_PARR; i++)
	{
		for(j = 0; j < MAX_FILAS; j++)
		{
	//		pstcaptura->anchos[i] = 70; // 7cm
			pstcaptura->ancho[i][j] = 61; // 6.1cm
			pstcaptura->largo[i][j] = 61; // 6.1cm
			pstcaptura->cantidades[i][j] = 255;
		}
	}
	
	for(i = 0; i < TX_BUFFER_SIZE; i++)
	{
		pstcaptura->bufferTrama[i] = 0x00;
	}
	
	return 1;
}

//***************************************************************************************
/****************************************************************************************
Función:  				char Iniciar_EstrucComCEIT(stComCEIT *pstcomceit)
Entradas:         		pstcomceit: Apuntador a la estructura de datos de COM_CEIT
Salidas:          		N/A
Descripción:  		    Esta función inicia la Estructura de Datos del Bloque COM_CEIT
Notas y Cambios:  
****************************************************************************************/
char Iniciar_EstrucComCEIT(stComCEIT *pstcomceit)
{
	int i;
	
	pstcomceit->SM_State = SM_STATE_START_RX;
	pstcomceit->enviarDatos = false;
	pstcomceit->datosListos = false;
	pstcomceit->envioOK = true;
	pstcomceit->xRxDoneFlag = false;
	pstcomceit->xTxDoneFlag = false;
	pstcomceit->TxLength = 0;
	pstcomceit->RxLength = 0;
	
	for(i = 0; i < TX_BUFFER_SIZE; i++)
	{
		pstcomceit->Tx_Buffer[i] = 0x00;
	}
	
	for(i = 0; i < RX_BUFFER_SIZE; i++)
	{
		pstcomceit->Rx_Buffer[i] = 0x00;
	}
	
	for(i = 0; i < RX_DATA_SIZE; i++)
	{
		pstcomceit->Rx_Data[i] = 0x00;
	}

	return 1;
}

//***************************************************************************************
/****************************************************************************************
Función:  				char Iniciar_EstrucDistancia(stDistancia *pstdistancia)
Entradas:         		pstdistancia: Apuntador a la estructura de datos de Distancia
Salidas:          		N/A
Descripción:  		    Esta función inicia la Estructura de Datos del Bloque Distancia
Notas y Cambios:  
****************************************************************************************/
char Iniciar_EstrucDistancia(stDistancia *pstdistancia)
{
	int i,j,k;
	
	pstdistancia->bandDistancia = false;							

	pstdistancia->contParrilla = 0;


	for(i = 0; i < MAX_PARR; i++)
	{
		pstdistancia->cantFilas[i] = CANT_FILAS;
		pstdistancia->bandInicio[i] = 0;
	}
	k=0;
	for(i = 0; i < PH; i++)
	{
		pstdistancia->posSensor[i] = 0;
		for(j = 0; j < CANT_FILAS; j++)
		{
			pstdistancia->datosDistancia[i][j] = 0;
			pstdistancia->sensor[k] = i;
			pstdistancia->senStatus[i][j] = 0;
			k++;
		}
	}
	return 1;
}

//***************************************************************************************
/****************************************************************************************
Función:  				char Iniciar_EstrucMotor(stMotor *pstmotor)
Entradas:         		pstmotor: Apuntador a la estructura de datos de Motor
Salidas:          		N/A
Descripción:  		    Esta función inicia la Estructura de Datos del Bloque Motor
Notas y Cambios:  
****************************************************************************************/
char Iniciar_EstrucMotor(stMotor *pstmotor)
{
	int i,j,k;

	pstmotor->bandMotor = false;
	pstmotor->posInicial = 0;
	pstmotor->posMotor = 0;
	for(i = 0; i < MAX_PARR; i++)
	{
		pstmotor->cantFilas[i] = CANT_FILAS;
	}
	pstmotor->ParrHab = PH;
//	pstmotor->MaxPosMotor = pstmotor->ParrHab*CANT_FILAS;

	for(i = 0; i < pstmotor->ParrHab; i++)
	{
		pstmotor->distFilas[i][0] = -POS_LINE_1;
		pstmotor->distFilas[i][1] = -POS_LINE_2;
		pstmotor->distFilas[i][2] = -POS_LINE_3;
		pstmotor->distFilas[i][3] = -POS_LINE_4;
		pstmotor->distFilas[i][4] = -POS_LINE_5;
		pstmotor->distFilas[i][5] = -POS_LINE_6;
		pstmotor->distFilas[i][6] = -POS_LINE_7;
		pstmotor->distFilas[i][7] = -POS_LINE_8;

	}
	k=0;
	for(i = 0; i < pstmotor->ParrHab; i++)
	{
		for(j=0; j<CANT_FILAS; j++)
		{
			pstmotor->recorrido[k] = pstmotor->distFilas[i][j];
			k++;
		}
	}
	pstmotor->MaxPosMotor = k;

//	pstmotor->initDeviceParameters.acceleration = 480;             		//Acceleration rate in pulse/s2 (must be greater than 0)
//	pstmotor->initDeviceParameters.deceleration = 480;             		//Deceleration rate in pulse/s2 (must be greater than 0)
//	pstmotor->initDeviceParameters.maxSpeed = 1600;            				//Running speed in pulse/s (8 pulse/s < Maximum speed <= 10 000 pulse/s )
//	pstmotor->initDeviceParameters.minSpeed = 400;            	 			//Minimum speed in pulse/s (8 pulse/s <= Minimum speed < 10 000 pulse/s)
//	pstmotor->initDeviceParameters.accelTorque = 20;              		//Acceleration current torque in % (from 0 to 100)
//	pstmotor->initDeviceParameters.decelTorque = 15;              		//Deceleration current torque in % (from 0 to 100)
//	pstmotor->initDeviceParameters.runTorque = 10;              			//Running current torque in % (from 0 to 100)
//	pstmotor->initDeviceParameters.holdTorque = 25;              			//Holding current torque in % (from 0 to 100)
//	pstmotor->initDeviceParameters.torqueBoostEnable = true;          //Torque boost speed enable
//	pstmotor->initDeviceParameters.torqueBoostSpeedThreshold = 200;		//Torque boost speed threshold in fullstep/s
//	pstmotor->initDeviceParameters.stepMode = STEP_MODE_1_32;  				//Step mode via enum motorStepMode_t
//	pstmotor->initDeviceParameters.stopMode = HOLD_MODE;
//	pstmotor->initDeviceParameters.vrefPwmFreq = 100000;           		//REF frequency (Hz)
       				//Automatic HIZ STOP
	
	return 1;
}

