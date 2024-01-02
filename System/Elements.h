
#ifndef SYSTEM_ELEMENTS_H_
#define SYSTEM_ELEMENTS_H_

#define Heater_PIN			DIO_U8_PIN2
#define Heater_PORT			DIO_U8_PORTC

#define Cooler_PIN			DIO_U8_PIN3
#define Cooler_PORT			DIO_U8_PORTC

#define Heater_LED_PIN			DIO_U8_PIN4
#define Heater_LED_PORT			DIO_U8_PORTC

#define ON_PORT		DIO_U8_PORTD
#define ON_PIN		DIO_U8_PIN4



void Buttons_init();
void TurnOn_Heater();
void TurnOff_Heater();
void TurnOn_Cooler();
void TurnOff_Cooler();
void Elements_CheckAVG();
void Elements_Check();
void TurnOff_HeaterLed();
void TurnOn_HeaterLed();
void Toggle_HeaterLed();


#endif /* SYSTEM_ELEMENTS_H_ */
