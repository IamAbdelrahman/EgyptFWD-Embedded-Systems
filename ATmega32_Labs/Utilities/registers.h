/*
 * Registers.h
 *
 *  Created on: Oct 10, 2022
 *      Author: ak
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

/* PORT A Registers */

#define PORTA *((volatile unint8_t*)0x3B)	//8-bit register
#define DDRA *((volatile unint8_t*)0x3A)	//8-bit register
#define PINA *((volatile unint8_t*)0x39)	//8-bit register

/* PORT B Registers */

#define PORTB *((volatile unint8_t*)0x38)	//8-bit register
#define DDRB *((volatile unint8_t*)0x37)	//8-bit register
#define PINB *((volatile unint8_t*)0x36)	//8-bit register

/* PORT C Registers */

#define PORTC *((volatile unint8_t*)0x35)	//8-bit register
#define DDRC *((volatile unint8_t*)0x34)	//8-bit register
#define PINC *((volatile unint8_t*)0x33)	//8-bit register

/* PORT D Registers */

#define PORTD *((volatile unint8_t*)0x32)	//8-bit register
#define DDRD *((volatile unint8_t*)0x31)	//8-bit register
#define PIND *((volatile unint8_t*)0x30)	//8-bit register

#endif /* REGISTERS_H_ */
