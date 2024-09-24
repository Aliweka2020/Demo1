/*
 * TIMER0_REV.c
 *
 * Created: 9/24/2024 3:55:44 PM
 *  Author: aweka
 */ 


#include <avr/io.h>
#include "TIMER0_Interface.h"
int main(void)
{
	Timer0_init();
	Timer0_SetOCR(125);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}