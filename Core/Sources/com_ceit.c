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
Funciones para el bloque COM_CEIT.

*********************************************************************
*
* 						Archivos Cabecera
*
*********************************************************************/
#include "com_ceit.h"
#include "usart.h"


/*********************************************************************
*
* 						Declaración de Variables
*
*********************************************************************/
uint8_t RX_Frame[RX_BUFFER_SIZE];
uint8_t TX_Frame[TX_BUFFER_SIZE+1];

/*********************************************************************
*
* 						Funciones
*
*********************************************************************/
//***************************************************************************************
/****************************************************************************************
Función:  				void BloqueCOM_CEIT(stComCEIT *pstcomceit)
Entradas:         		pstcomceit: Apuntador a la estructura de datos de COM_CEIT 
Salidas:          		N/A
Descripción:  		    Ejecuta la Máquina de Estados del bloque COM_CEIT
Notas y Cambios:  
****************************************************************************************/
void BloqueCOM_CEIT(stComCEIT *pstcomceit)
{
	int i;
  
  switch(pstcomceit->SM_State)
  {
		case SM_STATE_START_RX:      
      /* wait for data received or timeout period occured */
			pstcomceit->SM_State = SM_STATE_WAIT_FOR_RX_DONE;
		break;
    
		case SM_STATE_WAIT_FOR_RX_DONE:
			if((pstcomceit->xRxDoneFlag != RESET))
			{
//				pstcomceit->xRxDoneFlag = RESET;
				pstcomceit->SM_State = SM_STATE_DATA_RECEIVED;
			}
			else
			{
				pstcomceit->SM_State = SM_STATE_START_RX;
			}
		break;
    
		case SM_STATE_DATA_RECEIVED:  

			if((pstcomceit->Rx_Buffer[CMD] == GET_DATA) || (pstcomceit->Rx_Buffer[CMD] == CONFIG))
			{
				pstcomceit->enviarDatos = true;
				pstcomceit->SM_State = SM_STATE_WAIT_FOR_TX_DONE;
			}
			else
			{
				pstcomceit->enviarDatos = false;
				pstcomceit->envioOK = true;
				pstcomceit->xRxDoneFlag = RESET;
				pstcomceit->SM_State = SM_STATE_START_RX;
			}
		break;

		case SM_STATE_WAIT_FOR_TX_DONE:
			
			if((pstcomceit->enviarDatos == true) && (pstcomceit->datosListos == true))
			{
				pstcomceit->SM_State = SM_STATE_SEND_DATA;
			}
			else if((pstcomceit->xTxDoneFlag == RESET) || (pstcomceit->datosListos == false))
			{
				pstcomceit->SM_State = SM_STATE_WAIT_FOR_TX_DONE;
			}
			else if(pstcomceit->xTxDoneFlag == SET)
			{
				pstcomceit->xTxDoneFlag = RESET;
				pstcomceit->envioOK = true;
				pstcomceit->xRxDoneFlag = RESET;
				pstcomceit->SM_State = SM_STATE_START_RX;
			}
		break;
		
		case SM_STATE_SEND_DATA:

			if(pstcomceit->Rx_Buffer[CMD] == GET_DATA)
			{
				TX_Frame[CMD_LENGTH] = 0x01;
				TX_Frame[CMD_TAG] = pstcomceit->Rx_Buffer[CMD_TAG];
				TX_Frame[CMD_TYPE] = 0x11;
				TX_Frame[CMD] = DATA;			
				TX_Frame[DATA_LENGTH] = pstcomceit->TxLength;
				for (int i=5; i<pstcomceit->TxLength+5; i++)
				{
					TX_Frame[i] = pstcomceit->Tx_Buffer[i-5];
				}
				TX_Frame[TX_BUFFER_SIZE] = 0xFA;
				if (HAL_UART_Transmit(&huart5, TX_Frame, TX_BUFFER_SIZE+1, HAL_MAX_DELAY) != HAL_OK)
				{
					pstcomceit->xTxDoneFlag=RESET;
				}
				else
				{
					HAL_UART_Transmit(&huart2, TX_Frame, TX_BUFFER_SIZE+1, HAL_MAX_DELAY);
					pstcomceit->xTxDoneFlag=SET;
					pstcomceit->enviarDatos = false;
				}
			}
			else
			{
				pstcomceit->xTxDoneFlag=SET;
				pstcomceit->enviarDatos = false;
			}
			pstcomceit->SM_State = SM_STATE_WAIT_FOR_TX_DONE;
		break;
  }
}


//***************************************************************************************
