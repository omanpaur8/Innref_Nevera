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
Funciones para el bloque Captura.

*********************************************************************
*
* 						Archivos Cabecera
*
*********************************************************************/
#include "captura.h"
#include "usart.h"

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
Función:  				void BloqueCaptura(stCaptura *pstcaptura, stComCEIT *pstcomceit, stMotor *pstmotor, stDistancia *pstdistancia, stFuerza *pstfuerza)
Entradas:         		pstcaptura: Apuntador a la estructura de datos de Captura
						pstcomceit: Apuntador a la estructura de datos de COM_CEIT
						pstmotor: Apuntador a la estructura de datos de Motor
						pstdistancia: Apuntador a la estructura de datos de Distancia
						pstfuerza: Apuntador a la estructura de datos de Fuerza
Salidas:          		N/A
Descripción:  		    Ejecuta el proceso principal del bloque Captura
****************************************************************************************/
void BloqueCaptura(stCaptura *pstcaptura, stComCEIT *pstcomceit, stMotor *pstmotor, stDistancia *pstdistancia)
{
	int i,j;
	
	//Máquina de Estados del bloque
	switch(pstcaptura->CAP_State)
  {
		case CAP_ESPERAR:  
			//Actualizar estado actual			
			if(pstcomceit->enviarDatos == false || pstcomceit->envioOK == false)
			{
				pstcaptura->CAP_State = CAP_ESPERAR;
			}
			else if(pstcomceit->Rx_Buffer[CMD] == GET_DATA)
			{
				pstcomceit->datosListos = false;
				pstmotor->posMotor = 0;
				pstmotor->bandMotor = true;
				pstcomceit->envioOK = false;
				pstcaptura->CAP_State = CAP_MOVER_MOTOR;
			}
			else if(pstcomceit->Rx_Buffer[CMD] == CONFIG)
			{
				pstcomceit->datosListos = false;
				pstcomceit->envioOK = false;
				pstcaptura->CAP_State = CAP_CONFIGURAR;
			}
    break;
    
		case CAP_MOVER_MOTOR:
			
			//Actualizar estado actual
			if(pstmotor->bandMotor == 0)
			{
				pstdistancia->bandDistancia = true;
				pstcaptura->CAP_State = CAP_LEER_DISTANCIA;
			}
			else
			{
				pstcaptura->CAP_State = CAP_MOVER_MOTOR;
			}
    break;
    
		case CAP_LEER_DISTANCIA:  
			
			//Actualizar estado actual
			if(pstdistancia->bandDistancia == true)
			{
				pstcaptura->CAP_State = CAP_LEER_DISTANCIA;
			}
			else if(pstmotor->posMotor < pstmotor->MaxPosMotor)
			{
				//Calcular cantidad de producto
				pstcaptura->filaActual = pstdistancia->posSensor[pstdistancia->contParrilla];
				if(pstdistancia->senStatus[pstdistancia->contParrilla][pstcaptura->filaActual] == 0){
					pstcaptura->cantidades[pstdistancia->contParrilla][pstcaptura->filaActual] = ConvertirDistancia(pstcaptura, pstdistancia);
					pstdistancia->posSensor[pstdistancia->contParrilla]++;
				}else{
					pstcaptura->cantidades[pstdistancia->contParrilla][pstcaptura->filaActual] = 250+pstdistancia->senStatus[pstdistancia->contParrilla][pstcaptura->filaActual];
					pstdistancia->posSensor[pstdistancia->contParrilla]++;
				}
//				pstcaptura->filaActual++;
//				pstmotor->posMotor++;
				pstmotor->bandMotor = true;
				pstcaptura->CAP_State = CAP_MOVER_MOTOR;
			}
			else if(pstmotor->posMotor >= pstmotor->MaxPosMotor)
			{
				//Estimar cantidad de producto
				pstcaptura->filaActual = pstdistancia->posSensor[pstdistancia->contParrilla];
				if(pstdistancia->senStatus[pstdistancia->contParrilla][pstcaptura->filaActual] == 0){
					pstcaptura->cantidades[pstdistancia->contParrilla][pstcaptura->filaActual] = ConvertirDistancia(pstcaptura, pstdistancia);
				}else{
					pstcaptura->cantidades[pstdistancia->contParrilla][pstcaptura->filaActual] = 250+pstdistancia->senStatus[pstdistancia->contParrilla][pstcaptura->filaActual];
				}
				pstcaptura->filaActual = 0;
				pstdistancia->contDistancia = 0;
				for(i=0; i<MAX_PARR; i++)
				{
					pstdistancia->posSensor[i] = 0;
				}
				pstmotor->bandMotor = true;
				pstcaptura->CAP_State = CAP_ARMAR_TRAMA;
			}
    break;  
    
		case CAP_CONFIGURAR:

			/*Actualizar parámetros de funcionamiento*/
			ConfigParrillas(pstcaptura, pstcomceit, pstmotor, pstdistancia);
			/*Ordenar vectores*/
			Ordenar(pstmotor,pstdistancia);

			pstcaptura->CAP_State = CAP_ARMAR_TRAMA;
    break;
    
		case CAP_ARMAR_TRAMA:
			
			if(pstcomceit->Rx_Buffer[CMD] == GET_DATA)
			{
				//Incluir cantidades de productos
				for(i = 0; i < MAX_PARR; i++)
				{
					for(j = 0; j < MAX_FILAS; j++)
					{
						pstcomceit->Tx_Buffer[j+i*10] = pstcaptura->cantidades[i][j];
					}
				}
				
				for(i = 0; i < MAX_PARR; i++)
				{
					for(j = 0; j < MAX_FILAS; j++)
					{
						pstcaptura->cantidades[i][j] = 255;
					}
				}

//				//Copiar en el vector de transmisión
//				for(i = 0; i < (TX_BUFFER_SIZE - 5); i++)
//				{
//					pstcomceit->Tx_Buffer[i] = pstcaptura->bufferTrama[i];
//				}
				pstcomceit->TxLength = MAX_PARR*MAX_FILAS;
			}
			else if(pstcomceit->Rx_Buffer[CMD] == CONFIG)
			{
//				pstcomceit->Tx_Buffer[0] = 0xAA;
//				pstcomceit->TxLength = 1;
			}
			
			//Actualizar bandera de envío
 			pstcomceit->datosListos = true;
			pstcaptura->CAP_State = CAP_ESPERAR;

		break;
  }
}

