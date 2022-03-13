/*********************************************************************************
 *
 *  File name:           $Source: tim1.c $
 *  Revision:            $Revision: 1.1 $
 *  Author:              $Author: muecknerm $
 *  Date:                $Date: 2016/09/07 12:31:14CEST $
 *
 *  Description:         control of electrical machine PWM signals
 *  Originator:
 *  Specification:       UKM02X01
 *
 *********************************************************************************/

#include "gpio.h"
#include "ema_emvp.h"
#include "tim1.h"


void vDoUpdPwmEm1(void)
{
	uint16_t u16PwmDucyPhaseU, u16PwmDucyPhaseV;

	if (Get_bEnaPwmOutput() == 1)
	{
		u16PwmDucyPhaseU = 1800 + Get_s16DucyPwmL1Invt();
		u16PwmDucyPhaseV = 1800 + Get_s16DucyPwmL2Invt();
	}
	else
	{
		u16PwmDucyPhaseU = 0;
		u16PwmDucyPhaseV = 0;
	}

	vDoSetPwmBswInvt(u16PwmDucyPhaseU, u16PwmDucyPhaseV);
}

void EnablePwm()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
}

void DisablePwm()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
}

