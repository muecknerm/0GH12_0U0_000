
#include "ema_emsm.h"
#include "ema_emsc.h"

uint8_t bEnaPwmOutput;


void vDoInitEmsm(void)
{
	bEnaPwmOutput = 0;
}

void vDoClcEmsm(void)
{

	int16_t s16SpeedRefLid;

	s16SpeedRefLid = Get_s16SpeedRef();

	if (s16SpeedRefLid >= 1 || s16SpeedRefLid <= -1)
	{
		bEnaPwmOutput = 1;
	}
	else
	{
		bEnaPwmOutput = 0;
	}
}

uint8_t Get_bEnaPwmOutput(void)
{
	return bEnaPwmOutput;
}

