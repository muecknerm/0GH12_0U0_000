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

#include "ema_emsc.h"
#include "ema_emrps.h"
#include "ema_emsm.h"

int16_t s16SpeedRef;
int16_t s16PwmClc;

void vDoInitEmsc(void)
{
	s16PwmClc = 0;
	s16SpeedRef = 0;
}

void vDoClcEmsc(void)
{
	int16_t	s16SpeedMechLid;
	int16_t s16SpeedDeviation;


	static int16_t s16IPartCtrlSum = 0;
	static int16_t s16SpeedRefLid = 0;



	s16SpeedMechLid = Get_s16SpeedMech();

	if (s16SpeedMechLid > 2000)
	{
		s16SpeedMechLid = 2000;
	}
	else if (s16SpeedMechLid < -2000)
	{
		s16SpeedMechLid = -2000;
	};

	if (Get_bEnaPwmOutput() == 0)
	{
		s16IPartCtrlSum = 0;
	}


	if (s16SpeedRefLid != s16SpeedRef)
	{
		if (s16SpeedRefLid < s16SpeedRef)
		{
			s16SpeedRefLid = s16SpeedRefLid + 5;
		}
		else
		{
			s16SpeedRefLid = s16SpeedRefLid - 5;
		}
	}

	s16SpeedDeviation = (s16SpeedRefLid - Get_s16SpeedMech() );

	s16IPartCtrlSum = (s16IPartCtrlSum + s16SpeedDeviation);

	if (s16IPartCtrlSum > 30000)
	{
		s16IPartCtrlSum = 30000;
	}
	else if (s16IPartCtrlSum < -30000)
	{
		s16IPartCtrlSum = -30000;
	}

	//s16IPartCtrlSum = 0;


	//s16IPartCtrlSum = s16IPartCtrlSum + s16IPartCtrlSum;

	s16PwmClc =  s16SpeedDeviation / 2 + (s16IPartCtrlSum / 10 );


	//s16PwmClc = s16SpeedRef;
}

void Set_s16SpeedRef(int16_t s16SpeedRefTmp)
{
	s16SpeedRef = s16SpeedRefTmp;
}

int16_t Get_s16SpeedRef(void)
{
	return s16SpeedRef;
}

int16_t Get_s16PwmClc(void)
{
	return s16PwmClc;
}

