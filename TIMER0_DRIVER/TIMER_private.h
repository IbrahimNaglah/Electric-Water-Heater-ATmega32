/*
 * TIMER Private file
 *	DO NOT EDIT
 *
 *  Created on: Dec 17, 2023
 *      Author: https://github.com/IbrahimNaglah
 */


#ifndef _TIMER_PRIV
#define _TIMER_PRIV


/************************************************
 *					 TIMER 0
 *
 ***********************************************/

#define TIMSK (*(volatile u8 * )0x59)
#define OCR0 (*(volatile u8 * )0x5C)
#define TCCR0 (*(volatile u8 * )0x53)
#define TCNT0 (*(volatile u8 * )0x52)
#define TIFR (*(volatile u8 * )0x58)

//////////////////////////////////////////
/*Bits Inside Register*/

#define FOC0 	7
#define WGM00 	6
#define COM01 	5
#define COM00 	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0

#define OCIE0 	1
#define TOIE0 	0

#define OCF0 	1
#define TOV0	0

///////////////////////////////////////


#define TIMER0_NORMAL 		1
#define TIMER0_CTC 			2
#define TIMER0_FAST_PWM 	3
#define TIMER0_PHASE_PWM 	4

#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			5
#define TIMER0_DIV_BY_64		8
#define TIMER0_DIV_BY_256		10
#define TIMER0_DIV_BY_1024		15


#define TIMER0_NO_ACTION	100
#define TIMER0_TOGGLE		12
#define TIMER0_SET			20
#define TIMER0_CLEAR		25

/************************************************
 *					 TIMER 1
 *
 ***********************************************/
/*
#define TCCR1A
#define TCCR1B

#define TCNT1H
#define TCNT1L

#define OCR1AH
#define OCR1AL

#define OCR1BH
#define OCR1BL

#define ICR1H
#define ICR1L
*/

//Bits inside Register
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define	WGM11	1
#define WGM10	0

#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11	1
#define CS10	0

#define	TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2

#define ICF1	5
#define OCF1A	4
#define OCF1B	3
#define TOV1	2

#endif
