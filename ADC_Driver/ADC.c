/*
 * Analog to Digital Convertor Driver
 *
 *  Created on: Dec 15, 2023
 *      Author: https://github.com/IbrahimNaglah
 */

#include "../Services/STD_Types.h"
#include "../Services/BIT_MATH.h"
#include "ADC_Private.h"
#include "ADC.h"

void ADC_Init()
{
	//Division Factor
	ADCSRA |= Division_Factor;
	SET_BIT(ADCSRA,ADEN); //Enable ADC

//Choose Vref for ADC
#if (Voltage_Reference_Selection == VREF)
	CLEAR_BIT(ADMUX,REFS1);
	CLEAR_BIT(ADMUX,REFS0);
#elif (Voltage_Reference_Selection == VCC)
	CLEAR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#elif (Voltage_Reference_Selection == Internal)
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#endif

}


int ADC_Read(u8 ADC_Channel)
{
	int ADCH_Data,ADCL_Data;

	ADMUX = ADMUX|ADC_Channel;

	SET_BIT(ADCSRA,ADSC);
	while((ADCSRA&(1<<ADIF)) == 0);

	//Storing Data process
	ADCL_Data = (int)ADCL;
	ADCH_Data = (int)ADCH<<8;

	ADCH_Data += ADCL_Data;

	return ADCH_Data;
}
