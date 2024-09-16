/*
 * Master.c
 *
 * Created: 9/1/2024 4:50:02 PM
 *  Author: aweka
 */ 


#include <avr/io.h>
#include <util/delay.h>
void Master_init()
{
	DDRB |=(1<<4) | (1<<5) | (1<<7); 
	DDRB &=~ (1<<6); 
	SPCR |=(1<<SPE) | (1<<MSTR);
}
void Master_send(unsigned char data)
{
	SPDR  =  data;
	while((SPSR & (1<<SPIF))==0);
	//SPSR |=(1<<SPIF);
}

int main(void)
{
	Master_init();
    while(1)
    {
       // Local Uodate 2
			Master_send ('D');
			_delay_ms(1000);
			Master_send (11);
			_delay_ms(1000);
		//By Habib Tarek at 16/9/2024 
    }
}