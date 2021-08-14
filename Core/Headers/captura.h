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
Archivo cabecera para el bloque Captura.

*********************************************************************/
#ifndef __CAPTURA_H
#define __CAPTURA_H
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

/*********************************************************************
*
* 						Prototipos de Funciones
*
*********************************************************************/
void BloqueCaptura(stCaptura *pstcaptura, stComCEIT *pstcomceit, stMotor *pstmotor, stDistancia *pstdistancia);
void ConfigParrillas(stCaptura *pstcaptura, stComCEIT *pstcomceit, stMotor *pstmotor, stDistancia *pstdistancia);
void Ordenar(stMotor *pstmotor, stDistancia *pstdistancia);
uint8_t ConvertirDistancia(stCaptura *pstcaptura, stDistancia *pstdistancia);

#endif	//__CAPTURA_H
