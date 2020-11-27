/*
 * Keypad_Config.h
 *
 *  Created on: Nov 21, 2020
 *      Author: Abdelrahman
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_DIRECTION DDRC
#define KEYPAD_PORT PORTC
#define KEYPAD_PIN PINC

#define KEYPAD_OUTPUT_PINS {0,1,2,3}
#define KEYPAD_INPUT_PINS {4,5,6,7}

#define KEYPAD_MAP {{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'c','0','=','+'}}
#endif /* KEYPAD_CONFIG_H_ */
