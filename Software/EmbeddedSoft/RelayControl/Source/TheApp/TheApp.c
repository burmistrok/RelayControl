/*
 * TheApp.c
 *
 *  Created on: Jul 8, 2021
 *      Author: oleg.burmistr
 */


#include "TheApp.h"
#include "74HC595.h"
#include "HAL_USART.h"

#define ENABLE_IRQ 		__enable_irq
#define DISABLE_IRQ		__disable_irq


uint16_t BufferForTrash;																/*create due to HAL_USART_Sendbuffer*/
#define SEND_MSG(Data, Len) HAL_USART_SendBuffer(USART_STR, Data, Len, &BufferForTrash)
#define CMD_LEN 		(4u)
#define RX_CMD_LEN		CMD_LEN

#define SIZE_OF_U8		(8u)

#define SET_CMD 		0xAA
#define RESET_CMD		0x52
#define RESET_BYTE1		0x45
#define RESET_BYTE2		0x53

#define THE_APP_REC_TIME	(1u)

#define DEB_TIME_CMD_NOT_REC	(20u/THE_APP_REC_TIME)


static bool bTheAppInit = false;
static uint8_t u8_PrevNbOfRecievedByte;
static uint16_t u16_CmdNotCompTimer;

volatile uint8_t u8_NbOfRecievedByte;
volatile uint8_t ua8_RxBuffer[RX_CMD_LEN];


const uint8_t CmdNOK_MSG[RX_CMD_LEN] = {0x4E,0x4F,0x4B,0x4A};

static uint8_t u8GetBytesCnt(void);
static bool IsPacketCorrupted(void);
static void vResetBytesCnt(void);
static uint8_t ClcXorCrc(uint8_t* Data, uint8_t len);

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vTheApp_Init(const void* configPtr)
{
	uint8_t lu8_cnt = 0u;

	bTheAppInit = true;
	u8_PrevNbOfRecievedByte = 0u;
	u16_CmdNotCompTimer = 0u;
	for (lu8_cnt = 0u; lu8_cnt < RX_CMD_LEN;  lu8_cnt++ )
	{
		ua8_RxBuffer[lu8_cnt] = 0u;
	}
	u8_NbOfRecievedByte = 0u;
	(void)configPtr;
}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vTheApp_DeInit(void)
{
	bTheAppInit = false;

}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vTheApp_MainFunction(void)
{

	uint8_t lu8_NbOfRecievedBytes = 0u;
	bool lb_IsCmdOK = false;
	uint16_t lu16_bytesRec = 0u;
	uint16_t lu16_bytesSet = 0u;
	uint8_t lua8_TX_Buffer[CMD_LEN] = {0u,0u,0u,0u};

	if (false == bTheAppInit)
	{
		return;
	}
	else
	{
		lu8_NbOfRecievedBytes = u8GetBytesCnt();
		if (RX_CMD_LEN == lu8_NbOfRecievedBytes)
		{
			if (false != IsPacketCorrupted())
			{
				lb_IsCmdOK = false;
				vResetBytesCnt();
			}
			else
			{
				switch (ua8_RxBuffer[0u])
				{
				case SET_CMD:

					lu16_bytesRec = (uint16_t)ua8_RxBuffer[1u];
					lu16_bytesRec |= (((uint16_t)ua8_RxBuffer[2u])<<SIZE_OF_U8);
					lu16_bytesSet = u16SendCmd(lu16_bytesRec);

					lua8_TX_Buffer[0u] = SET_CMD;
					lua8_TX_Buffer[1u] = (uint8_t)(0x00FF&lu16_bytesSet);
					lua8_TX_Buffer[2u] = (uint8_t)((0xFF00 & lu16_bytesSet)>>SIZE_OF_U8);
					lua8_TX_Buffer[3u] = ClcXorCrc(lua8_TX_Buffer, (CMD_LEN-1u) );

					SEND_MSG(lua8_TX_Buffer, CMD_LEN);
					lb_IsCmdOK = true;
					break;

				case RESET_CMD:

					if ( (ua8_RxBuffer[1u] == RESET_BYTE1) && (ua8_RxBuffer[2u] == RESET_BYTE2))
					{
						/*Reset MC*/
						lb_IsCmdOK = true;
					}
					break;

				default:
					lb_IsCmdOK = false;

				}
				vResetBytesCnt();
			}
			if (false == lb_IsCmdOK)
			{
				SEND_MSG((uint8_t*)CmdNOK_MSG, CMD_LEN);
			}
		}

		/*If last cmd is not completed more than some time, reset counter of received bytes, to be prepared to receive new cmd*/
		if (0u != lu8_NbOfRecievedBytes)
		{
			if (u8_PrevNbOfRecievedByte == lu8_NbOfRecievedBytes)
			{
				if (DEB_TIME_CMD_NOT_REC > u16_CmdNotCompTimer)
				{
					u16_CmdNotCompTimer++;
				}

				if (DEB_TIME_CMD_NOT_REC == u16_CmdNotCompTimer)
				{
					vResetBytesCnt();
				}
			}
			else
			{
				u8_PrevNbOfRecievedByte = lu8_NbOfRecievedBytes;
				u16_CmdNotCompTimer = 0u;
			}

		}


	}

}




#ifdef USE_DIRECT_CALL_BACK
void vTheApp_CallBackRx		(uint8_t Data)
{
	if (RX_CMD_LEN > u8_NbOfRecievedByte)
	{
		ua8_RxBuffer[u8_NbOfRecievedByte] = Data;
		u8_NbOfRecievedByte++;
	}

}

#endif

static uint8_t u8GetBytesCnt(void)
{
	uint8_t lu8_RetVal = false;
	DISABLE_IRQ();
	lu8_RetVal = u8_NbOfRecievedByte;
	ENABLE_IRQ();


	return lu8_RetVal;
}

static bool IsPacketCorrupted(void)
{
	bool lb_RetVal = true;
	uint8_t lu8_cnt = 0u;
	uint8_t lu8_Flag = ua8_RxBuffer[0u];

	for (lu8_cnt = 1u; lu8_cnt < RX_CMD_LEN; lu8_cnt++)
	{
		lu8_Flag ^= ua8_RxBuffer[lu8_cnt];
	}

	if (0u == lu8_Flag)
	{
		lb_RetVal = false;
	}


	return lb_RetVal;
}

static void vResetBytesCnt(void)
{
	DISABLE_IRQ();
	u8_NbOfRecievedByte = 0u;
	ENABLE_IRQ();
	u8_PrevNbOfRecievedByte = 0u;
}

static uint8_t ClcXorCrc(uint8_t* Data, uint8_t len)
{
	uint8_t lu8_RetVal = *Data;
	uint8_t lu8_cnt = 0u;

	for (lu8_cnt = 1u; lu8_cnt < len; lu8_cnt++)
	{
		lu8_RetVal ^= *(Data+lu8_cnt);
	}

	return lu8_RetVal;

}
