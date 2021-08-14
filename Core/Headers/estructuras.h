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
Archivo cabecera para manejo de las estructuras de datos de los diferentes bloques.

*********************************************************************/
#ifndef __ESTRUCTURAS_H
#define __ESTRUCTURAS_H
/*********************************************************************
*
* 						Archivos Cabecera
*
*********************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "stm32l0xx_hal.h"
#include "vl53l1_api.h"
#include "i2c.h"
#include "stspin220.h"

/*********************************************************************
*
* 						Macro definiciones
*
*********************************************************************/
//********************************************************************
//Macros para la estructura del Bloque Captura
//********************************************************************



//********************************************************************
//Macros para la estructura del Bloque Distancia
//********************************************************************
#define MAX_FILAS			10							//Número máximo de filas que puede tener una parrilla
#define MAX_PARR			10							//Número máximo de parrillas
#define PH					5							//Número de parrillas habilitadas por defecto
#define CORR_DIST			-27							//Valor que se suma a la medición de distancia

//********************************************************************
//Macros para la estructura del Bloque COM_CEIT
//********************************************************************
#define TX_BUFFER_SIZE   			MAX_PARR*10+5//65				//Tamaño máximo del buffer de Transmisión Serial
#define RX_BUFFER_SIZE   			6								//Tamaño de la cabecera de Recepción Serial
#define RX_DATA_SIZE     			MAX_PARR*MAX_FILAS*2+3 //103	//Tamaño máximo del buffer de Recepción Serial

#define GET_DATA					0x60							//Comando usado por CEIT para pedir inventario
#define CONFIG						0x61							//Comando usado por CEIT para configurar parrillas
#define	DATA						0x70							//Comando usado por PARRILLAS para enviar inventario

#define	CONFIRM						0x71
#define ACK_OK                      0x01
#define CMD_LENGTH					0x00
#define CMD_TAG						0x01
#define CMD_TYPE					0x02
#define CMD							0x03
#define DATA_LENGTH					0x04

//********************************************************************
//Macros para la estructura del Bloque Motor
//********************************************************************

#define MOTOR_ID				0								//Número de identificación del motor
//#define STEP_ANGLE            			(18) 				//ángulo de cada paso [decigrados]
#define STEP_ANGLE            	(4) 							//ángulo de cada paso [decigrados]
#define FULL_STEPS_PER_TURN   	(3600 / (STEP_ANGLE))			//Pasos por cada vuelta
#define AJUSTE_REL_PASOS		1								//Permite cambiar la relación de pasos (1 -> 1a32, 2 -> 1a16, 4 -> 1a8, 8 -> 1a4)
#define AJUSTE_INICIAL			-7								//Ajuste en mm de la posición inicial de los motores
#define AJUSTE_INICIAL_M1		0								//Ajuste en mm de la posición inicial motor 1
#define AJUSTE_INICIAL_M2		0								//Ajuste en mm de la posición inicial motor 2
#define AJUSTE_INICIAL_M3		0								//Ajuste en mm de la posición inicial motor 3
#define AJUSTE_INICIAL_M4		0								//Ajuste en mm de la posición inicial motor 4
#define AJUSTE_INICIAL_M5		-8								//Ajuste en mm de la posición inicial motor 5
#define AJUSTE_INICIAL_M6		0								//Ajuste en mm de la posición inicial motor 6
#define SEPARADOR				7								//Ancho en mm del separador
#define CALIB					0								//0 si se calibran los motores respecto a home, 1 se tiene en cuenta el otro FC
#define T_STOP					500								//Tiempo usado para deshabilitar bridges
#define T_FC					200								//Tiempo para buscar FC
#define STEP_1MM				797//790						//Número de pasos para un 1mm de avance
#define STEP_1CM				7970//7990						//Número de pasos para un 1cm de avance
#define POS_LINE_1			(STEP_1MM * 0)						//Posición por Defecto Línea 1 (Igual al Home)
#define POS_LINE_2			(STEP_1MM * (-65/AJUSTE_REL_PASOS))			//Posición por Defecto Línea 2 (70mm del Home)
#define POS_LINE_3			(STEP_1MM * (-130/AJUSTE_REL_PASOS))			//Posición por Defecto Línea 3 (140mm del Home)
#define POS_LINE_4			(STEP_1MM * (-195/AJUSTE_REL_PASOS))			//Posición por Defecto Línea 4 (210mm del Home)
#define POS_LINE_5			(STEP_1MM * (-260/AJUSTE_REL_PASOS))			//Posición por Defecto Línea 5 (280mm del Home)
#define POS_LINE_6			(STEP_1MM * (-325/AJUSTE_REL_PASOS))			//Posición por Defecto Línea 6 (345mm del Home)
#define POS_LINE_7			(STEP_1MM * (-390))					//Posición por Defecto Línea 7 (410mm del Home)
#define POS_LINE_8			(STEP_1MM * (-455))					//Posición por Defecto Línea 8 (460mm del Home - Igual al Mark)
#define CANT_FILAS			8									//Cantidad de filas habilitadas por defecto en cada parrilla


/*********************************************************************
*
* 						Tipos de Datos
*
*********************************************************************/
//********************************************************************
//Estructura de datos para el Bloque Captura
//********************************************************************
typedef enum 
{
   CAP_ESPERAR = 0,
   CAP_MOVER_MOTOR,
   CAP_LEER_DISTANCIA,
   CAP_CONFIGURAR,
   CAP_ARMAR_TRAMA,
}CAP_State_t;

