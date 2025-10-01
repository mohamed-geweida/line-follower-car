/* DIO implementation (ported) */
#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "mcal/dio/DIO_interface.h"
#include "mcal/dio/DIO_register.h"

u8 DIO_u8_SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    u8 Local_u8ErrorState = 0;
    if ((Copy_u8Pin <= DIO_u8Pin7) && (Copy_u8Pin >= DIO_u8Pin0))
    {
        if (Copy_u8Direction == DIO_u8Pin_Output)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
                case DIO_u8PORTB: SET_BIT(DDRB, Copy_u8Pin); break;
                case DIO_u8PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
                case DIO_u8PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        }
        else if (Copy_u8Direction == DIO_u8Pin_Input)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: CLR_BIT(DDRA, Copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(DDRB, Copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(DDRC, Copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(DDRD, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        }
        else
        {
            Local_u8ErrorState = 1;
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}

u8 DIO_u8_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    u8 Local_u8ErrorState = 0;
    if ((Copy_u8Direction == DIO_u8Pin_Output) || (Copy_u8Direction == DIO_u8Pin_Input))
    {
        switch (Copy_u8Port)
        {
            case DIO_u8PORTA: DDRA = Copy_u8Direction; break;
            case DIO_u8PORTB: DDRB = Copy_u8Direction; break;
            case DIO_u8PORTC: DDRC = Copy_u8Direction; break;
            case DIO_u8PORTD: DDRD = Copy_u8Direction; break;
            default: Local_u8ErrorState = 1;
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}

u8 DIO_u8_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    u8 Local_u8ErrorState = 0;
    if ((Copy_u8Pin <= DIO_u8Pin7) && (Copy_u8Pin >= DIO_u8Pin0))
    {
        if (Copy_u8Value == DIO_u8Pin_High)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
                case DIO_u8PORTB: SET_BIT(PORTB, Copy_u8Pin); break;
                case DIO_u8PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
                case DIO_u8PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        }
        else if (Copy_u8Value == DIO_u8Pin_Low)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: CLR_BIT(PORTA, Copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(PORTB, Copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(PORTC, Copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(PORTD, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        }
        else
        {
            Local_u8ErrorState = 1;
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}

u8 DIO_u8_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    u8 Local_u8ErrorState = 0;
    if ((Copy_u8Value == DIO_u8Port_High) || (Copy_u8Value == DIO_u8Port_Low))
    {
        switch (Copy_u8Port)
        {
            case DIO_u8PORTA: PORTA = Copy_u8Value; break;
            case DIO_u8PORTB: PORTB = Copy_u8Value; break;
            case DIO_u8PORTC: PORTC = Copy_u8Value; break;
            case DIO_u8PORTD: PORTD = Copy_u8Value; break;
            default: Local_u8ErrorState = 1;
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}

u8 DIO_u8_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
    u8 Local_u8ErrorState = 0;
    if ((Copy_u8Pin <= DIO_u8Pin7) && (Copy_u8Pin >= DIO_u8Pin0) && (Copy_pu8Value != NULL))
    {
        switch (Copy_u8Port)
        {
            case DIO_u8PORTA: *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin); break;
            case DIO_u8PORTB: *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin); break;
            case DIO_u8PORTC: *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin); break;
            case DIO_u8PORTD: *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin); break;
            default: Local_u8ErrorState = 1;
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}


