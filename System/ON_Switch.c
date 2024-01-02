/*
 * ON_Switch.c
 *
 *  Created on: Dec 26, 2023
 *      Author: HP
 */

#include "System_int.h"

#define ON_PIN		DIO_U8_PIN4
#define ON_PORT		DIO_U8_PORTD

void ON_Switch_Init()
{
	DIO_voidSetPinDir(ON_PORT, ON_PIN, DIO_U8_INPUT);

}

int System_Status(void)
{
	static int status = 1;
	if (PIND & (1 << ON_PIN))
	{
        _delay_ms(30); // Debounce delay
        if (PIND & (1 << ON_PIN)) {
            if(status == 1)	status = 0;
            else if(status == 0) status = 1;
        }
	}
	return status;
}

