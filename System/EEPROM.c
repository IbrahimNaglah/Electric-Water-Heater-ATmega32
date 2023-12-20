/*
 * Used to Manage EEPROM Storage
 *
 *  Created on: Dec 19, 2023
 *      Author: https://github.com/IbrahimNaglah
 */




#include "System_int.h"



void EEPROM_init()
{
	I2C_init();
	EEPROM_SendByte(EEPROM_SET_ADD,EEPROM_INITIAL_SET_ADD,Initial_Set_Temp);
}

void EEPROM_SendByte(u8 EEPROM_ADD,u8 Storage_Location,u8 Data)
{
	I2C_start();
	I2C_Write(EEPROM_ADD);
	I2C_Write(Storage_Location);
	I2C_Write(Data);
	I2C_Stop();
}

u8 EEPROM_ReadByte(u8 EEPROM_ADD,u8 Storage_Location)
{
	u8 Stored_Data;
	I2C_start();

	I2C_Write(EEPROM_ADD);
	I2C_Write(Storage_Location);

	I2C_Repeated_Start();

	I2C_Write(EEPROM_ADD+1);

	Stored_Data = I2C_Read_Nack();
	I2C_Stop();

	return Stored_Data;
}
