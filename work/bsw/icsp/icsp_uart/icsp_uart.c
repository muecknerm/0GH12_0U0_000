

#include "icsp_uart.h"
#include "usart.h"
#include "ema_emrps.h"
#include "ema_emsc.h"
#include "ema_emvp.h"

uint8_t u8TxBuffer[100];
uint8_t u8RxBuffer[100];


void InitUart(void)
{
	HAL_UART_Receive_IT(&huart1, &u8RxBuffer[0], 7);
}

void sendTxPacket(void)
{
	static uint16_t u16Counter = 0;

	u16Counter++;

	if (u16Counter > 100)
	{
		u16Counter = 0;
	}

	u8TxBuffer[0] = '#';
	u8TxBuffer[1] = '#';

	u8TxBuffer[2] = (uint8_t) (u16Counter >> 8);
	u8TxBuffer[3] = (uint8_t) u16Counter;

	u8TxBuffer[4] = (uint8_t) (Get_s16AngleRot() >> 8);
	u8TxBuffer[5] = (uint8_t) Get_s16AngleRot();

	u8TxBuffer[6] = (uint8_t) (Get_s16SpeedMech() >> 8);
	u8TxBuffer[7] = (uint8_t) Get_s16SpeedMech();

	u8TxBuffer[8] = (uint8_t) (Get_s16DucyPwmL1Invt() >> 8);
	u8TxBuffer[9] = (uint8_t) Get_s16DucyPwmL1Invt();

	u8TxBuffer[10] = (uint8_t) (Get_s16DucyPwmL2Invt() >> 8);
	u8TxBuffer[11] = (uint8_t) Get_s16DucyPwmL2Invt();

	u8TxBuffer[12] = (uint8_t) (Get_s16SpeedRef() >> 8);
	u8TxBuffer[13] = (uint8_t) Get_s16SpeedRef();

	u8TxBuffer[14] = 0;
	u8TxBuffer[15] = 0;

	u8TxBuffer[16] = 0;
	u8TxBuffer[17] = 0;


    HAL_UART_Transmit_IT(&huart1, &u8TxBuffer[0], 23);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint8_t index;

	index = u8RxBuffer[2];
	int16_t s16SpeedRefLid;

	switch (index)
	{
		case 0x10:
		{
			s16SpeedRefLid = (int16_t) ((uint16_t) ( (u8RxBuffer[3] << 8) | u8RxBuffer[4]));
			Set_s16SpeedRef(s16SpeedRefLid);
			break;
		}
		case 0x11:
		{
			break;
		}
	}
	HAL_UART_Abort_IT(&huart1);
    HAL_UART_Receive_IT(&huart1, &u8RxBuffer[0], 7);
}
