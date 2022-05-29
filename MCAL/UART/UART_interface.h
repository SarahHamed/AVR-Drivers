/*
 * UART_interface.h
 *
 *  Created on: Feb 19, 2022
 *      Author: user
 */

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_vidSend(u8 data);
u8 UART_vdReceive();
void UART_vid_Initialize();

#endif /* MCAL_UART_UART_INTERFACE_H_ */
