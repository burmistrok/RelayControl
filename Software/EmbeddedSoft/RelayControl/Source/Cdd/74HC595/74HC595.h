/*
 * 74HC595.h
 *
 *  Created on: Jul 8, 2021
 *      Author: oleg.burmistr
 */

#ifndef CDD_74HC595_74HC595_H_
#define CDD_74HC595_74HC595_H_

#include "Std_types.h"


void v74HC595_Init			(const void* configPtr);
void v74HC595_DeInit		(void);
void v74HC595_MainFunction	(void);
uint16_t u16SendCmd(uint16_t Data);

#endif /* CDD_74HC595_74HC595_H_ */
