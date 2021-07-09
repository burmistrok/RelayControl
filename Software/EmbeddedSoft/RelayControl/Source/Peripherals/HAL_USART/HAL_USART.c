/*
 * USART.c
 *
 *  Created on: Apr 14, 2020
 *      Author: ok
 */


#include "HAL_USART.h"
#include "CircularFIFOBuffer.h"
#ifdef USE_DIRECT_CALL_BACK
#include "TheApp.h"
#endif


static bool bUSARTInit = false;
static TS_CircularFIFOBuffer TX_Buffer;
static TS_CircularFIFOBuffer RX_Buffer;


static void vLL_USART_Init(void);


/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vUSART_Init(const void* configPtr())
{

	bUSARTInit = true;
	if (NULL_PTR != configPtr)
	{
		(void)configPtr();
	}
	memset(TX_Buffer.Buffer, 0, BUFFER_SIZE);
	memset(RX_Buffer.Buffer, 0, BUFFER_SIZE);
	vLL_USART_Init();
}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vUSART_DeInit(void)
{
	bUSARTInit = false;

}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vUSART_MainFunction(void)
{

#if 0
	uint16_t u16_len;
	uint8_t tmp_Buffer[BUFFER_SIZE];

	if ( bUSARTInit == false)
	{
		return;
	}
	else
	{
		//HAL_USART_SendBuffer(USART_STR, (uint8_t*)&"U\n", 2, &u16_len);
		HAL_USART_ReceiveBuffer(USART_STR, &tmp_Buffer[0], BUFFER_SIZE, &u16_len);
		if (u16_len != 0u)
		{
			HAL_USART_SendBuffer(USART_STR, &tmp_Buffer[0], u16_len, &u16_len);

		}

	}
#endif


}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vUSART_ITCallBack(void)
{
	volatile uint8_t u8_Data = 0;

	if ((USART_STR->ISR & USART_ISR_RXNE_Msk) == USART_ISR_RXNE)
	{
#ifdef USE_DIRECT_CALL_BACK
		vTheApp_CallBackRx( LL_USART_ReceiveData8(USART_STR) );
#else
		(void)bCircularFIFOBuffer_addElement(&RX_Buffer, LL_USART_ReceiveData8(USART_STR));
#endif
	}

	if ((USART_STR->ISR & USART_ISR_TC_Msk) == USART_ISR_TC)
	{
		if (bCircularFIFOBuffer_getElement(&TX_Buffer, (uint8_t*) &u8_Data) == false )
		{
			if ((USART_STR->CR1 & USART_CR1_TCIE_Msk) == USART_CR1_TCIE)
			{
				LL_USART_DisableIT_TC(USART_STR);
			}
		}
		else
		{
			LL_USART_TransmitData8(USART_STR, u8_Data);
		}
	}
}

static void vLL_USART_Init(void)
{
	LL_USART_EnableIT_RXNE(USART_STR);
}



TE_ERROR HAL_USART_GetChar(TS_USART* USARTx, uint8_t* Data)
{
	uint8_t u8_Data = 0;
	if (bCircularFIFOBuffer_getElement(&RX_Buffer, (uint8_t*) &u8_Data) == true )
	{
		*Data = u8_Data;
		return ERR_OK;
	}
	else
	{
		return ERR_NOK;
	}


}


TE_ERROR HAL_USART_SendChar(TS_USART* USARTx, uint8_t Data)
{



	if (bCircularFIFOBuffer_addElement(&TX_Buffer, Data) == true )
	{
		if ( (USART_STR->CR1 & USART_CR1_TCIE_Msk) != USART_CR1_TCIE )
		{
			LL_USART_EnableIT_TC(USART_STR);
		}
		return ERR_OK;
	}
	else
	{
		return ERR_BUFFER_FULL;
	}

}



TE_ERROR HAL_USART_SendBuffer(TS_USART* USARTx, uint8_t* Data, uint16_t Len, uint16_t* RecievedLen)
{
	uint16_t u16_Len = 0u;
	*RecievedLen = 0u;

	while (Len > u16_Len)
	{
		if (ERR_OK == HAL_USART_SendChar( USART_STR, *Data))
		{
			Data++;
			u16_Len++;
			(*RecievedLen)++;
		}
		else
		{
			return ERR_BUFFER_FULL;
		}
	}

	return ERR_OK;

}

TE_ERROR HAL_USART_ReceiveBuffer(TS_USART* USARTx, uint8_t* Data, uint16_t Len, uint16_t* RecievedLen)
{


	uint16_t u16_Len = 0u;
	*RecievedLen = 0u;

	while (Len > u16_Len)
	{
		if (ERR_OK == HAL_USART_GetChar( USART_STR, Data))
		{
			Data++;
			u16_Len++;
			(*RecievedLen)++;
		}
		else
		{
			return ERR_BUFFER_EMPTY;
		}
	}

	return ERR_OK;
}

