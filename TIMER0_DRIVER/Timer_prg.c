
#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATH.h"
#include "Timer_int.h"
#include "Timer_priv.h"
#include "Timer_config.h"

void TIMER0_Init(void)
{
	#if(TIMER0_MODE == TIMER0_NORMAL)
		CLEAR_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_CTC)
		CLEAR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER0_FAST_PWM )
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER0_PHASE_PWM )
		SET_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
		
	#endif

	#if(TIMER0_COM_EVENT == TIMER0_NO_ACTION)
	CLEAR_BIT(TCCR0 , 4);
	CLEAR_BIT(TCCR0 , 5);
	
	
	#elif(TIMER0_COM_EVENT == TIMER0_TOGGLE)
	SET_BIT(TCCR0 , 4)
	CLEAR_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_CLEAR )
	CLEAR_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_SET )
	SET_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);

	
	#endif
	
	#if(TIMER0_PRESCALER == TIMER0_DIV_BY_1)
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_8)
		CLEAR_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_64 )
		SET_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_256 )
		CLEAR_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_1024 )
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
		
	#endif
}

void TIMER0_SetTCNT(u8 Copy_u8Val)
{
	TCNT0 = Copy_u8Val ;
}

void TIMER0_SetOCR(u8 Copy_u8Val)
{
	OCR0 = Copy_u8Val ;
}

void TIMER0_EnableOVFInt(void)
{
	SET_BIT(TIMSK , 0);
}

void TIMER0_DisableOVFInt(void)
{
	CLEAR_BIT(TIMSK , 0);
}

void TIMER0_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 1);
}
