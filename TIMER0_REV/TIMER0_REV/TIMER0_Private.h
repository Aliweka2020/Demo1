/*
 * TIMER0_Private.h
 *
 * Created: 9/24/2024 3:57:38 PM
 *  Author: aweka
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#define MY_TCCR0   * ((volatile unsigned char *) 0x53)

 #define MY_OCR0  * ((volatile unsigned char *) 0x5C)
 #define  MY_TIMSK   * ((volatile unsigned char *) 0x59)


#endif /* TIMER0_PRIVATE_H_ */