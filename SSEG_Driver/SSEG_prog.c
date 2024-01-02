/*
 * Seven_Segment Driver
 *
 *  Created on: Dec 18, 2023
 *      Author: https://github.com/IbrahimNaglah
 */


#include "../DIO_Driver/DIO_private.h"
#include "../Services/STD_types.h"
#include "../Services/BIT_math.h"
#include "../DIO_Driver/DIO_int.h"
#include "SSEG_int.h"


void SSEG_voidInit(void)
{
//	DIO_voidSetPinDir(Activation_PORT,Activate_SSEG1,DIO_U8_OUTPUT);
//	DIO_voidSetPinDir(Activation_PORT,Activate_SSEG2,DIO_U8_OUTPUT);

	//First Left
	DIO_voidSetPinDir(DIO_SSEG1_PORT,SSEG_PINA,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_SSEG1_PORT,SSEG_PINB,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_SSEG1_PORT,SSEG_PINC,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_SSEG1_PORT,SSEG_PIND,DIO_U8_OUTPUT);


	//Second Right
	DIO_voidSetPinDir(DIO_SSEG2_PORT,SSEG_PINA2,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_SSEG2_PORT,SSEG_PINB2,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_SSEG2_PORT,SSEG_PINC2,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_SSEG2_PORT,SSEG_PIND2,DIO_U8_OUTPUT);

	DIO_voidSetPinDir(Activate_PORT,Activate_PIN,DIO_U8_OUTPUT);


}

void SSEG_voidDisplay(u8 SSEG_Num,u8 Data)
{

	if(SSEG_Num==1)
	{


	DIO_voidSetPinVal(DIO_SSEG1_PORT,SSEG_PINA,GET_BIT((Data),0));
	DIO_voidSetPinVal(DIO_SSEG1_PORT,SSEG_PINB,GET_BIT((Data),1));
	DIO_voidSetPinVal(DIO_SSEG1_PORT,SSEG_PINC,GET_BIT((Data),2));
	DIO_voidSetPinVal(DIO_SSEG1_PORT,SSEG_PIND,GET_BIT((Data),3));
	}

	if(SSEG_Num==2)
	{

	DIO_voidSetPinVal(DIO_SSEG2_PORT,SSEG_PINA2,GET_BIT((Data),0));
	DIO_voidSetPinVal(DIO_SSEG2_PORT,SSEG_PINB2,GET_BIT((Data),1));
	DIO_voidSetPinVal(DIO_SSEG2_PORT,SSEG_PINC2,GET_BIT((Data),2));
	DIO_voidSetPinVal(DIO_SSEG2_PORT,SSEG_PIND2,GET_BIT((Data),3));
	}

}

void SSEG_Toggle()
{

	DIO_voidTogglePin(Activate_PORT,Activate_PIN);
}

void SSEG_ACT()
{

	DIO_voidSetPinVal(Activate_PORT,Activate_PIN,DIO_U8_HIGH);
}

void SSEG_DACT()
{
	DIO_voidSetPinVal(Activate_PORT,Activate_PIN,DIO_U8_LOW);
}

void Send_Num_SSEG(int value)
{

	int Right_Digit,Left_Digit;

	Right_Digit = ((int)value)%10;
	Left_Digit = ((int)value)/10;
	SSEG_voidDisplay(1,(u8)Left_Digit);
	SSEG_voidDisplay(2,(u8)Right_Digit);

}
