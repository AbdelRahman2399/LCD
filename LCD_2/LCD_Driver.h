/*
 * LCD_Driver.h
 *
 *  Created on: Nov 20, 2020
 *      Author: Islam
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

void LCD_init(void);
void LCD_writeCommand(void (*pfun) (void));
void LCD_setMode(void);
void LCD_clearDisplay(void);
void LCD_displayOn(void);
void LCD_enable(void);
void LCD_disable(void);
void LCD_writeChar(char c);

#endif /* LCD_DRIVER_H_ */
