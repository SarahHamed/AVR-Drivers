
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define Mode Master
#define Master 1
#define Slave 0

void SPI_Init(u8 mode);
u8 SPI_Transmit(u8 data);


#endif /* MCAL_SPI_SPI_REGISTER_H_ */
