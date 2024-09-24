/*
 * GccApplication24.c
 *
 * Created: 8/5/2024 7:13:15 PM
 *  Author: Ali
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
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
	
	LCD_init();
	ADC_init();
	_delay_ms(35);
	LCD_send_cmd(Function_Set8bit); 
	_delay_ms(1);
	LCD_send_cmd(Display_Cur_NoBlink);
	_delay_ms(1);
	LCD_send_cmd(LCD_Clear);
	_delay_ms(2);
	LCD_send_cmd(Entry_INC_NOshift);
	while(1)
	   {
        LCD_send_cmd(0x80);
		LCD_send_string("ADC = ");
		int temp = ADC_Read();
		int n =  temp/100;
		LCD_send_data(n + 0x30);
		temp = temp %100;
		n =  temp/10;
		LCD_send_data(n + 0x30);
		temp = temp %10;
		LCD_send_data(temp + 0x30);
 
 /*
		   for (int  i =0 ;i<16; i++)
		   {
			   
		LCD_send_cmd(0x80 + i);   
        LCD_send_data('A');
		_delay_ms(200);
		LCD_send_data('l');
		_delay_ms(200);
		LCD_send_data('i');
		_delay_ms(500);
		LCD_send_cmd(LCD_Clear);
		   }
		   */
		   /*
		   LCD_send_cmd(0x80);
		   unsigned char t = ADC_read();
		   t = t * (5000/1024);
		   display (t);
		*/
		
		
		
		
		//LCD_send_string("ALi");
		
    }
}
