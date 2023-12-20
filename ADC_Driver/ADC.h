/*
 * Analog to Digital Convertor Driver
 *
 *  Created on: Dec 15, 2023
 *      Author: https://github.com/IbrahimNaglah
 */

#ifndef ADC_DRIVER_ADC_H_
#define ADC_DRIVER_ADC_H_

//#define ADC0	0b00000
//#define ADC1	0b00001
//#define ADC2	0b00010
//#define ADC3	0b00011
//#define ADC4	0b00100
//#define ADC5	0b00101
//#define ADC6	0b00110
//#define ADC7	0b00111

#define D2		0b000
#define D4		0b010
#define D8		0b011
#define D16		0b100
#define D32		0b101
#define D64		0b110
#define D128	0b111


enum ADC_channel {
	ADC0=0,ADC1,ADC2,
	ADC3,ADC4,ADC5,ADC6,ADC7};

/*
 * Voltage_Reference_Selection Options:
 * VREF
 * VCC
 * Internal --> 2.5V
 */
#define Voltage_Reference_Selection		Internal





/*
ADC_Channel Options:

	 ADC0
	 ADC1
	 ADC2
	 ADC3
	 ADC4
	 ADC5
	 ADC6
	 ADC7
 */

//#define ADC_Channel	ADC0


/*
 * Division Factor Options:
	D2
	D4
	D16
	D32
	D64
	D128

	D128 is the only valid option
	16MHZ/128 = 125kHZ as ADC cannot handle more than 200kHZ
 */




#define Division_Factor	D128


void ADC_Init();
int ADC_Read(u8 ADC_Channel);


#endif /* ADC_DRIVER_ADC_H_ */
