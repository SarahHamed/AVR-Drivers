/*
 * WDT_interface.h
 *
 *  Created on: Feb 18, 2022
 *      Author: user
 */

#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define sleep_time_prescalar	6

void WDT_vidSetTimer(u8 time);

void WDT_vidEn();

void WDT_vidDisable();

// l mafrod n3ml enum ll prescalar

typedef enum
{
	time_0,
	time_1,
	time_2,
	time_3,
	time_4,
	time_5,
	time_6,
	time_7,
}sleep_time;



#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
