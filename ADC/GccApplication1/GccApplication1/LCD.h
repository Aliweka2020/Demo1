/*
 * LCD.h
 *
 * Created: 8/15/2024 5:48:53 PM
 *  Author: aweka
 */ 


#ifndef LCD_H_
#define LCD_H_


typedef enum {FOUR, EIGHT}BITS;
typedef enum {A,B,C,D}PORTS;
#define LCD_DATA_PORT  C
#define LCD_CONTROL_PORT  B
#define RS 0
#define E 1
#define RW 2
#define LCD_BITS FOUR
#define Function_Set8bit 0x38
#define Display_NOCur_NoBlink 0x0c
#define Display_Cur_NoBlink 0x0E
#define LCD_Clear 0x01
#define Entry_INC_NOshift 0x06
#define Entry_DEC_NOshift 0x04

void LCD_init();
void LCD_send_cmd(unsigned char cmd);
void LCD_send_data(unsigned char data);



#endif /* LCD_H_ */