/*
 * Timer0_interface.h
 *
 *  Created on: Feb 5, 2022
 *      Author: user
 */

#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

void Timer0_vidInit();
void TIMR0_VidPWMInit();
void TIMR0_vidSetOCR0( u8 cpy_u8ocr0Value );
void TIMR_vidSetICR1A(u16 copy_u16PeriodCounts);
void TIMR_vidSetOCR1AL(u16 copy_u16PeriodCounts);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
