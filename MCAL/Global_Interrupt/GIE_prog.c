/*
 * GIE_prog.c
 *
 *  Created on: Jan 1, 2022
 *      Author: user
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "GIE_register.h"

void GIE_vidEnable(void)
{
	BIT_SET(SREG,SREG_I_BIT);
}
void GIE_vidDisable(void){

	BIT_CLEAR(SREG,SREG_I_BIT);
}
