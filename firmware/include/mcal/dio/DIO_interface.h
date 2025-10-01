#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "lib/STD_TYPES.h"

u8 DIO_u8_SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
u8 DIO_u8_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

u8 DIO_u8_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 DIO_u8_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 DIO_u8_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);

#endif /* DIO_INTERFACE_H_ */

