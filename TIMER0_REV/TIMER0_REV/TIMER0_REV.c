/*
 * TIMER0_REV.c
 *
 * Created: 9/24/2024 3:55:44 PM
 *  Author: aweka
 */ 

#include <util/delay.h>
#include <avr/io.h>
#include "TIMER0_Interface.h"
int main(void)
{
	Timer0_init();
	Timer0_SetOCR(1);
    while(1)
    {
		for (int i=0;i<255;i++)
		{
			Timer0_SetOCR(i);
			_delay_ms(100);
		}
       }
}