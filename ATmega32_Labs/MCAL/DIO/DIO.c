/*
 * dio.c
 *
 *  Created on: Oct 10, 2022
 *      Author: ak
 */


/* Here we write:
 * inclusion of header files.h
 * global variables
 * function definitions
 */

#include "DIO.h"

void DIO_init (unint8_t portNumber, unint8_t pinNumber, unint8_t direction)
{
	switch (portNumber)
	{
	case PORT_A:
		if (direction == OUT)
			DDRA |= (1<<pinNumber);	//set bit (pin)

		else if (direction == IN)
			DDRA &= ~(1<<pinNumber);
		else;
			// Error Handling
	break;

	case PORT_B:
			if (direction == OUT)
				DDRB |= (1<<pinNumber);	//set bit (pin)

			else if (direction == IN)
				DDRB &= ~(1<<pinNumber); //clear bit

			else;
				// Error Handling
		break;

	case PORT_C:
			if (direction == OUT)
				DDRC |= (1<<pinNumber);	//set bit (pin)

			else if (direction == IN)
				DDRC &= ~(1<<pinNumber);

			else;
				// Error Handling
		break;

	case PORT_D:
			if (direction == OUT)
				DDRD |= (1<<pinNumber);	//set bit (pin)

			else if (direction == IN)
				DDRD &= ~(1<<pinNumber);

			else;
				// Error Handling
		break;
	}
}

void DIO_write (unint8_t portNumber, unint8_t pinNumber, unint8_t value)
{
	switch (portNumber)
	{
	case PORT_A:
		if (value == HIGH)
			PORTA |= (1<<pinNumber);	//High

		else if (value == LOW)
			PORTA &= ~(1<<pinNumber); //Low
		else;
			// Error Handling
	break;

	case PORT_B:
			if (value == HIGH)
				PORTB |= (1<<pinNumber);	//High

			else if (value == LOW)
				PORTB &= ~(1<<pinNumber);  //Low

			else;
				// Error Handling
		break;

	case PORT_C:
			if (value == HIGH)
				PORTC |= (1<<pinNumber);	//High

			else if (value == LOW)
				PORTC &= ~(1<<pinNumber);  //Low

			else;
				// Error Handling
		break;

	case PORT_D:
			if (value == HIGH)
				PORTD |= (1<<pinNumber);//High

			else if (value == LOW)
				PORTD &= ~(1<<pinNumber); //Low

			else;
				// Error Handling
		break;
	}
}
void DIO_toggle (unint8_t portNumber, unint8_t pinNumber)

switch (portNumber)
	{
	case PORT_A:
		if (value == HIGH)
			PORTA ^= (1<<pinNumber);	//High

		else if (value == LOW)
			PORTA &= ~(1<<pinNumber); //Low
		else;
			// Error Handling
	break;

	case PORT_B:
			if (value == HIGH)
				PORTB |= (1<<pinNumber);	//High

			else if (value == LOW)
				PORTB &= ~(1<<pinNumber);  //Low

			else;
				// Error Handling
		break;

	case PORT_C:
			if (value == HIGH)
				PORTC |= (1<<pinNumber);	//High

			else if (value == LOW)
				PORTC &= ~(1<<pinNumber);  //Low

			else;
				// Error Handling
		break;

	case PORT_D:
			if (value == HIGH)
				PORTD |= (1<<pinNumber);//High

			else if (value == LOW)
				PORTD &= ~(1<<pinNumber); //Low

			else;
				// Error Handling
		break;
	}
}


void DIO_read (uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
    switch (portNumber) 
	{
        
	case PORT_A:
        
		*value = ( PINA & (1<<pinNumber) ) >> pinNumber; 
        
    break;
    
    case PORT_B:
        
		*value = ( PINB & (1<<pinNumber) ) >> pinNumber; 
        
    break;
    
    case PORT_C:
        
		*value = ( PINC & (1<<pinNumber) ) >> pinNumber; 
        
    break;
    
    case PORT_D:
        
		*value = ( PIND & (1<<pinNumber) ) >> pinNumber; 
        
    break;
}

}
