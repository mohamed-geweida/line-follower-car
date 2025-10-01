#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>
#include "HAL/L298N/MOTOR_INTERFACE.h"

int main(void) {
	L298N_Init();

	while (1) {
		u8 left_ir = Read_Left_IR();
		u8 right_ir = Read_Right_IR();

		if (left_ir == 0 && right_ir == 0) {
			// Both sensors on the line
			MotorA_Forward();
			MotorB_Forward();
			} else if (left_ir == 0 && right_ir == 1) {
			// Left sensor on the line, right sensor off the line
			Turn_Left();
			} else if (left_ir == 1 && right_ir == 0) {
			// Left sensor off the line, right sensor on the line
			Turn_Right();
			} else {
			// Both sensors off the line
			MotorA_Stop();
			MotorB_Stop();
		}
	}
}

