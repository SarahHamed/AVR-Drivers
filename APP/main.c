/*
 * main.c
 *
 *  Created on: Feb 4, 2022
 *      Author: user
 */

#include "../lib/BIT_MATH.h"
#include "../lib/STD_TYPES.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "util/delay.h"
#include "../MCAL/01-DIO/AVR_DIO_REG.h"

int main()
{

	//(RXD) PD0
	//(TXD) PD1
	DIO_voidSetPinDir(DIO_PORT_3,DIO_PIN_0,DIO_Inputs);
	DIO_voidSetPinDir(DIO_PORT_3,DIO_PIN_1,DIO_Output);
	//to led
	DIO_voidSetPinDir(DIO_PORT_0,DIO_PIN_0,DIO_Output);
	DIO_voidSetPinDir(DIO_PORT_0,DIO_PIN_1,DIO_Output);

	UART_vid_Initialize();

	UART_vidSend('c');
	 while(1){
		 if(UART_vdReceive()=='a')
			 DIO_voidSetPinValue(DIO_PORT_0,DIO_PIN_0,DIO_High);
		 else if(UART_vdReceive()=='b')
			 DIO_voidSetPinValue(DIO_PORT_0,DIO_PIN_0,DIO_Low);
	}

}
