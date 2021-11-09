/*
 * HAL_USART.h
 *
 *  Created on: Apr 14, 2020
 *      Author: ok
 */

#ifndef PERIPHERALS_HAL_USART_HAL_USART_H_
#define PERIPHERALS_HAL_USART_HAL_USART_H_


#include "Std_types.h"
#include <stdio.h>

#define USART_STR USART2


void vUSART_Init			(const void* configPtr());
void vUSART_DeInit			(void);
void vUSART_MainFunction	(void);

void vUSART_ITCallBack(void);

void HAL_USART_SendBuffer(TS_USART* USARTx, uint8_t* Data, uint16_t Len, uint16_t* RecievedLen);

#ifndef USE_DIRECT_CALL_BACK
void HAL_USART_ReceiveBuffer(TS_USART* USARTx, uint8_t* Data, uint16_t Len, uint16_t* RecievedLen);
#endif

#endif /* PERIPHERALS_HAL_USART_HAL_USART_H_ */
