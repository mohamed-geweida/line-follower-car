/* L298N HAL implementation (ported) */
#include "hal/l298n/MOTOR_INTERFACE.h"
#include "mcal/dio/DIO_interface.h"

void L298N_Init(void) {
    DIO_u8_SetPinDirection(DIO_u8PORTD, IN1, DIO_u8Pin_Output);
    DIO_u8_SetPinDirection(DIO_u8PORTD, IN2, DIO_u8Pin_Output);
    DIO_u8_SetPinDirection(DIO_u8PORTD, IN3, DIO_u8Pin_Output);
    DIO_u8_SetPinDirection(DIO_u8PORTD, IN4, DIO_u8Pin_Output);
}

void MotorA_Forward(void) {
    DIO_u8_SetPinValue(DIO_u8PORTD, IN2, DIO_u8Pin_High);
    DIO_u8_SetPinValue(DIO_u8PORTD, IN1, DIO_u8Pin_Low);
}

void MotorA_Backward(void) {
    DIO_u8_SetPinValue(DIO_u8PORTD, IN1, DIO_u8Pin_Low);
    DIO_u8_SetPinValue(DIO_u8PORTD, IN2, DIO_u8Pin_High);
}

void MotorA_Stop(void) {
    DIO_u8_SetPinValue(DIO_u8PORTD, IN1, DIO_u8Pin_Low);
    DIO_u8_SetPinValue(DIO_u8PORTD, IN2, DIO_u8Pin_Low);
}

void MotorB_Forward(void) {
    DIO_u8_SetPinValue(DIO_u8PORTD, IN3, DIO_u8Pin_High);
    DIO_u8_SetPinValue(DIO_u8PORTD, IN4, DIO_u8Pin_Low);
}

void MotorB_Backward(void) {
    DIO_u8_SetPinValue(DIO_u8PORTD, IN3, DIO_u8Pin_Low);
    DIO_u8_SetPinValue(DIO_u8PORTD, IN4, DIO_u8Pin_High);
}

void MotorB_Stop(void) {
    DIO_u8_SetPinValue(DIO_u8PORTD, IN3, DIO_u8Pin_Low);
    DIO_u8_SetPinValue(DIO_u8PORTD, IN4, DIO_u8Pin_Low);
}

void Turn_Left(void){
    MotorA_Forward();
    MotorB_Stop();
}
void Turn_Right(void){
    MotorB_Forward();
    MotorA_Stop();
}

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


