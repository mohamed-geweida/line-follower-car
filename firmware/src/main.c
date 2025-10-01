#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>

#include "hal/l298n/MOTOR_INTERFACE.h"

int main(void) {
    L298N_Init();

    while (1) {
        u8 left_ir = Read_Left_IR();
        u8 right_ir = Read_Right_IR();

        if (left_ir == 0 && right_ir == 0) {
            MotorA_Forward();
            MotorB_Forward();
        } else if (left_ir == 0 && right_ir == 1) {
            Turn_Left();
        } else if (left_ir == 1 && right_ir == 0) {
            Turn_Right();
        } else {
            MotorA_Stop();
            MotorB_Stop();
        }
    }
}


