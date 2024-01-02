#include "System_int.h"

/***************************************
 * Heating and cooling elements

 -  Created on: Dec 20, 2023

 -      Author: https://github.com/IbrahimNaglah
 ***************************************/

int HeaterLed_Flag = 0;

char Curr_Temp,Data_Avg;
int Set_Temp;

int Off_State = 0;

void Buttons_init()
{
	// Initialize OUTPUT
	DIO_voidSetPinDir(Heater_PORT,Heater_PIN,DIO_U8_OUTPUT);

	DIO_voidSetPinDir(Cooler_PORT,Cooler_PIN,DIO_U8_OUTPUT);

	DIO_voidSetPinDir(Heater_LED_PORT,Heater_LED_PIN,DIO_U8_OUTPUT);

	TurnOff_Heater();
	TurnOff_Cooler();
	TurnOff_HeaterLed();


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

void Elements_CheckAVG()
{
	if(Set_Temp-5 > Data_Avg)
	{
		TurnOn_Heater();
		TurnOff_Cooler();
		HeaterLed_Flag = 1;
	}
	if(Set_Temp+5 < Data_Avg)
	{
		TurnOn_Cooler();
		TurnOff_Heater();
		HeaterLed_Flag = 0;
		TurnOn_HeaterLed();
	}


}

void Elements_Check()
{
	if(Set_Temp-5 > Curr_Temp)
	{
		TurnOn_Heater();
		TurnOff_Cooler();
		HeaterLed_Flag = 1;
	}
	if(Set_Temp+5 < Curr_Temp)
	{
		TurnOn_Cooler();
		TurnOff_Heater();
		HeaterLed_Flag = 0;
		TurnOn_HeaterLed();
	}
	else
	{
		TurnOff_Cooler();
		TurnOff_Heater();
	}


}

void TurnOn_HeaterLed()
{

	DIO_voidSetPinVal(Heater_LED_PORT, Heater_LED_PIN, DIO_U8_HIGH);
}

void TurnOff_HeaterLed()
{
	DIO_voidSetPinVal(Heater_LED_PORT, Heater_LED_PIN, DIO_U8_LOW);
}

void Toggle_HeaterLed()
{

	DIO_voidTogglePin(Heater_LED_PORT, Heater_LED_PIN);
}


