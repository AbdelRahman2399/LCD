/*
 * main.c
 *
 *  Created on: Nov 20, 2020
 *      Author: Islam
 */
#include"stdlib.h"
#include "LCD_Driver.h"

int main()
{

	LCD_init();
	LCD_writeChar('H');
	LCD_writeChar('I');
	while(1){
		unsigned char c= Keypad_read();
		LCD_writeChar(c);
	}
	return 0;

}
