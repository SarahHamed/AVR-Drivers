/*
 * ADC_prog.c
 *
 *  Created on: Feb 4, 2022
 *      Author: user
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "ADC_register.h"

#define ADC0	0

void ADC_init()
{
	//Select VCC Reference Voltage
	BIT_CLEAR(ADMUX,ADMUX_REFS1);
	BIT_SET(ADMUX,ADMUX_REFS0);

	//Select left adjustement
	BIT_SET(ADMUX,ADMUX_ADLAR);

	//Select Prescaler 128
	BIT_SET(ADCSRA,ADCSRA_ADPS2);
	BIT_SET(ADCSRA,ADCSRA_ADPS1);

	//EN ADC
	BIT_SET(ADCSRA,ADCSRA_ADEN);

}

u8 ADC_u8channel_select(u8 cpy_channel)
{
	//Select Channel/
	/*
	if(cpy_channel == ADC0){
	BIT_CLEAR(ADMUX,ADMUX_MUX4);
	BIT_CLEAR(ADMUX,ADMUX_MUX3);
	BIT_CLEAR(ADMUX,ADMUX_MUX2);
	BIT_CLEAR(ADMUX,ADMUX_MUX1);
	BIT_CLEAR(ADMUX,ADMUX_MUX0);
	}
	*/
	ADMUX &= 0b1110000;
	ADMUX |= cpy_channel;
	//Start conversion
	BIT_SET(ADCSRA,ADCSRA_ADSC);

	//Busy waiting
	while(BET_GET(ADCSRA,ADCSRA_ADIF)!=1);

	BIT_CLEAR(ADCSRA,ADCSRA_ADIF); // l mafrod 2ktb 1

	return ADCH;

}
