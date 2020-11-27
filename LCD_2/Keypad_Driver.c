/*
 * Keypad_Driver.c
 *
 *  Created on: Nov 21, 2020
 *      Author: Abdelrahman
 */

#include "avr/io.h"
#include "avr/delay.h"
#include "Keypad_Config.h"
#include "stdlib.h"
#include "macros.h"

void Keypad_init(){

	char output[] = KEYPAD_OUTPUT_PINS;
	char input[] = KEYPAD_INPUT_PINS;
	int i=0;
	for(i=0;i<=3;i++){
		setBit(KEYPAD_DIRECTION,output[i]);
	}
	for(i=0;i<=3;i++){
			clearBit(KEYPAD_DIRECTION,input[i]);
		}
}

unsigned char Keypad_read(){
	int read =0,i,j;
	char output[] = KEYPAD_OUTPUT_PINS;
	char input[] = KEYPAD_INPUT_PINS;
	unsigned char keymap[4][4]=KEYPAD_MAP;
	for(i=0;i<=3;i++){
		clearBit(KEYPAD_PORT,output[i]);
	}
	while(read==0){
		for(i=0;i<=3;i++){
			setBit(KEYPAD_PORT,output[i]);
			for(j=0;j<=3;j++){
				if(readBit(KEYPAD_PIN,input[j])>=1){
					while(readBit(KEYPAD_PIN,input[j])>=1);
					clearBit(KEYPAD_PORT,output[i]);
					i=0;
					j=0;
					return keymap[i][j];
				}
				clearBit(KEYPAD_PORT,output[i]);
			}
		}
	}
}
