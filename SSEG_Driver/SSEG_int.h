/*
 * Seven_Segment Driver
 *
 *  Created on: Dec 18, 2023
 *      Author: https://github.com/IbrahimNaglah
 */

#ifndef SSEG_INT_H_
#define SSEG_INT_H_

#define DIO_SSEG1_PORT	DIO_U8_PORTB
#define DIO_SSEG2_PORT	DIO_U8_PORTB


#define SSEG1_PORT 	PORTB
#define SSEG2_PORT 	PORTB


#define SSEG_PINA DIO_U8_PIN0
#define SSEG_PINB DIO_U8_PIN1
#define SSEG_PINC DIO_U8_PIN2
#define SSEG_PIND DIO_U8_PIN3

#define SSEG_PINA2 DIO_U8_PIN4
#define SSEG_PINB2 DIO_U8_PIN5
#define SSEG_PINC2 DIO_U8_PIN6
#define SSEG_PIND2 DIO_U8_PIN7

/*
//Noting to use
#define Activate_SSEG1	DIO_U8_PIN0
#define Activate_SSEG2	DIO_U8_PIN2
#define Activation_PORT	PORTB
*/
/*
 * READ_MODE
 * for SSEG write 0
 * for LCD write 1
 */
#define Activate_PORT	DIO_U8_PORTA
#define Activate_PIN	DIO_U8_PIN7


void SSEG_voidInit(void);
void SSEG_voidDisplay(u8 SSEG_Num,u8 Data);
void SSEG_Toggle();
void SSEG_ACT();
void Send_Num_SSEG(int value);

#endif 
