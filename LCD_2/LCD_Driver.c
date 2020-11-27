/*
 * LCD_Driver.c
 *
 *  Created on: Nov 20, 2020
 *      Author: Islam
 */
#include"stdlib.h"
#include"avr/io.h"
#include"avr/delay.h"
#include "macros.h"
#include "LCD_cfg.h"
#include "LCD_Driver.h"

void LCD_init(void){
	LCD_CONTROL_DIRECTION = 0xFF;
	LCD_DATA_DIRECTION = 0xFF;
	LCD_DATA_PORT = 0x00;
	LCD_CONTROL_PORT = 0x00;
	LCD_writeCommand(LCD_setMode);
	LCD_writeCommand(LCD_clearDisplay);
	LCD_writeCommand(LCD_displayOn);

}

void LCD_writeCommand(void (*pfun) (void)){
	clearBit(LCD_CONTROL_PORT,LCD_RW_PIN);
	_delay_ms(1);
	LCD_enable();
	_delay_ms(1);
	pfun();
	LCD_disable();
}

void LCD_writeChar(char c){
	char a=c;
	clearBit(LCD_CONTROL_PORT,LCD_RW_PIN);
	setBit(LCD_CONTROL_PORT,LCD_RS_PIN);
	_delay_ms(1);
	LCD_enable();
	_delay_ms(1);
	LCD_DATA_PORT = a;
	a=(a<<4);
	LCD_DATA_PORT = a;
	_delay_ms(1);
	LCD_disable();
}


void LCD_setMode(void){
	LCD_DATA_PORT = 0x00;
	char a = 0b00101010;
#if LCD_DATA_MODE == FOUR
    setBit(LCD_DATA_PORT,LCD_DB5_PIN);
	clearBit(LCD_DATA_PORT,LCD_DB4_PIN);
	setBit(LCD_DATA_PORT,LCD_DB7_PIN);
#endif
}

void LCD_clearDisplay(void){

	LCD_DATA_PORT = 0x00;
	setBit(LCD_DATA_PORT,LCD_DB7_PIN);

}

void LCD_displayOn(void){

	LCD_DATA_PORT = 0x00;
	setBit(LCD_DATA_PORT,LCD_DB7_PIN);
	setBit(LCD_DATA_PORT,LCD_DB6_PIN);
	setBit(LCD_DATA_PORT,LCD_DB5_PIN);
	setBit(LCD_DATA_PORT,LCD_DB4_PIN);

}

void LCD_enable(void){

	setBit(LCD_CONTROL_PORT,LCD_E_PIN);

}

void LCD_disable(void){

	clearBit(LCD_CONTROL_PORT,LCD_E_PIN);

}
