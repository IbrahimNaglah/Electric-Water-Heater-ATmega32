/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 05-11-2023            */
/*          Version: 1.0                */
/*          Module: DIO                 */
/****************************************/
#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_U8_PORTA 0
#define DIO_U8_PORTB 1
#define DIO_U8_PORTC 2
#define DIO_U8_PORTD 3

#define DIO_U8_PIN0 0 
#define DIO_U8_PIN1 1
#define DIO_U8_PIN2 2
#define DIO_U8_PIN3 3
#define DIO_U8_PIN4 4
#define DIO_U8_PIN5 5
#define DIO_U8_PIN6 6
#define DIO_U8_PIN7 7

#define DIO_U8_INPUT  0
#define DIO_U8_OUTPUT 1

#define DIO_U8_LOW  0
#define DIO_U8_HIGH 1

void DIO_voidSetPinDir(u8 Port, u8 Pin, u8 Direction);
void DIO_voidSetPinVal(u8 Port, u8 Pin, u8 Value);
u8 DIO_u8GetPinVal(u8 Port, u8 Pin);
void DIO_voidTogglePin(u8 Port , u8 Pin);
void DIO_voidSetPortValue(u8 DIO_u8Port, u8 DIO_u8Value);

#endif
