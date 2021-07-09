/*
 * 74HC595.c
 *
 *  Created on: Jul 8, 2021
 *      Author: oleg.burmistr
 */

#include "74HC595.h"

#define SET_UO() 			LL_GPIO_SetOutputPin(UPDATE_OUT_GPIO_Port, UPDATE_OUT_Pin)
#define RESET_UO()			LL_GPIO_ResetOutputPin(UPDATE_OUT_GPIO_Port, UPDATE_OUT_Pin)

#define SET_RST() 			LL_GPIO_SetOutputPin(RESET_GPIO_Port, RESET_Pin)
#define RESET_RST()			LL_GPIO_ResetOutputPin(RESET_GPIO_Port, RESET_Pin)

#define SET_CLK() 			LL_GPIO_SetOutputPin(CLK_GPIO_Port, CLK_Pin)
#define RESET_CLK()			LL_GPIO_ResetOutputPin(CLK_GPIO_Port, CLK_Pin)

#define SET_DATA() 			LL_GPIO_SetOutputPin(DATA_GPIO_Port, DATA_Pin)
#define RESET_DATA()		LL_GPIO_ResetOutputPin(DATA_GPIO_Port, DATA_Pin)

#define READ_FEEDBACK()		LL_GPIO_IsInputPinSet(FEEDBACK_GPIO_Port,FEEDBACK_Pin)

#define SHIFT_LEFT(Data)	(Data = Data<<1u)
#define SHIFT_RIGHT(Data)	(Data = Data>>1u)

#define SIZE_OF_U8		(8u)

#define INITIAL_MASK 	(128u)

static uint8_t u8SendByte(uint8_t Data);


static bool b74HC595Init = false;

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void v74HC595_Init(const void* configPtr)
{

	b74HC595Init = true;
	/*Clear all registers*/
	RESET_RST();
	SET_RST();
	SET_UO();
	RESET_UO();

	(void)configPtr;
}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void v74HC595_DeInit(void)
{
	b74HC595Init = false;

}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void v74HC595_MainFunction(void)
{

	if (false == b74HC595Init)
	{
		return;
	}
	else
	{

	}

}

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
uint16_t u16SendCmd(uint16_t Data)
{

	uint16_t lu16_ReturnValue = 0u;
	uint8_t* pu8_RetValue = (uint8_t*)&lu16_ReturnValue;
	uint8_t* pu8_Data = (uint8_t*)&Data;

	(void)u8SendByte(*pu8_Data);
	(void)u8SendByte(*(pu8_Data+1u));

	SET_UO();
	RESET_UO();

	*pu8_RetValue = u8SendByte(*pu8_Data);
	*(pu8_RetValue + 1u) = u8SendByte(*(pu8_Data+1u));

	return lu16_ReturnValue;
}



static uint8_t u8SendByte(uint8_t Data)
{
	uint8_t lu8_RetData = 0u;
	uint8_t lu8_Cnt = 0u;
	uint8_t lu8_Mask = INITIAL_MASK;

	for(lu8_Cnt = 0u; lu8_Cnt < SIZE_OF_U8; lu8_Cnt++)
	{
		if ( 0u != (Data & lu8_Mask) )
		{
			SET_DATA();
		}
		else
		{
			RESET_DATA();
		}

		SET_CLK();
		RESET_CLK();

		if( 0u != READ_FEEDBACK() )
		{
			lu8_RetData |= lu8_Mask;
		}
		else
		{
			/*lu8_RetData is initialized with 0u, so there is not reason to reset bit*/
		}

		SHIFT_RIGHT(lu8_Mask);
	}
	return lu8_RetData;

}

