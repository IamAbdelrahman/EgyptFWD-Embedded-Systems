/*
 * dio.h
 *
 *  Created on: Oct 10, 2022
 *      Author: ak
 */

/* Here we write :-
 * type definitions
 * Macros
 * Functions prototypes
 */

#ifndef DIO_DRIVERS_DIO_H_
#define DIO_DRIVERS_DIO_H_
#include "../../Utilities/Registers.h"
#include "../../Utilities/Types.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Directions defines
#define IN 0
#define OUT 1

// Value defines
#define LOW 0
#define HIGH 1

void DIO_init (unint8_t portNumber, unint8_t pinNumber, unint8_t direction);	//initialize dio pins

void DIO_write (unint8_t portNumber, unint8_t pinNumber, unint8_t value); //write data on dio pins

void DIO_toggle (unint8_t portNumber, unint8_t pinNumber); //toggle dio pins

void DIO_read (unint8_t portNumber, unint8_t pinNumber, unint8_t* value); //read dio pins

#endif /* DIO_DRIVERS_DIO_H_ */
