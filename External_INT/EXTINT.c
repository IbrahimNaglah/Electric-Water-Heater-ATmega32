/*
 * EXTINT.c
 *
 *  Created on: Dec 20, 2023
 *      Author: HP
 */


#include "../System/System_int.h"

void INT0_init() {
    // Set INT0 (PD2) as input with internal pull-up resistor
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    // Configure external interrupt INT0 settings
    MCUCR |= (1 << ISC01); // Trigger INT0 on falling edge
    GICR |= (1 << INT0);  // Enable INT0 interrupt
}

void INT1_init() {
    // Set INT1 (PD3) as input with internal pull-up resistor
    DDRD &= ~(1 << PD3);
    PORTD |= (1 << PD3);

    // Configure external interrupt INT1 settings
    MCUCR |= (1 << ISC11); // Trigger INT1 on rising edge
    GICR |= (1 << INT1);  // Enable INT1 interrupt
}