/****************************************************************************************
Función:  				void ConfigParrillas(stCaptura *pstcaptura, stComCEIT *pstcomceit, stMotor *pstmotor, stDistancia *pstdistancia, stFuerza *pstfuerza)
Entradas:         		pstcaptura: Apuntador a la estructura de datos de Captura
						pstcomceit: Apuntador a la estructura de datos de COM_CEIT
						pstmotor: Apuntador a la estructura de datos de Motor
						pstdistancia: Apuntador a la estructura de datos de Distancia
						pstfuerza: Apuntador a la estructura de datos de Fuerza
Salidas:          		N/A
Descripción:  		    Realiza la configuración de las parrillas
****************************************************************************************/
void ConfigParrillas(stCaptura *pstcaptura, stComCEIT *pstcomceit, stMotor *pstmotor, stDistancia *pstdistancia)
{
	int i,j,k;
	pstmotor->ParrHab = pstcomceit->Rx_Data[0];
	pstdistancia->SenHab = pstcomceit->Rx_Data[0];
	pstcaptura->Distancia = pstcomceit->Rx_Data[1];

	/*Actualizar largo y ancho*/
	for(i=0; i<pstmotor->ParrHab; i++)
	{
		j=0;
		while(pstcomceit->Rx_Data[2+i*20+2*j+1] != 255)
		{
			if(pstcomceit->Rx_Data[2+i*20+2*j+1] !=0)
			{
				pstcaptura->ancho[i][j] = pstcomceit->Rx_Data[2+i*20+2*j];
				pstcaptura->largo[i][j] = pstcomceit->Rx_Data[2+i*20+2*j+1];
			}
			else
			{
				pstcaptura->ancho[i][j] = pstcomceit->Rx_Data[2+i*20+2*j];
				pstcaptura->largo[i][j] = pstcaptura->ancho[i][j];
			}
			j++;
		}
		pstdistancia->cantFilas[i] = j;
	}

	/*Actualizar distancias a recorrer y crear vectores de recorrido y sensor*/
	k=0;
	for(i=0; i<pstmotor->ParrHab; i++)
	{
		pstmotor->distFilas[i][0] = 0;
		pstmotor->recorrido[k] = pstmotor->distFilas[i][0];
		pstdistancia->sensor[k] = i;
		k++;
		for(j=1; j<pstdistancia->cantFilas[i]; j++)
		{
			pstmotor->distFilas[i][j] = ((pstcaptura->ancho[i][j-1]+pstcaptura->ancho[i][j])/2+SEPARADOR)*STEP_1MM+pstmotor->distFilas[i][j-1];// Fix signo
			pstmotor->recorrido[k] = pstmotor->distFilas[i][j];
			pstdistancia->sensor[k] = i;
			k++;
		}
	}
	pstmotor->MaxPosMotor = k;
}

