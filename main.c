#include "System/System_int.h"

int TimerCounter = 0;
int Flag_1ms = 0, Flag_1Sec = 0, Back_to_Default = 0, Def_Count = 0;
int mode = Default_Mode;


int Curr_Temp = 0;
int Set_Temp = Initial_Set_Temp;


ISR(INT0_vect) { // Up Button
	TimerCounter = 0; Def_Count = 0;
	mode = SET_Mode;
	if(Set_Temp < Max_Temp)
		Set_Temp += 5;
}

ISR(INT1_vect) { // Down Button
	TimerCounter = 0; Def_Count = 0;
	mode = SET_Mode;
	if(Min_Temp < Set_Temp)
		Set_Temp -= 5;
}

ISR(TIMER0_OVF_vect)
{
	TimerCounter++;
	if(TimerCounter == 6 && mode == Default_Mode ) // 100ms
		{TimerCounter = 0; Curr_Temp = ADC_Read(0)/2;}
	if(TimerCounter == 30 && mode == SET_Mode)
		{
		Flag_1Sec = 1; TimerCounter = 0;
		if(Def_Count == 5)
			{ Back_to_Default = 1; mode = Default_Mode; SSEG_ACT();}
		 Def_Count ++;
		}

}


int main() {
    // Initialize INT0 and INT1
    INT0_init();
    INT1_init();
	ADC_Init();
	SSEG_voidInit();
	Buttons_init();
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
    				Elements_Check();
    			break;

    		case SET_Mode:
    			Send_Num_SSEG(Set_Temp);
    			if(Flag_1Sec == 1){SSEG_Toggle(); Flag_1Sec = 0; }
    			if(Back_to_Default == 1){ Back_to_Default = 0;}
    	}
    }

    return 0;
}
