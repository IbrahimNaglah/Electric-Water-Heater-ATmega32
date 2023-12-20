#include "System_int.h"

/***************************************
 * APIs for UP - DOWN - ON/OFF Buttons

 -  Created on: Dec 20, 2023

 -      Author: https://github.com/IbrahimNaglah
 ***************************************/


#define Heater_PIN			DIO_U8_PIN2
#define Heater_PORT			DIO_U8_PORTC

#define Cooler_PIN			DIO_U8_PIN3
#define Cooler_PORT			DIO_U8_PORTC

int Curr_Temp, Set_Temp;

void Buttons_init()
{
	// Initialize OUTPUT
	DIO_voidSetPinDir(Heater_PORT,Heater_PIN,DIO_U8_OUTPUT);

	DIO_voidSetPinDir(Cooler_PORT,Cooler_PIN,DIO_U8_OUTPUT);

}


void TurnOn_Heater()
{
	DIO_voidSetPinVal(Heater_PORT, Heater_PIN, DIO_U8_HIGH);
}

void TurnOff_Heater()
{
	DIO_voidSetPinVal(Heater_PORT, Heater_PIN, DIO_U8_LOW);
}

void TurnOn_Cooler()
{
	DIO_voidSetPinVal(Cooler_PORT, Cooler_PIN, DIO_U8_HIGH);
}

void TurnOff_Cooler()
{
	DIO_voidSetPinVal(Cooler_PORT, Cooler_PIN, DIO_U8_LOW);
}

void Elements_Check()
{
	if(Set_Temp > Curr_Temp)
	{
		TurnOn_Heater();
		TurnOff_Cooler();
	}
	else if(Set_Temp < Curr_Temp)
	{
		TurnOn_Cooler();
		TurnOff_Heater();
	}
}
