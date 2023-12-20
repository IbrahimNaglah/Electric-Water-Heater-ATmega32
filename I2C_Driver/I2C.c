/*
 * Inter_integrated_Circuit or Two_Wire_Interface Driver
 *
 *  Created on: Dec 14, 2023
 *      Author: https://github.com/IbrahimNaglah
 */

#include "../Services/STD_Types.h"
#include "I2C_privat.h"
#include "I2C.h"
#include "../Global_interrupt_driver/GIE_int.h"

void I2C_init()
{
	TWBR = BITRATE(TWSR = TWI_PRESCALER);
	GIE_voidEnable();
}


void I2C_start ()
{
	u8 status;

	TWCR = (1<<CRTL_TWI_START) | (1 << CRTL_TWI_INTERRUPT) | (1<<CRTL_TWI_EN);  //Enable TWI, generate START

	while ((TWCR&(1<<CRTL_TWI_INTERRUPT)) == 0); // Wait until TWI finish its current job
	status = TWSR & 0xF8; // Read TWI status register

//	if(status != 0x08) // Check weather START transmitted or not
//		return 0; // Return 0 to indicate start condition fail
//
//	return 1;

}

void I2C_Repeated_Start()
{
	u8 status;

	TWCR = (1<<CRTL_TWI_START) | (1 << CRTL_TWI_INTERRUPT) | (1<<CRTL_TWI_EN);  //Enable TWI, generate START

	while ((TWCR&(1<<CRTL_TWI_INTERRUPT)) == 0); // Wait until TWI finish its current job
	status = TWSR & 0xF8; // Read TWI status register
//
//	if(status != 0x10) // Check weather Repeated START transmitted or not
//		return 0; // Return 0 to indicate start condition fail
//
//	return 1;
}


void I2C_Write(u8 Data)
{
	u8 status;
	TWDR = Data;

	TWCR = (1 << CRTL_TWI_INTERRUPT) | (1<<CRTL_TWI_EN);  //Enable TWI & clear interrupt flag

	while ((TWCR&(1<<CRTL_TWI_INTERRUPT)) == 0); // Wait until TWI finish its current job
	status = TWSR & 0xF8; // Read TWI status register

//	if(status == 0x28)
//		return 0; //Return 0 to indicate Ack received
//	if(status == 0x30)
//		return 1; //Return 1 to indicate Nack received
//	else
//		return 2;
}

void I2C_WriteString(char* Data)
{
	for(int i = 0; Data[i] != '\0';i++)
	{
		I2C_Write(Data[i]);
	}

}

u8 I2C_Read_Aack()
{
	TWCR = (1<<CRTL_TWI_INTERRUPT) | (1<<CRTL_TWI_EN_ACK) | (1<<CRTL_TWI_EN); //Generate Ack
	while(!(TWCR&(1<<CRTL_TWI_INTERRUPT)));

	return TWDR;
}

u8 I2C_Read_Nack()		/* I2C read nack function */
{
    TWCR=(1<<CRTL_TWI_EN)|(1<<CRTL_TWI_INTERRUPT);
    while(!(TWCR&(1<<CRTL_TWI_INTERRUPT)));
    return TWDR;		/* Return received data */
}

void I2C_Stop()			/* I2C stop function */
{
    TWCR=(1<<CRTL_TWI_STOP)|(1<<CRTL_TWI_INTERRUPT)|(1<<CRTL_TWI_EN);/* Enable TWI, generate stop */
    //while(TWCR&(1<<CRTL_TWI_STOP));	/* Wait until stop condition execution */
}



