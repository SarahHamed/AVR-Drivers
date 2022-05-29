/*
 * DIO_interface.h
 *
 *  Created on: ???/???/????
 *      Author: Administrator
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include"../../lib/STD_TYPES.h"

typedef enum
{
	DIO_PORT_0,
	DIO_PORT_1,
	DIO_PORT_2,
	DIO_PORT_3
}DIO_PORTS;

typedef enum
{
	DIO_PIN_0,
	DIO_PIN_1,
	DIO_PIN_2,
	DIO_PIN_3,
	DIO_PIN_4,
	DIO_PIN_5,
	DIO_PIN_6,
	DIO_PIN_7,
}DIO_PINS;

typedef enum
{
DIO_Inputs,
DIO_Output
}DIO_Dir;

/* updated DEC31
typedef enum {
	pinInput,
	pinOutput,
	generalio,
	portOutput=0xff,
	portInput=0x00
}enum_direction;


typedef enum{
	pinLow,
	pinHigh,
	portLow  =0x00,
	portHigh =0xff

}enum_value;
*/
typedef enum
{
DIO_Low,
DIO_High
}DIO_Value;


/*
description:
Inputs:
Outputs:
*/
void DIO_voidSetPinDir(DIO_PORTS enuPortIdx_Cpy,DIO_PINS enuPinIdx_Cpy,DIO_Dir enuDir_Cpy);
void DIO_voidSetPinValue(DIO_PORTS enuPortIdx_Cpy,DIO_PINS enuPinIdx_Cpy,DIO_Value enuValue_Cpy);
void DIO_voidSetPortDir(DIO_PORTS enuPortIdx_Cpy,u8 u8Direction_cpy);
//updated DEC31 u8 DIO_u8SetPortDirection(enum_port Copy_enuPort, enum_direction Copy_u8GeneralIO);
void DIO_voidSetPortValue(DIO_PORTS enuPortIdx_Cpy,u8 u8Value_cpy);
//updated DEC31 u8 DIO_u8SetPortValue(enum_port Copy_enuPort, enum_value Copy_u8GeneralValue);
DIO_Value DIO_enuGetPinValue(DIO_PORTS enuPortIdx_Cpy,DIO_PINS enuPinIdx_Cpy);
u8 DIO_u8GetPortValue(DIO_PORTS enuPortIdx_Cpy);
#endif /* DIO_INTERFACE_H_ */
