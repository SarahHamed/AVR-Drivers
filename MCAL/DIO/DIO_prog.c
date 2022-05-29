/*
 * DIO_prog.c
 *
 *  Created on: ???/???/????
 *      Author: Administrator
 */


#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"

void DIO_voidSetPinDir(DIO_PORTS enuPortIdx_Cpy,DIO_PINS enuPinIdx_Cpy,DIO_Dir enuDir_Cpy)
{
	switch(enuPortIdx_Cpy)
	{
	case DIO_PORT_0:
		if(enuDir_Cpy==DIO_Inputs)
		{
			BIT_CLEAR(DDRA,enuPinIdx_Cpy);
		}
		else if(enuDir_Cpy==DIO_Output)
		{
			BIT_SET(DDRA,enuPinIdx_Cpy);
		}
		else
		{
			/* DO NOTHING */
		}
		break;
	case DIO_PORT_1:
		if(enuDir_Cpy==DIO_Inputs)
		{
			BIT_CLEAR(DDRB,enuPinIdx_Cpy);
		}
		else if(enuDir_Cpy==DIO_Output)
		{
			BIT_SET(DDRB,enuPinIdx_Cpy);
		}
		else
		{
			/* DO NOTHING */
		}
		break;
	case DIO_PORT_2:
		if(enuDir_Cpy==DIO_Inputs)
		{
			BIT_CLEAR(DDRC,enuPinIdx_Cpy);
		}
		else if(enuDir_Cpy==DIO_Output)
		{
			BIT_SET(DDRC,enuPinIdx_Cpy);
		}
		else
		{
			/* DO NOTHING */
		}
		break;
	case DIO_PORT_3:
		if(enuDir_Cpy==DIO_Inputs)
		{
			BIT_CLEAR(DDRD,enuPinIdx_Cpy);
		}
		else if(enuDir_Cpy==DIO_Output)
		{
			BIT_SET(DDRD,enuPinIdx_Cpy);
		}
		else
		{
			/* DO NOTHING */
		}
		break;
	}
}

void DIO_voidSetPinValue(DIO_PORTS enuPortIdx_Cpy,DIO_PINS enuPinIdx_Cpy,DIO_Value enuValue_Cpy)
{
	switch(enuPortIdx_Cpy)
		{
		case DIO_PORT_0:
			if(enuValue_Cpy==DIO_Low)
			{
				BIT_CLEAR(PORTA,enuPinIdx_Cpy);
			}
			else if(enuValue_Cpy==DIO_High)
			{
				BIT_SET(PORTA,enuPinIdx_Cpy);
			}
			else
			{
				/* DO NOTHING */
			}
			break;
		case DIO_PORT_1:
			if(enuValue_Cpy==DIO_Low)
			{
				BIT_CLEAR(PORTB,enuPinIdx_Cpy);
			}
			else if(enuValue_Cpy==DIO_High)
			{
				BIT_SET(PORTB,enuPinIdx_Cpy);
			}
			else
			{
				/* DO NOTHING */
			}
			break;
		case DIO_PORT_2:
			if(enuValue_Cpy==DIO_Low)
			{
				BIT_CLEAR(PORTC,enuPinIdx_Cpy);
			}
			else if(enuValue_Cpy==DIO_High)
			{
				BIT_SET(PORTC,enuPinIdx_Cpy);
			}
			else
			{
				/* DO NOTHING */
			}
			break;
		case DIO_PORT_3:
			if(enuValue_Cpy==DIO_Low)
			{
				BIT_CLEAR(PORTD,enuPinIdx_Cpy);
			}
			else if(enuValue_Cpy==DIO_High)
			{
				BIT_SET(PORTD,enuPinIdx_Cpy);
			}
			else
			{
				/* DO NOTHING */
			}
			break;
		}
}


void DIO_voidSetPortDir(DIO_PORTS enuPortIdx_Cpy,u8 u8Direction_Cpy)
{
	switch(enuPortIdx_Cpy)
	{
	case DIO_PORT_0:
		DDRA=u8Direction_Cpy;
		break;
	case DIO_PORT_1:
			DDRB=u8Direction_Cpy;
			break;
	case DIO_PORT_2:
			DDRC=u8Direction_Cpy;
			break;
	case DIO_PORT_3:
			DDRD=u8Direction_Cpy;
			break;

	}
}

void DIO_voidSetPortValue(DIO_PORTS enuPortIdx_Cpy,u8 u8Value_Cpy)
{
	switch(enuPortIdx_Cpy)
		{
		case DIO_PORT_0:
			PORTA=u8Value_Cpy;
			break;
		case DIO_PORT_1:
			PORTB=u8Value_Cpy;
			break;
		case DIO_PORT_2:
			PORTC=u8Value_Cpy;
			break;
		case DIO_PORT_3:
			PORTD=u8Value_Cpy;
			break;

		}
}

DIO_Value DIO_enuGetPinValue(DIO_PORTS enuPortIdx_Cpy,DIO_PINS enuPinIdx_Cpy)
{
	DIO_Value DIO_ValueValue_Loc;
	switch(enuPortIdx_Cpy)
			{
			case DIO_PORT_0:
				DIO_ValueValue_Loc=BET_GET(PINA,enuPinIdx_Cpy) ;
				break;
			case DIO_PORT_1:
				DIO_ValueValue_Loc=BET_GET(PINB,enuPinIdx_Cpy) ;
				break;
			case DIO_PORT_2:
				DIO_ValueValue_Loc=BET_GET(PINC,enuPinIdx_Cpy) ;
				break;
			case DIO_PORT_3:
				DIO_ValueValue_Loc=BET_GET(PIND,enuPinIdx_Cpy) ;
				break;
			}
return DIO_ValueValue_Loc;
	}
u8 DIO_u8GetPortValue(DIO_PORTS enuPortIdx_Cpy)
{
	u8 u8Value;
		switch(enuPortIdx_Cpy)
				{
				case DIO_PORT_0:
					u8Value=PINA ;
					break;
				case DIO_PORT_1:
					u8Value=PINB ;
					break;
				case DIO_PORT_2:
					u8Value=PINC ;
					break;
				case DIO_PORT_3:
					u8Value=PIND ;
					break;
				}
	return u8Value;
		}

//update Dec31
/*
 * u8 DIO_u8SetPortDirection(enum_port Copy_enuPort,enum_direction Copy_u8GeneralIO){

	switch(Copy_enuPort){
		case portA: DDRA=Copy_u8GeneralIO;break;
		case portB: DDRB=Copy_u8GeneralIO;break;
		case portC: DDRC=Copy_u8GeneralIO;break;
		case portD: DDRD=Copy_u8GeneralIO;break;
	}
}
 *
 */

/*
 * u8 DIO_u8SetPortValue(enum_port Copy_enuPort,enum_value Copy_u8GeneralValue){

		switch(Copy_enuPort){
			case portA: PORTA=Copy_u8GeneralValue;break;
			case portB: PORTB=Copy_u8GeneralValue;break;
			case portC: PORTC=Copy_u8GeneralValue;break;
			case portD: PORTD=Copy_u8GeneralValue;break;
		}
}
 *
 */
