/*
 * Inter_integrated_Circuit or Two_Wire_Interface Driver
 *
 *  Created on: Dec 14, 2023
 *      Author: https://github.com/IbrahimNaglah
 */


#ifndef I2C_PRIVAT_H_
#define I2C_PRIVAT_H_

#define TWCR *( ( volatile u8*) 0x56)
#define TWDR *( ( volatile u8*) 0x23)
#define TWAR *( ( volatile u8*) 0x22)
#define TWSR *( ( volatile u8*) 0x21)
#define TWBR *( ( volatile u8*) 0x20)

#define CRTL_TWI_INTERRUPT 			7	//TWINT
#define CRTL_TWI_EN_ACK 			6	//TWEA
#define CRTL_TWI_START				5	//TWSTA
#define CRTL_TWI_STOP				4	//TWSTO
#define CRTL_TWI_Write_Collision	3	//TWWC
#define CRTL_TWI_EN					2	//TWEN
#define CRTL_TWI_Interrupt_EN		0 	//TWIE


#endif