typedef struct stCaptura stCaptura;
struct stCaptura
{			
	CAP_State_t CAP_State;									//Estado actual de la máquina de estados
	uint8_t filaActual;										//Variable que guarda el valor de la fila actual en la conversión
	uint8_t Distancia;										//Variable que guarda el la distancia del sensor a la posición final del empujador en cm
	
	uint8_t ancho[MAX_PARR][MAX_FILAS];						//Vector para almacenar el ancho (en mm) de los productos de cada fila
	uint8_t largo[MAX_PARR][MAX_FILAS];						//Vector para almacenar el largo o profundidad (en mm) de los productos de cada fila
	uint8_t cantidades[MAX_PARR][MAX_FILAS];				//Vector para almacenar la cantidad de productos de cada fila
	uint8_t bufferTrama[TX_BUFFER_SIZE - 5];				//Buffer para armado de trama
};

//********************************************************************
//Estructura de datos para el Bloque COM_CEIT
//********************************************************************
typedef enum 
{
   SM_STATE_START_RX = 0,
   SM_STATE_WAIT_FOR_RX_DONE,
   SM_STATE_DATA_RECEIVED,
   SM_STATE_SEND_DATA,
   SM_STATE_WAIT_FOR_TX_DONE,
}SM_State_t;

typedef struct stComCEIT stComCEIT;
struct stComCEIT
{			
	SM_State_t SM_State;				//Estado actual de la máquina de estados
	bool enviarDatos;					//Bandera que indica que se deben enviar datos de respuesta, 1 en SM_STATE_DATA_RECEIVED (Ceit)
	bool datosListos;					//Bandera que indica que la trama de respuesta está lista para enviar, 1 en CAP_ARMAR_TRAMA
	bool envioOK;						//Bandera que indica que los datos enviados fueron confirmados, 1 en SM_STATE_DATA_RECEIVED o SM_STATE_WAIT_FOR_TX_DONE
	bool xRxDoneFlag;					//Bandera que si se recibieron datos, 1 cuando llega dato
	bool xTxDoneFlag;					//Bandera que indica si se transmitieron datos, 1 en SM_STATE_SEND_DATA
	uint8_t TxLength;					//Cantidad de datos para transmitir por Serial
	uint8_t RxLength;					//Cantidad de datos para recibir por Serial
	uint8_t Tx_Buffer[TX_BUFFER_SIZE];	//Buffer de transmisión por Serial
	uint8_t Rx_Buffer[RX_BUFFER_SIZE];	//Buffer de recepción de cabecera
	uint8_t Rx_Data[RX_DATA_SIZE];		//Buffer de recepción de configuración
};

//********************************************************************
//Estructura de datos para el Bloque Distancia
//********************************************************************


typedef struct stDistancia stDistancia;
struct stDistancia
{			
	bool bandDistancia;									//Bandera que indica que debe hacerse una lectura del sensor VL53L0X
	uint8_t senStatus[MAX_PARR][MAX_FILAS];				//Estatus de la medición del sensor
	uint8_t contDistancia;								//Contador de mediciones de distancia hechas
	uint8_t contParrilla;								//Contador de parrillas
	uint8_t cantFilas[MAX_PARR];						//Cantidad de filas habilitadas en cada parrilla
	uint16_t datosDistancia[MAX_PARR][MAX_FILAS];		//Matriz para almacenar la distancia sensada en milímetros [mm]
	uint16_t datosDistancia2[MAX_PARR][MAX_FILAS][5];	//Arreglo para almacenar la distancia sensada en milímetros [mm]
	uint8_t sensor[MAX_PARR*MAX_FILAS];					//Sensor que se debe usar
	uint8_t posSensor[MAX_PARR];						//Indica la fila de cada sensor
	uint8_t SenHab;										//Indica la cantidad de sensores habilitados
	uint8_t bandInicio[MAX_PARR];						//Indica si la cada sensor ya fue leido la primera vez o no

	VL53L1_RangingMeasurementData_t RangingData;		//Estructura para datos de medición del sensor
	VL53L1_Dev_t  VL53L1_DEV[MAX_PARR];					//Estructura sensor
//	VL53L1_DEV    Dev;
};


//********************************************************************
//Estructura de datos para el Bloque Motor
//********************************************************************

typedef struct stMotor stMotor;
struct stMotor
{			
	bool bandMotor;								//Bandera que indica que debe moverse el motor a una nueva posición
	int32_t posInicial;							//Variable que guarda la posición incial del motor //Fix int32 por int8
	int8_t posMotor;							//Variable que guarda la posición actual del motor
	uint8_t cantFilas[MAX_PARR];				//Cantidad de filas habilitadas en cada parrilla
	uint32_t distFilas[MAX_PARR][MAX_FILAS];	//Variable que guarda la distancia entre las filas (en pasos) de cada parrilla
	uint32_t recorrido[MAX_PARR*MAX_FILAS];		//Variable que guarda el recorrido (en pasos) de los motores
	uint8_t ParrHab;							//Variable que guarda la cantidad de Parrillas habilitadas
	uint8_t MaxPosMotor;						//Variable que guarda la cantidad de Parrillas habilitadas
	
//	Stspin220_Init_t initDeviceParameters;			//Estructura con la configuración del motor
};

/*********************************************************************
*
* 						Prototipos de Funciones
*
*********************************************************************/
char Iniciar_EstrucCaptura(stCaptura *pstcaptura);
char Iniciar_EstrucComCEIT(stComCEIT *pstcomceit);
char Iniciar_EstrucDistancia(stDistancia *pstdistancia);
char Iniciar_EstrucMotor(stMotor *pstmotor);

#endif	//__ESTRUCTURAS_H
