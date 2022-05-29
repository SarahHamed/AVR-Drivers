/*
 * SPI_register.h
 *
 *  Created on: Feb 25, 2022
 *      Author: user
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

//SPCR
//SPSR


#define SPCR *((u8*)0x2D)
#define SPSR *((u8*)0x2E)
#define SPDR *((u8*)0x2F)

//SPCR
#define SPCR_SPIE 7
#define SPCR_SPE 6
#define SPCR_DORD 5
#define SPCR_MSTR 4
#define SPCR_CPOL 3
#define SPCR_CPHA 2
#define SPCR_SPR1 1
#define SPCR_SPR0 0


//SPSR
#define SPSR_SPIF 7
#define SPSR_WCOL 6
#define SPSR_SPI2X 0


//SPDR
#define SPDR_MSB 7
#define SPDR_LSB 0



#endif /* MCAL_SPI_SPI_REGISTER_H_ */
