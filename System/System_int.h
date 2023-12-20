/*
 * System_int.h
 *
 *  Created on: Dec 20, 2023
 *      Author: https://github.com/IbrahimNaglah/Electric-Water-Heater-ATmega32
 */

#ifndef SYSTEM_SYSTEM_INT_H_
#define SYSTEM_SYSTEM_INT_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../Services/STD_Types.h"
#include "../Global_interrupt_driver/GIE_int.h"
#include "../DIO_Driver/DIO_int.h"
#include "../TIMER0_Driver/Timer_int.h"
#include "../SSEG_Driver/SSEG_int.h"
#include "../ADC_Driver/ADC.h"
#include "Temp_Settings.h"
#include "../I2C_Driver/I2C.h"
#include "EEPROM_Settings.h"
#include "Elements.h"

#define Default_Mode	0
#define SET_Mode		1

void INT0_init();
void INT1_init();

void EEPROM_init();
void EEPROM_SendByte(u8 EEPROM_ADD,u8 Storage_Location,u8 Data);
u8 EEPROM_ReadByte(u8 EEPROM_ADD,u8 Storage_Location);

#endif /* SYSTEM_SYSTEM_INT_H_ */
