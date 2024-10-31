/*
 * DIO_interface.h
 *
 * Created: 10/25/2024 11:16:22 PM
 *  Author: fares
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
// Direction
u8 DIO_u8_SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
u8 DIO_u8_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

// Output
u8 DIO_u8_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 DIO_u8_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

// Input
u8 DIO_u8_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);


#endif /* DIO_INTERFACE_H_ */