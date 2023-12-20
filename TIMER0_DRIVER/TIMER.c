/*
 * TIMER Driver
 *
 *
 *  Created on: Dec 17, 2023
 *      Author: https://github.com/IbrahimNaglah
 */


#include "../Services/STD_Types.h"
#include "TIMER_private.h"

void PWM_Init()
{

	    // Set Fast PWM mode with non-inverted output on OC0
	    TCCR0 |= (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS02) | (1<<CS00); // No prescaler

	    // Set TOP value (255 for 8-bit PWM resolution)
	    // Output frequency = F_CPU / (N * 256), where N is the prescaler value
	    // For 50Hz at 16MHz with no prescaler: TOP = 312
	    OCR0 = 0; // 50% duty cycle for 8-bit PWM (TOP = 255)
}


