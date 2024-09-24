/*
 * TIMER0_REV.c
 *
 * Created: 9/24/2024 3:55:44 PM
 *  Author: aweka
 */ 

#include <util/delay.h>
#include <avr/io.h>
#include "TIMER0_Interface.h"
void ADC_init()
{
	DDRA &= ~(1<<0);
	ADMUX |= (1<<ADLAR);
	ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADPS2);
}
int ADC_Read()
{
	ADCSRA |= (1<<ADSC);
	while ( (ADCSRA & (1<<ADIF) ) ==0);
	ADCSRA |= (1<<ADIF);
	return ((int) (ADCH));
}
int main(void)
{
	ADC_init();
	Timer0_init();
	Timer0_SetOCR(1);
    while(1)
    {
		//int x=ADC_Read();
		Timer0_SetOCR(ADC_Read());
	/*	for (int i=0;i<255;i++)
		{
			Timer0_SetOCR(i);
			_delay_ms(100);
		}*/
       }
}