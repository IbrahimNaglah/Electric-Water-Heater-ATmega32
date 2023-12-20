/************************************************/
/* Title       : Timer interface file           */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H


void TIMER0_Init(void);

void TIMER0_SetTCNT(u8 Copy_u8Val);

void TIMER0_SetOCR(u8 Copy_u8Val);

void TIMER0_EnableOVFInt(void);

void TIMER0_DisableOVFInt(void);

void TIMER0_EnableCTCInt(void);

void TIMER0_DisableCTCInt(void);

void PWM_Init();

#endif
