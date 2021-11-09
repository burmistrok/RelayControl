/*
 * USART.c
 *
 *  Created on: Apr 14, 2020
 *      Author: ok
 */


#include "HAL_USART.h"

#ifdef USE_DIRECT_CALL_BACK
#include "TheApp.h"
#endif

#define UART_TX_BUF_SIZE	(32u)
#define UART_RX_BUF_SIZE	(64u)

#define UART_TX_BUF_SIZE_MASK                   (UART_TX_BUF_SIZE - 1u)
#if (UART_TX_BUF_SIZE & UART_TX_BUF_SIZE_MASK)
#error UART_TX_BUF_SIZE is not power of 2
#endif

#define UART_RX_BUF_SIZE_MASK                   (UART_RX_BUF_SIZE - 1u)
#if (UART_RX_BUF_SIZE & UART_RX_BUF_SIZE_MASK)
#error UART_RX_BUF_SIZE is not power of 2
#endif

typedef struct{
#ifndef USE_DIRECT_CALL_BACK
	uint8_t 	u8_RxBuffer[UART_RX_BUF_SIZE];
	uint16_t	u16_RxHead;
	uint16_t	u16_RxTail;
#endif
	uint8_t 	u8_TXBuffer[UART_TX_BUF_SIZE];
	uint16_t	u16_TxHead;
	uint16_t	u16_TxTail;
}TS_UsartDataType;


TS_UsartDataType rs_UsartDataType;

static bool bUSARTInit = false;


static void vLL_USART_Init(void);

static void vUSART_RxIsr(void);

static inline void vUSART_FillUpBufferAndHandlerIsr(void);


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
#ifndef USE_DIRECT_CALL_BACK
	rs_UsartDataType.u16_RxHead = 0u;
	rs_UsartDataType.u16_RxTail = 0u;
#endif
	rs_UsartDataType.u16_TxHead = 0u;
	rs_UsartDataType.u16_TxTail = 0u;
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
	/*Reset parity error*/
	if( (0u != LL_USART_IsActiveFlag_PE(USART_STR)) && (0u != LL_USART_IsEnabledIT_PE(USART_STR)) )
	{
		(void)LL_USART_ReceiveData8(USART_STR);
		LL_USART_ClearFlag_PE(USART_STR);
	}

	/*Reset frame error*/
	if( (0u != LL_USART_IsActiveFlag_FE(USART_STR)) && (0u != LL_USART_IsEnabledIT_ERROR(USART_STR)) )
	{
		(void)LL_USART_ReceiveData8(USART_STR);
		LL_USART_ClearFlag_FE(USART_STR);
	}

	/*Reset noise error*/
	if( (0u != LL_USART_IsActiveFlag_NE(USART_STR)) && (0u != LL_USART_IsEnabledIT_ERROR(USART_STR)) )
	{
		(void)LL_USART_ReceiveData8(USART_STR);
		LL_USART_ClearFlag_NE(USART_STR);
	}

	/*Reset Over-run error*/
	if( (0u != LL_USART_IsActiveFlag_ORE(USART_STR)) && (0u != LL_USART_IsEnabledIT_ERROR(USART_STR)) )
	{
		(void)LL_USART_ReceiveData8(USART_STR);
		LL_USART_ClearFlag_ORE(USART_STR);
	}

	/*RX interrupt*/
	if( (0u != LL_USART_IsActiveFlag_RXNE(USART_STR)) && (0u != LL_USART_IsEnabledIT_RXNE(USART_STR)) )
	{
		vUSART_RxIsr();
	}

	/*TX buffer empty interrupt*/
	if( (0u != LL_USART_IsActiveFlag_TXE(USART_STR)) && (0u != LL_USART_IsEnabledIT_TXE(USART_STR)) )
	{
		LL_USART_DisableIT_TXE(USART_STR);
		vUSART_FillUpBufferAndHandlerIsr();
	}

	/*TX completed interrupt*/
	if( (0u != LL_USART_IsActiveFlag_TC(USART_STR)) && (0u != LL_USART_IsEnabledIT_TC(USART_STR)) )
	{
		LL_USART_DisableIT_TC(USART_STR);
		LL_USART_ClearFlag_TC(USART_STR);
	}
}

static void vLL_USART_Init(void)
{
	LL_USART_EnableIT_RXNE(USART_STR);
}

void HAL_USART_SendBuffer(TS_USART* USARTx, uint8_t* Data, uint16_t Len, uint16_t* RecievedLen)
{
	uint16_t u16_Len = 0u;
	*RecievedLen = 0u;

	do
	{
		rs_UsartDataType.u16_TxHead = ((rs_UsartDataType.u16_TxHead + 1u) & UART_TX_BUF_SIZE_MASK);
		if( rs_UsartDataType.u16_TxTail != rs_UsartDataType.u16_TxHead )
		{
			rs_UsartDataType.u8_TXBuffer[rs_UsartDataType.u16_TxHead] = *Data;
			Data++;
			u16_Len++;
			(*RecievedLen)++;
		}
	}
	while( ( rs_UsartDataType.u16_TxTail != rs_UsartDataType.u16_TxHead ) &&  (Len > u16_Len) );

	vUSART_FillUpBufferAndHandlerIsr();
}

#ifndef USE_DIRECT_CALL_BACK
void HAL_USART_ReceiveBuffer(TS_USART* USARTx, uint8_t* Data, uint16_t Len, uint16_t* RecievedLen)
{
	uint16_t u16_Len = 0u;
	*RecievedLen = 0u;

	while(Len > u16_Len)
	{
		if( rs_UsartDataType.u16_RxTail != rs_UsartDataType.u16_RxHead )
		{
			rs_UsartDataType.u16_RxTail = ((rs_UsartDataType.u16_RxTail + 1u) & UART_RX_BUF_SIZE_MASK);
			(*Data) = rs_UsartDataType.u8_RxBuffer[rs_UsartDataType.u16_RxTail];
			Data++;
			u16_Len++;
			(*RecievedLen)++;
		}
	}
}
#endif


static void vUSART_RxIsr(void)
{

#ifdef USE_DIRECT_CALL_BACK
	vTheApp_CallBackRx(LL_USART_ReceiveData8(USART_STR));
#else
	uint16_t lu16_ClcHead = ((rs_UsartDataType.u16_RxHead + 1u) & UART_RX_BUF_SIZE_MASK);
	if(rs_UsartDataType.u16_RxTail != lu16_ClcHead)
	{
		rs_UsartDataType.u16_RxHead = lu16_ClcHead;
		rs_UsartDataType.u8_RxBuffer[lu16_ClcHead] = LL_USART_ReceiveData8(USART_STR);
	}
#endif
}


static inline void vUSART_FillUpBufferAndHandlerIsr(void)
{
	while( (rs_UsartDataType.u16_TxHead != rs_UsartDataType.u16_TxTail) && ( 0u != LL_USART_IsActiveFlag_TXE(USART_STR) ) )
	{
		rs_UsartDataType.u16_TxTail = ((rs_UsartDataType.u16_TxTail + 1u) & UART_TX_BUF_SIZE_MASK);
		LL_USART_TransmitData8(USART_STR, rs_UsartDataType.u8_TXBuffer[rs_UsartDataType.u16_TxTail]);
	}

	if(rs_UsartDataType.u16_TxHead != rs_UsartDataType.u16_TxTail)
	{
		LL_USART_EnableIT_TXE(USART_STR);
	}
	else
	{
		LL_USART_EnableIT_TC(USART_STR);
	}
}
