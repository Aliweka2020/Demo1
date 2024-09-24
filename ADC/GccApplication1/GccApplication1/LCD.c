/*
 * LCD.c
 *
 * Created: 8/15/2024 5:48:36 PM
 *  Author: aweka
 */ 
#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
LCD_send_string(char *s)
{
	while(*s != '\0')
	{
		LCD_send_data(*s);
		s++;
	}
}
void LCD_init()
{
	if(LCD_DATA_PORT == A)
		DDRA = 0xFF;
	else if(LCD_DATA_PORT == B)
		DDRB = 0xFF;
	else if(LCD_DATA_PORT == C)
		DDRC = 0xFF;
	else if(LCD_DATA_PORT == D)
		DDRD = 0xFF;
		
	if (LCD_CONTROL_PORT == A)
	{
		DDRA |= (1<<RS) | (1<<E) | (1<<RW);
	}
	else if (LCD_CONTROL_PORT == B)
	{
		DDRB |= (1<<RS) | (1<<E)| (1<<RW);
	}
	else if (LCD_CONTROL_PORT == C)
	{
		DDRC |= (1<<RS) | (1<<E)| (1<<RW);
	}
	else if (LCD_CONTROL_PORT == D)
	{
		DDRD |= (1<<RS) | (1<<E)| (1<<RW);
	}
	
}
void LCD_send_cmd(unsigned char cmd)
{
	
	PORTB &= ~(1<<RS);
	PORTB &= ~(1<<RW);
	
		
	PORTC =  cmd;
	
	PORTB |=(1<<E);
	_delay_ms(1);
	PORTB &=~(1<<E);
	_delay_ms(1);
	
	
		
		/*
		PORTA = (PORTA & 0x0F) |  (cmd & 0xF0);
		// E latch
		PORTB |= (1<<E);
		_delay_ms(1);
		PORTB &= ~(1<<E);
		_delay_ms(1);
		
		PORTA = (PORTA & 0x0F) | cmd <<4;
		// E latch
		PORTB |= (1<<E);
		_delay_ms(1);
		PORTB &= ~(1<<E);
		_delay_ms(2);
	*/
	
}
void LCD_send_data(unsigned char data)
{
	PORTB |= (1<<RS);   //RS =1
	PORTB &= ~(1<<RW);
	
		
			
			PORTC =  data;
			
			PORTB |=(1<<E);
			_delay_ms(1);
			PORTB &=~(1<<E);
			_delay_ms(1);
		
		
			
		/*	
			PORTA = (PORTA & 0x0F) | (data & 0xF0);
			// E latch
			PORTB |= (1<<E);
			_delay_ms(1);
			PORTB &= ~(1<<E);
			_delay_ms(1);
			
			PORTA = (PORTA & 0x0F) | data <<4;
			// E latch
			PORTB |= (1<<E);
			_delay_ms(1);
			PORTB &= ~(1<<E);
			_delay_ms(1);
		*/
}