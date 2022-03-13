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
#include "ema_emvp.h"
#include "ema_emsc.h"

/*********************************************************************************
* Unit global variables
**********************************************************************************/
int16_t s16DucyPwmL1Invt;
int16_t s16DucyPwmL2Invt;


/*********************************************************************************
* Unit global variables
**********************************************************************************/
void vDoIniEmvp(void)
{
	s16DucyPwmL1Invt = 0;
	s16DucyPwmL2Invt = 0;
}

void vDoClcDucyPwmInvt(void)
{
	int16_t s16PWMDucyRaw;

	s16PWMDucyRaw = Get_s16PwmClc();


	  if (s16PWMDucyRaw > 1800)
	  {
		  s16PWMDucyRaw = 1800;
	  }
	  else if (s16PWMDucyRaw < -1800)
	  {
		  s16PWMDucyRaw = -1800;
	  }

	s16DucyPwmL1Invt = 	s16PWMDucyRaw;
	s16DucyPwmL2Invt = -1 * s16PWMDucyRaw;
}


/*********************************************************************************
* Unit Interfacae
**********************************************************************************/


int16_t Get_s16DucyPwmL1Invt(void)
{
	return s16DucyPwmL1Invt;
}

int16_t Get_s16DucyPwmL2Invt(void)
{
	return s16DucyPwmL2Invt;
}
