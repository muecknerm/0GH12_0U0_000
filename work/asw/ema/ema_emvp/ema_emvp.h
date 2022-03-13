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
#include <stdint.h>

void vDoIniEmvp(void);

void vDoClcDucyPwmInvt(void);

int16_t Get_s16DucyPwmL1Invt(void);

int16_t Get_s16DucyPwmL2Invt(void);
