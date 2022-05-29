/*
 * LCD_prog.c
 *
 *  Created on: ???/???/????
 *      Author: Administrator
 */
#include"../../lib/STD_TYPES.h"
#include"util/delay.h"
#include"../../MCAL/01-DIO/DIO_Interface.h"
#include"LCD_interface.h"
#include"LCD_config.h"

void LCD_voidWriteCommand(u8 u8Command_Cpy)
{
	/*Set RS->LOW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_Low);
	/*Set RW->LOW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_Low);
	/*Set E->LOW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_Low);
	/*Set Data Pins->Command*/
	DIO_voidSetPortValue(LCD_DATA_PORT , u8Command_Cpy);
	/*Set E->high*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_High);
	/*delay for 1ms*/
	_delay_ms(1);
	/*Set E->LOW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_Low);


}

void LCD_voidWriteData(u8 u8Data_Cpy)
{
	/*Set RS->High*/
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_High);
		/*Set RW->LOW*/
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_Low);
		/*Set E->LOW*/
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_Low);
		/*Set Data Pins->Data*/
		DIO_voidSetPortValue(LCD_DATA_PORT , u8Data_Cpy);
		/*Set E->high*/
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_High);
		/*delay for 1ms*/
		_delay_ms(1);
		/*Set E->LOW*/
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_Low);
}

void LCD_voidInitialize(void)
{
	_delay_ms(31);
	LCD_voidWriteCommand(0b00111000);
	_delay_ms(1);
	LCD_voidWriteCommand(0b00001100);
	_delay_ms(1);
	LCD_voidWriteCommand(0b00000001);
	_delay_ms(1);
}

void LCD_voidWriteString(u8 *pu8String_cpy,u8 size)
{
	u8 i=0;
	for(i=0;i<size;i++)
	{
		LCD_voidWriteData(pu8String_cpy[i]);
	}
}

void LCD_voidGoToXY(u8 pos_x,u8 pos_y)
{
	u8 Address=0;
	u8 pos=0;
	if(pos_y==0)
	{
		Address= pos_x+0x00;
	}
	else if(pos_y==1)
	{
		Address=pos_x+0x40;
	}
	else
	{/*doNothing*/}

	pos=Address+0b10000000;
	LCD_voidWriteCommand(pos);

	}
