Line Follower (AVR ATmega32)

[![Build](https://img.shields.io/badge/build-make-brightgreen)](#build)
[![Toolchain](https://img.shields.io/badge/toolchain-avr--gcc-blue)](#build)
[![MCU](https://img.shields.io/badge/mcu-ATmega32-orange)](#pinout)
[![Language](https://img.shields.io/badge/language-C-9cf)](#)
[![License](https://img.shields.io/badge/license-MIT-lightgrey)](#)

A simple line-following robot firmware built for AVR ATmega32 using Atmel Studio toolchain. It uses an L298N driver to control two DC motors and two IR sensors for line detection.

Structure

```
firmware/
  include/
    lib/            # Common headers (types, bit ops)
    mcal/dio/       # DIO interfaces and register maps
    hal/l298n/      # L298N interfaces and pin definitions
  src/
    main.c          # Application entry point
    mcal/dio/       # DIO implementation
    hal/l298n/      # L298N implementation

GccApplication1/    # Original Atmel Studio project (unchanged)
  ...
```

- MCAL/DIO: Digital I/O register map and APIs
- HAL/L298N: Motor driver API and implementation
- LIB: STD_TYPES.h, BIT_MATH.h

Build

There are two ways to build:

- From Atmel Studio (Windows): open `GccApplication1.atsln`, select the project, and Build.
- Portable Make (cross-platform if AVR GCC is installed):

```bash
make
```

Outputs (ignored in VCS) are in `build/`: `line-follower.elf`, `line-follower.hex`.

Flashing

Use avrdude or Atmel Studio Device Programming with your programmer. Example avrdude (adjust COM/port and programmer):

```bash
avrdude -c usbasp -p m32 -U flash:w:build/line-follower.hex:i
```

Pinout

- Motor A: PD0 (IN1), PD1 (IN2)
- Motor B: PD3 (IN3), PD4 (IN4)
- IR Left: PD6
- IR Right: PD7

Edit `firmware/include/hal/l298n/MOTOR_DEFINITION.h` to change pin mapping.

Notes

- Define CPU frequency via F*CPU for accurate \_delay*\* functions. See `firmware/src/main.c`.
- Keep register and DIO definitions centralized under `MCAL/DIO`.
