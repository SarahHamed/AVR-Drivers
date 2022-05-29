#include "UART_register.h"
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"

//	BIT_CLEAR(TCCR0,TCCR0_COM00);
//	BIT_SET(TCCR0,TCCR0_COM01);

void UART_vidSend(u8 data)
{
	while(BET_GET(UCSRA,UCSRA_UDRE)==0);
	UDR=data;
	}


u8 UART_vdReceive()
{
	while(BET_GET(UCSRA,UCSRA_RXC)==0);

	return UDR;
}

void UART_vid_Initialize()
{


	u8 my_ucsrc=0;
	//8 bit data
	BIT_CLEAR(UCSRB,UCSRB_UCSZ2);
	BIT_SET(my_ucsrc,UCSRC_UCSZ1);
	BIT_SET(my_ucsrc,UCSRC_UCSZ0);


	//use reg UCSRC
	BIT_SET(my_ucsrc,UCSRC_URSEL);
	//Asynch
	BIT_CLEAR(my_ucsrc,UCSRC_UMSEL);
	// no parity mode
	BIT_CLEAR(my_ucsrc,UCSRC_UPM1);
	BIT_CLEAR(my_ucsrc,UCSRC_UPM0);



	// one stop bit
	BIT_CLEAR(my_ucsrc,UCSRC_USBS);
	UCSRC=my_ucsrc;
	//use reg UBRRH
	//BIT_CLEAR(UCSRC,UCSRC_URSEL);
	UBRRL=51;
	//enable rec and trans
	BIT_SET(UCSRB,UCSRB_RXEN);
	BIT_SET(UCSRB,UCSRB_TXEN);
}
