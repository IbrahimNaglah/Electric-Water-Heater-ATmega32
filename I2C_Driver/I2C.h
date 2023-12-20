/*
 * Inter_integrated_Circuit or Two_Wire_Interface Driver
 *
 *  Created on: Dec 14, 2023
 *      Author: https://github.com/IbrahimNaglah
 */

#ifndef I2C_H_
#define I2C_H_

/*Options:
 * 0b0000	-->	prescaler = 1
 * 0b0001	-->	prescaler = 4
 * 0b0010	--> prescaler = 16
 * 0b0011	--> prescaler = 64
 */

#define TWI_PRESCALER 0b0000

#define SCL_CLK 9600
#define BITRATE(TWSR)	( (F_CPU/SCL_CLK)-16) /(2*4^(TWSR&((1<<0)|(1<<1))) )

void I2C_init();
void I2C_start ();
void I2C_Repeated_Start();
void I2C_Write(u8 Data);
void I2C_WriteString(char* Data);
u8 I2C_Read_Aack();
u8 I2C_Read_Nack();
void I2C_Stop();


#endif
