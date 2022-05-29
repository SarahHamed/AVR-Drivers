/*
 * I2C_interface.h
 *
 *  Created on: ???/???/????
 *      Author: Administrator
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_Init();
void Start();
void Stop();
void Send_SLA(u8 SLA,u8 ReadOrWrite);
void Send_Data(u8 Data);
u8 Read_WithAck();
u8 Read_WithNotAck();
u8 Get_Status();

#endif /* I2C_INTERFACE_H_ */
