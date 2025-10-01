Architecture Overview

Layers

- LIB: Generic utilities (`STD_TYPES.h`, `BIT_MATH.h`). No MCU dependencies beyond basic types/macros.
- MCAL: Microcontroller Abstraction Layer for ATmega32 DIO. Exposes typed APIs and register mappings.
- HAL: Hardware Abstraction for L298N driver and IR sensors. Depends on MCAL.
- APP: `main.c` orchestrates behavior: initialize HAL, read sensors, command motors.

Data flow

IR sensors on PD6/PD7 -> HAL `Read_*_IR()` -> `main.c` decision -> HAL motor functions -> MCAL DIO -> registers.

Portability

- Swap pin mappings in `HAL/L298N/MOTOR_DEFINITION.h`.
- For different MCUs, replace `MCAL/DIO` implementation while keeping the same interface.
