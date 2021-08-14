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
Archivo cabecera para el bloque Distancia.

*********************************************************************/
#ifndef __DISTANCIA_H
#define __DISTANCIA_H
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
uint8_t BloqueDistancia(stDistancia *pstdistancia);
uint8_t EnableSensors(stDistancia *pstdistancia);
int IniciarSensores(stDistancia *pstdistancia);
void Convertir4Cif(uint16_t numero, uint8_t *mil, uint8_t *centena,	uint8_t *decena, uint8_t *unidad);
uint8_t DetectSensors(stDistancia *pstdistancia);
uint8_t SetupSingleShot(stDistancia *pstdistancia);

#endif	//__DISTANCIA_H
