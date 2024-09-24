/*
 * TIMER0.c
 *
 * Created: 9/24/2024 3:56:15 PM
 *  Author: aweka
 */ 
#include <avr/io.h>
#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_config.h"
void Timer0_init()
{
	DDRB |=(1<<3);
	//configure Wave generation mode
	#if Mode == Fast_PWM
	   MY_TCCR0 |=(1<<WGM01)|(1<<WGM00);
	#elif Mode == CTC
	
	#endif
	//configure Clock_Select
	#if Clock_Select == Clock_64
			MY_TCCR0 |=(1<<CS01)|(1<<CS00);
	#endif
	
	//configure Compare_Output_Mode
	#if Compare_Output_Mode== Non_Inverting
	 MY_TCCR0 |=(1<<COM01) ;
	#endif
}
void Timer0_SetOCR(unsigned char duty)
{
	MY_OCR0 =duty;
}