/*
 * I2C_prog.c
 *
 *  Created on: ???/???/????
 *      Author: Administrator
 */
#include "AVR_I2C_REG.h"
#include"STD_TYPES.h"
#include"BIT_MATH.h"

void I2C_Init()
{
	TWBR=72;	//0x48
	TWAR=(10<<1);

	TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWEA);
	TWSR = 0x00;

		BIT_CLEAR(TWSR,TWSR_TWPS0);
		BIT_CLEAR(TWSR,TWSR_TWPS1);

/*
	 TWSR = 0x00;
	    TWBR = 0x0C;
	    //enable TWI
	    TWCR =(1<<TWCR_TWEN);*/
}
void Start()
{
	TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);
	while(BET_GET(TWCR,TWCR_TWINT)==0);
}

void Stop()
{
	TWCR=1<<TWCR_TWINT|1<<TWCR_TWSTO|1<<TWCR_TWEN;
}

void Send_SLA(u8 SLA,u8 ReadOrWrite)
{
	TWDR=(SLA<<1)|ReadOrWrite;
	TWCR=1<<TWCR_TWINT|1<<TWCR_TWEN;
	while(BET_GET(TWCR,TWCR_TWINT)==0);
}

void Send_Data(u8 Data)
{
	TWDR=Data;
	TWCR=1<<TWCR_TWINT|1<<TWCR_TWEN;
	while(BET_GET(TWCR,TWCR_TWINT)==0);
}

u8 Read_WithAck()
{
	TWCR=1<<TWCR_TWINT|1<<TWCR_TWEN|1<<TWCR_TWEA;
	while(BET_GET(TWCR,TWCR_TWINT)==0);
	return TWDR;
}

u8 Read_WithNotAck()
{
	TWCR=1<<TWCR_TWINT|1<<TWCR_TWEN|1;
	while(BET_GET(TWCR,TWCR_TWINT)==0);
	return TWDR;
}

u8 Get_Status()
{
	return TWSR&(0xF8);
}

