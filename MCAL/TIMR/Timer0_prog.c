/*
 * Timer_prog.c
 *
 *  Created on: Feb 5, 2022
 *      Author: user
 */

//	BIT_CLEAR(ADMUX,ADMUX_REFS1);
//	BIT_SET(ADMUX,ADMUX_REFS0);


#include "Timer0_register.h"
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "Timer0_config.h"


//#define mode

void TIMR0_VidPWMInit()
{
//#if pwm_timer0
//	/* Mode Fast PWM */
//	BIT_SET(TCCR0,TCCR0_WGM00);
//	BIT_SET(TCCR0,TCCR0_WGM01);
//
//	/* Set on top clear on compare */
//	BIT_CLEAR(TCCR0,TCCR0_COM00);
//	BIT_SET(TCCR0,TCCR0_COM01);
//
//	/*Set OCR0 value pre-build*/
//	OCR0 = OCR0_CONFG_VALUE;
//
//	/* Prescaler 64 */
//	BIT_SET(TCCR0,TCCR0_CS00);
//	BIT_SET(TCCR0,TCCR0_CS01);
//	BIT_CLEAR(TCCR0,TCCR0_CS02);
//#elif pwm_servo
	//Select fast pwm at wave generation mode
	//clear on compare match
	BIT_SET(TCCR1A,TCCR1A_COM1A1);
	BIT_CLEAR(TCCR1A,TCCR1A_COM1A0);
	//select fast pwm ICR1A
	BIT_CLEAR(TCCR1A,TCCR1A_WGM10);
	BIT_SET(TCCR1A,TCCR1A_WGM11);
	BIT_SET(TCCR1B,TCCR1B_WGM12);
	BIT_SET(TCCR1B,TCCR1B_WGM13);
	//set prescalar as 8
	BIT_CLEAR(TCCR1B,TCCR1B_CS10);
	BIT_SET(TCCR1B,TCCR1B_CS11);
	BIT_CLEAR(TCCR1B,TCCR1B_CS12);
//#endif
	}

// Post-build changing the value of OCR0
// ocr0 value controls the time on value

void TIMR0_vidSetOCR0( u8 cpy_u8ocr0Value )
{
	OCR0 = cpy_u8ocr0Value;
}

void TIMR_vidSetICR1A(u16 copy_u16PeriodCounts)
{
	ICR1L=copy_u16PeriodCounts;
}

void TIMR_vidSetOCR1AL(u16 copy_u16PeriodCounts)
{
	OCR1L=copy_u16PeriodCounts;
}

/* SET CTC */

/* Prescaler 64*/
