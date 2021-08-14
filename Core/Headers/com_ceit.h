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
Archivo cabecera para el bloque COM_CEIT.

*********************************************************************/
#ifndef __COM_CEIT_H
#define __COM_CEIT_H
/*********************************************************************
*
* 						Archivos Cabecera
*
*********************************************************************/
#include "estructuras.h"

/*********************************************************************
*
* 						Macro definiciones
*
*********************************************************************/


/*********************************************************************
*
* 						Tipos de Datos
*
*********************************************************************/
extern volatile FlagStatus xRxDoneFlag, xTxDoneFlag;
extern volatile FlagStatus PushButtonStatusWakeup; 
extern volatile FlagStatus PushButtonStatusData, datasendFlag;


/*********************************************************************
*
* 						Prototipos de Funciones
*
*********************************************************************/
void BloqueCOM_CEIT(stComCEIT *pstcomceit);		


#endif	//__COM_CEIT_H
