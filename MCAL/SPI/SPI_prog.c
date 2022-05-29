/*
 * SPI_prog.c
 *
 *  Created on: Feb 25, 2022
 *      Author: user
 */

#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "SPI_register.h"
#include "SPI_interface.h"

/*
void SPI_vidMasterInit(void)
{
	//data order MSB
	BIT_CLEAR(SPCR,SPCR_DORD);
	//SET AS MASTER
	BIT_SET(SPCR,SPCR_MSTR);
	// CLK PAHSE AND POLARTY
	BIT_CLEAR(SPCR,SPCR_CPOL);
	BIT_CLEAR(SPCR,SPCR_CPHA);
	//SPI2X SPR1 SPR0


}


void SPI_vidSlaveInit(void)
{

}


u8 SPI_u8Transceive(void)
{

	return 0;
}
*/




void SPI_Init(u8 mode)
{
	// Set mode master or slave
	if(mode==1)
		BIT_SET(SPCR,SPCR_MSTR);
	else if(mode==0)
		BIT_CLEAR(SPCR,SPCR_MSTR);

	//	//polarity
	BIT_SET(SPCR,SPCR_CPOL);
	//	//phase
	BIT_SET(SPCR,SPCR_CPHA);
	//least sig bit (data order)
	BIT_SET(SPCR,SPCR_DORD);
	//select clk
	BIT_SET(SPSR,SPSR_SPI2X);
	BIT_SET(SPCR,SPCR_SPR1);
	BIT_SET(SPCR,SPCR_SPR0);
	//enable spi
	BIT_SET(SPCR,SPCR_SPE);
}


u8 SPI_Transmit(u8 data)
{
	SPDR = data;
	while(!(BET_GET(SPSR,SPSR_SPIF)) );
	BIT_SET(SPSR,SPSR_SPIF);
	return SPDR;
}

