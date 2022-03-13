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

#include "tim.h"
#include "tim1.h"

void vDoSetPwmBswInvt(uint16_t pwm_PhaseU, uint16_t pwm_PhaseV)
{
	TIM1->CCR1 = pwm_PhaseU;
	TIM1->CCR2 = pwm_PhaseV;
}