/****************************************************************************************
Función:  				void Ordenar(stMotor *pstmotor, stDistancia *pstdistancia)
Entradas:         		pstmotor: Apuntador a la estructura de datos de Motor
						pstdistancia: Apuntador a la estructura de datos de Distancia
Salidas:          		N/A
Descripción:  		    Planeación de las paradas que deben realizar los motores
****************************************************************************************/
void Ordenar(stMotor *pstmotor, stDistancia *pstdistancia)
{
	int i,j,band=1;
	while(band)
	{
		band = 0;
		for(i=1; i<pstmotor->MaxPosMotor; i++)
		{
			if(pstmotor->recorrido[i]<pstmotor->recorrido[i-1])
			{
				j = pstmotor->recorrido[i-1];
				pstmotor->recorrido[i-1] = pstmotor->recorrido[i];
				pstmotor->recorrido[i] = j;
				j = pstdistancia->sensor[i-1];
				pstdistancia->sensor[i-1] = pstdistancia->sensor[i];
				pstdistancia->sensor[i] = j;
				band = 1;
			}
		}
	}
	for(i=0; i<pstmotor->MaxPosMotor; i++)
	{
		pstmotor->recorrido[i] = -pstmotor->recorrido[i];
	}
}

//***************************************************************************************
/****************************************************************************************
Función:  				uint8_t ConvertirDistancia(stCaptura *pstcaptura, stDistancia *pstdistancia)
Entradas:         		pstcaptura: Apuntador a la estructura de datos de Captura
						pstdistancia: Apuntador a la estructura de datos de Distancia
Salidas:          		Retorna la cantidad de productos de acuerdo a la distancia
Descripción:  		    Convierte el valor de distancia a cantidad de productos
****************************************************************************************/
uint8_t ConvertirDistancia(stCaptura *pstcaptura, stDistancia *pstdistancia)
{
	uint8_t resultado = 0, sensor;
	uint16_t dist, largo;
	float e1, e2, e3, e4, e5;

	sensor = pstdistancia->contParrilla;
	dist = pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual];
	largo = pstcaptura->largo[pstdistancia->contParrilla][pstcaptura->filaActual];
	e1=pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual]*0.0309-36.803;
	e2=pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual]*0.0583-42.687;
	e3=pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual]*-0.0067-23.071;
	e4=pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual]*0.0192-24.945;
	e5=pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual]*0.0177-26.045;
	
	//NOTA: Calcular distancias de acuerdo a la parrilla
//	resultado = (390-pstdistancia->datosDistancia[pstcaptura->filaActual]+70) / pstcaptura->anchos[pstcaptura->filaActual];

//	if(dist > 460){
//		resultado = 0;
//	}else{
//		if(dist>351 && dist<=460){
//			resultado = 1;
//		}else{
//			if(dist>290 && dist<=351){
//				resultado = 2;
//			}else{
//				if(dist>230 && dist<=280){
//					resultado = 3;
//				}else{
//					if(dist>160 && dist<=210){
//						resultado = 4;
//					}else{
//						resultado = 5;
//					}
//				}
//			}
//		}
//
//	}



