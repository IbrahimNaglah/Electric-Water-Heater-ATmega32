/************************************************/
/* Title       : GIE Rrogram file               */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATH.h"
#include "GIE_int.h"
#include "GIE_priv.h"
#include "GIE_config.h"


void GIE_voidEnable(void)
{
	SET_BIT(SREG , I_BIT) ; // set I bit to enable the general interrupt enable
}


void GIE_voidDisable(void)
{
	
	CLEAR_BIT(SREG , I_BIT); // clear I bit to disable the general interrupt enable
}
