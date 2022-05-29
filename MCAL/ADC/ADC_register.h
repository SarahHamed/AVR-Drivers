/*
 * ADC_register.h
 *
 *  Created on: Feb 4, 2022
 *      Author: user
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX	*((volatile u8*)0x27)

//if they are set to 1 1 means internal 2.56 voltage
#define	ADMUX_REFS1		7
#define	ADMUX_REFS0		6

// left adj or right adj
#define	ADMUX_ADLAR		5

#define	ADMUX_MUX4		4
#define	ADMUX_MUX3		3
#define	ADMUX_MUX2		2
#define	ADMUX_MUX1		1
#define	ADMUX_MUX0		0

#define ADCSRA	*((volatile u8*)0x26)

#define ADCSRA_ADEN		7
#define ADCSRA_ADSC		6
#define ADCSRA_ADATE	5
#define ADCSRA_ADIF		4
#define ADCSRA_ADIE		3
#define ADCSRA_ADPS2	2
#define ADCSRA_ADPS1	1
#define ADCSRA_ADPS0	0


#define SFIOR	*((volatile u8*)0x50)

#define SFIOR_ADTS2		7
#define SFIOR_ADTS1		6
#define SFIOR_ADTS0		5
#define SFIOR_ACME		3
#define SFIOR_PUD		2
#define SFIOR_PSR2		1
#define SFIOR_PSR10		0


#define ADCH	*((volatile u8*)0x25)

typedef enum
{
	channel_0=0b00000,
	channel_1=0b00001,
	channel_2=0b00010,
	channel_3=0b00011,
	channel_4=0b00100,
	channel_5=0b00101,
	channel_6=0b00110,
	channel_7=0b00111
}channel;



#endif /* MCAL_ADC_ADC_REGISTER_H_ */
