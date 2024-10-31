/*
 * DIO_register.h
 *
 * Created: 10/25/2024 11:16:05 PM
 *  Author: fares
 */ 

#include "C:\Users\AdminOS\Desktop\driver\GccApplication1\GccApplication1\LIB\STD_TYPES.h"

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

// Ports And Pins
#define DIO_u8PORTA   0
#define DIO_u8PORTB   1
#define DIO_u8PORTC   2
#define DIO_u8PORTD   3

#define DIO_u8Pin0   0
#define DIO_u8Pin1   1
#define DIO_u8Pin2   2
#define DIO_u8Pin3   3
#define DIO_u8Pin4   4
#define DIO_u8Pin5   5
#define DIO_u8Pin6   6
#define DIO_u8Pin7   7

// Direction
#define DIO_u8Pin_Input   0
#define DIO_u8Pin_Output  1

#define DIO_u8Port_Input   0
#define DIO_u8Port_Output  0xff

// Values
#define DIO_u8Pin_Low   0
#define DIO_u8Pin_High  1

#define DIO_u8Port_Low   0
#define DIO_u8Port_High  0xff

// Register of direction of pins
#define DDRA *( (volatile u8*) 0x3A )
#define DDRB *( (volatile u8*) 0x37 )
#define DDRC *( (volatile u8*) 0x34 )
#define DDRD *( (volatile u8*) 0x31 )

// Register of output pins value
#define PORTA *( (volatile u8*) 0x3B )
#define PORTB *( (volatile u8*) 0x38 )
#define PORTC *( (volatile u8*) 0x35 )
#define PORTD *( (volatile u8*) 0x32 )

// Register of input pins value
#define PINA *( (volatile u8*) 0x39 )
#define PINB *( (volatile u8*) 0x36 )
#define PINC *( (volatile u8*) 0x33 )
#define PIND *( (volatile u8*) 0x30 )

#endif /* DIO_REGISTER_H_ */