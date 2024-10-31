/*
 * MOTOR_PROGRAM.c
 *
 * Created: 27/10/2024 06:42:29 م
 *  Author: AdminOS
 */ 


#include "MOTOR_INTERFACE.h"

void L298N_Init(void) {
	DIO_u8_SetPinDirection(DIO_u8PORTD, IN1, DIO_u8Pin_Output);
	DIO_u8_SetPinDirection(DIO_u8PORTD, IN2, DIO_u8Pin_Output);
	DIO_u8_SetPinDirection(DIO_u8PORTD, ENA, DIO_u8Pin_Output);
	DIO_u8_SetPinDirection(DIO_u8PORTD, IN3, DIO_u8Pin_Output);
	DIO_u8_SetPinDirection(DIO_u8PORTD, IN4, DIO_u8Pin_Output);
	DIO_u8_SetPinDirection(DIO_u8PORTD, ENB, DIO_u8Pin_Output);
}

void MotorA_Forward(void) {
	DIO_u8_SetPinValue(DIO_u8PORTD, IN1, DIO_u8Pin_High);
	DIO_u8_SetPinValue(DIO_u8PORTD, IN2, DIO_u8Pin_Low);
	DIO_u8_SetPinValue(DIO_u8PORTD, ENA, DIO_u8Pin_High);
}

void MotorA_Backward(void) {
	DIO_u8_SetPinValue(DIO_u8PORTD, IN1, DIO_u8Pin_Low);
	DIO_u8_SetPinValue(DIO_u8PORTD, IN2, DIO_u8Pin_High);
	DIO_u8_SetPinValue(DIO_u8PORTD, ENA, DIO_u8Pin_High);
}

void MotorA_Stop(void) {
	DIO_u8_SetPinValue(DIO_u8PORTD, ENA, DIO_u8Pin_Low);
}

void MotorB_Forward(void) {
	DIO_u8_SetPinValue(DIO_u8PORTD, IN3, DIO_u8Pin_High);
	DIO_u8_SetPinValue(DIO_u8PORTD, IN4, DIO_u8Pin_Low);
	DIO_u8_SetPinValue(DIO_u8PORTD, ENB, DIO_u8Pin_High);
}

void MotorB_Backward(void) {
	DIO_u8_SetPinValue(DIO_u8PORTD, IN3, DIO_u8Pin_Low);
	DIO_u8_SetPinValue(DIO_u8PORTD, IN4, DIO_u8Pin_High);
	DIO_u8_SetPinValue(DIO_u8PORTD, ENB, DIO_u8Pin_High);
}

void MotorB_Stop(void) {
	DIO_u8_SetPinValue(DIO_u8PORTD, ENB, DIO_u8Pin_Low);
}

//ir sensor
u8 Read_Left_IR(void) {
	u8 value;
	DIO_u8_GetPinValue(DIO_u8PORTD, LEFT_IR, &value);
	return value;
}

u8 Read_Right_IR(void) {
	u8 value;
	DIO_u8_GetPinValue(DIO_u8PORTD, RIGHT_IR, &value);
	return value;
}