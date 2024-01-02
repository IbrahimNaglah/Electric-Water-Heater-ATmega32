#include "System/System_int.h"

///EEPROM Related Stuff
char Stored_Temp[10] = {'1','2','3','4','5','6','7','8','9','A'};
char EEPROM_Index_Location = 0x0B;
int  EEPROM_Index = 0;
int EEPROM_Index2 = 0;

///************************************
/// Author: https://github.com/IbrahimNaglah
/// *******************************

///Timer related stuff
int TimerCounter = 0, TimerCounter2 = 0;
int Flag_1ms = 0, Flag_1Sec = 0, Back_to_Default = 0, Def_Count = 0;
int mode = Default_Mode;
///************************************

///Temperature Related Stuff
char Curr_Temp = 0;//Current Temperature measured by Temperature sensor
char Total_Curr_Temp = 0; //
char Total_NumOf_Temp = 0;
char Data_Avg = 0; //Data Average = Curr_Temp/Division
char Division=0; // Total Number of Data

int Set_Temp = Initial_Set_Temp; //Set Temperature by user which defaults is 60

int HeaterLed_Flag; // Heater led depends on flag
///*************************************


ISR(INT0_vect) { /// Up Button interrupt
	TimerCounter = 0; Def_Count = 0;
	mode = SET_Mode;
	if(Set_Temp < Max_Temp)
		Set_Temp += 5;
}

ISR(INT1_vect) { /// Down Button interrupt
	TimerCounter = 0; Def_Count = 0;
	mode = SET_Mode;
	if(Min_Temp < Set_Temp)
		Set_Temp -= 5;
}

ISR(TIMER0_OVF_vect)
{
	TimerCounter++;TimerCounter2++;
	if(TimerCounter == 6 && mode == Default_Mode) // 100ms
		{
		TimerCounter = 0;

		if(Total_NumOf_Temp<=10)	{Total_NumOf_Temp ++;}
		else	{Total_NumOf_Temp = 1;	Total_Curr_Temp = 0;}

		Curr_Temp = ADC_Read(0)/2;
		Total_Curr_Temp += Curr_Temp;
		Data_Avg = Total_Curr_Temp/Total_NumOf_Temp;
		}

//	if(TimerCounter2 == 30 )
//		{if(HeaterLed_Flag ==1) Toggle_HeaterLed(); TimerCounter2 = 0;}

	if(TimerCounter == 30 && mode == SET_Mode)
		{
		Flag_1Sec = 1; TimerCounter = 0;
		if(Def_Count == 5)
			{ Back_to_Default = 1; mode = Default_Mode; SSEG_ACT();
			EEPROM_SendByte(EEPROM_SET_ADD, Stored_Temp[EEPROM_Index], Set_Temp);}
		 Def_Count ++;
		}

}


int main() {
    // All Initializations
    INT0_init();
    INT1_init();
	ADC_Init();
	SSEG_voidInit();
	Buttons_init();
	ON_Switch_Init();
	TIMER0_Init();
	TIMER0_SetTCNT(197);
	TIMER0_EnableOVFInt(); //Enable Timer0 interrupt
	// Enable global interrupts
    GIE_voidEnable();

    while (1)
    {

    		switch(mode)
    		{
    			case Default_Mode:
    				if(Curr_Temp <= Max_Temp && Curr_Temp >= Min_Temp)
    					Send_Num_SSEG(Curr_Temp);
    				break;

    			case SET_Mode:
    				Send_Num_SSEG(Set_Temp);

    				if(Flag_1Sec == 1){SSEG_Toggle(); Flag_1Sec = 0; }
    				if(Back_to_Default == 1){ Back_to_Default = 0;
    				EEPROM_Index++; EEPROM_Index2++;
    				if(EEPROM_Index == 10)
    					EEPROM_Index = 0; EEPROM_Index2 = 9;}
    				break;
    		}
    	Elements_Check();
    }


    return 0;
}
