/*
 * TIMER0.h
 *
 * Created: 9/24/2024 3:56:25 PM
 *  Author: aweka
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/// modes
#define Normal    0
#define CTC       1
#define Fast_PWM  2
#define Phase_PWM 3


//Clock Select
#define Clock_1  0
#define Clock_8  0
#define Clock_64  0
#define Clock_256  0
#define Clock_1024  0

//Compare Output Mode
#define Inverting     0
#define Non_Inverting 1

void Timer0_init();
void Timer0_SetOCR(unsigned char duty);



#endif /* TIMER0_H_ */