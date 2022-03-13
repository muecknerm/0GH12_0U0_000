/*
 * ema_emrps.c
 *
 *  Created on: 12.03.2022
 *      Author: User
 */

#include "ema_emrps.h"
#include "tim.h"

/*********************************************************************************
* Unit global variables
**********************************************************************************/
int16_t s16SpeedMech;
int16_t s16SpeedMechLpf;
int16_t s16AngleRot;
int16_t s16AngleLpf;

uint16_t u16CntEncoderTim8Old;


void vDoInitEmrps(void)
{
	u16CntEncoderTim8Old = 0;
}
void vDoClcEmrps(void)
{
	uint16_t u16CntEncoderTim8;

	u16CntEncoderTim8 = TIM8->CNT;

	s16AngleRot = u16CntEncoderTim8;

	s16SpeedMech =  (u16CntEncoderTim8 - u16CntEncoderTim8Old);

	if (s16SpeedMech > 1000)
	{
		s16SpeedMech = s16SpeedMech - 2000;
	}
	else if (s16SpeedMech < -1000)
	{
		s16SpeedMech = s16SpeedMech + 2000;
	}

	s16SpeedMech = s16SpeedMech * 30;

	u16CntEncoderTim8Old = u16CntEncoderTim8;
}

/*********************************************************************************
* unit interfacae
**********************************************************************************/
int16_t Get_s16AngleRot(void)
{
	return s16AngleRot;
}

int16_t Get_s16SpeedMech(void)
{
	return s16SpeedMech;
}
