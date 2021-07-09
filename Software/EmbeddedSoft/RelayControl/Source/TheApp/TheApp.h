/*
 * TheApp.h
 *
 *  Created on: Jul 8, 2021
 *      Author: oleg.burmistr
 */

#ifndef THEAPP_THEAPP_H_
#define THEAPP_THEAPP_H_
#include "Std_types.h"


void vTheApp_Init			(const void* configPtr);
void vTheApp_DeInit			(void);
void vTheApp_MainFunction	(void);

void vTheApp_CallBackRx		(uint8_t Data);


#endif /* THEAPP_THEAPP_H_ */
