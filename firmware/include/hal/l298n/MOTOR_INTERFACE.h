#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "mcal/dio/DIO_register.h"
#include "hal/l298n/MOTOR_DEFINITION.h"

void L298N_Init(void);
void MotorA_Forward(void);
void MotorA_Backward(void);
void MotorA_Stop(void);
void MotorB_Forward(void);
void MotorB_Backward(void);
void MotorB_Stop(void);
void Turn_Left(void);
void Turn_Right(void);

u8 Read_Left_IR(void);
u8 Read_Right_IR(void);

#endif /* MOTOR_INTERFACE_H_ */