//	if(pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual] > 430){//------------Fix distancia empujador
//		resultado = 0;
//	}else{
//		switch(sensor){
//		case 0:
//			if(dist > 460){
//				resultado = 0;
//			}else{
//				if(dist>351 && dist<=460){
//					resultado = 1;
//				}else{
//					if(dist>290 && dist<=351){
//						resultado = 2;
//					}else{
//						if(dist>230 && dist<=280){
//							resultado = 3;
//						}else{
//							if(dist>160 && dist<=210){
//								resultado = 4;
//							}else{
//								resultado = 5;
//							}
//						}
//					}
//				}
//
//			}
//			break;
//		case 1:
//				if(dist > 460){
//					resultado = 0;
//				}else{
//					if(dist>351 && dist<=460){
//						resultado = 1;
//					}else{
//						if(dist>290 && dist<=351){
//							resultado = 2;
//						}else{
//							if(dist>220 && dist<=280){
//								resultado = 3;
//							}else{
//								if(dist>160 && dist<=210){
//									resultado = 4;
//								}else{
//									resultado = 5;
//								}
//							}
//						}
//					}
//
//				}
//			break;
//		case 2:
//				if(dist > 460){
//					resultado = 0;
//				}else{
//					if(dist>351 && dist<=460){
//						resultado = 1;
//					}else{
//						if(dist>290 && dist<=351){
//							resultado = 2;
//						}else{
//							if(dist>230 && dist<=280){
//								resultado = 3;
//							}else{
//								if(dist>160 && dist<=210){
//									resultado = 4;
//								}else{
//									resultado = 5;
//								}
//							}
//						}
//					}
//
//				}
//			break;
//		case 3:
//				if(dist > 460){
//					resultado = 0;
//				}else{
//					if(dist>351 && dist<=460){
//						resultado = 1;
//					}else{
//						if(dist>290 && dist<=351){
//							resultado = 2;
//						}else{
//							if(dist>230 && dist<=280){
//								resultado = 3;
//							}else{
//								if(dist>150 && dist<=210){
//									resultado = 4;
//								}else{
//									resultado = 5;
//								}
//							}
//						}
//					}
//
//				}
//			break;
//		case 4:
//			if(dist > 460){
//				resultado = 0;
//			}else{
//				if(dist>351 && dist<=460){
//					resultado = 1;
//				}else{
//					if(dist>290 && dist<=351){
//						resultado = 2;
//					}else{
//						if(dist>230 && dist<=280){
//							resultado = 3;
//						}else{
//							if(dist>160 && dist<=210){
//								resultado = 4;
//							}else{
//								resultado = 5;
//							}
//						}
//					}
//				}
//
//			}
//			break;
//		default:
//			resultado = (pstcaptura->Distancia*10-(dist+CORR_DIST+e1)+largo) / largo;
//			break;
//		}
//	}



	if(pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual] > 400){
		resultado = 0;
	}else{
		switch(sensor){
		case 0:
			resultado = (pstcaptura->Distancia*10-(dist+CORR_DIST-e1)+largo) / largo;
			break;
		case 1:
			resultado = (pstcaptura->Distancia*10-(dist+CORR_DIST-e2)+largo) / largo;
			break;
		case 2:
			resultado = (pstcaptura->Distancia*10-(dist+CORR_DIST-e3)+largo) / largo;
			break;
		case 3:
			resultado = (pstcaptura->Distancia*10-(dist+CORR_DIST-e4)+largo) / largo;
			break;
		case 4:
			resultado = (pstcaptura->Distancia*10-(dist+CORR_DIST-e5)+largo) / largo;
			break;
		default:
			resultado = (pstcaptura->Distancia*10-(dist+CORR_DIST-e1)+largo) / largo;
			break;
		}
	}

//	resultado = (pstcaptura->Distancia*10-pstdistancia->datosDistancia[pstdistancia->contParrilla][pstcaptura->filaActual]+pstcaptura->largo[pstdistancia->contParrilla][pstcaptura->filaActual]) / pstcaptura->largo[pstdistancia->contParrilla][pstcaptura->filaActual];

	return resultado;
}
