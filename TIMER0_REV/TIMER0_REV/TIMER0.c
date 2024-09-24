/*
 * TIMER0.c
 *
 * Created: 9/24/2024 3:56:15 PM
 *  Author: aweka
 */ 

#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_config.h"
void Timer0_init()
{
	//configure Wave generation mode
	#if Mode == Fast_PWM
	  // MY_TCCR0 
	#elif Mode == CTC
	
	#endif
	//configure Clock_Select
	#if Clock_Select == Clock_64
			// MY_TCCR0 
	#endif
	
	//configure Compare_Output_Mode
	#if Compare_Output_Mode== Non_Inverting
	 // MY_TCCR0 
	#endif
}
void Timer0_SetOCR(unsigned char duty)
{
	// MY_OCR0 =duty
}