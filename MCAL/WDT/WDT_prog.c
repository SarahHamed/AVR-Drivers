/*
 * WDT_prog.c
 *
 *  Created on: Feb 18, 2022
 *      Author: user
 */
#include "WDT_register.h"
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"

//set sleep time
void WDT_vidSetTimer(u8 time)
{
	WDTCR&=0b11111000;
	WDTCR|=time;
}


void WDT_vidEn()
{
	BIT_SET(WDTCR, WDTCR_WDE);
}

void WDT_vidDisable()
{
	WDTCR|=0b00011000;
	WDTCR=0;
}

