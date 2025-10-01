Line Follower (AVR ATmega32)

[![Build](https://img.shields.io/badge/build-make-brightgreen?style=for-the-badge)](#build)
[![Toolchain](https://img.shields.io/badge/toolchain-AVR--GCC-blue?style=for-the-badge)](#build)
[![MCU](https://img.shields.io/badge/MCU-ATmega32-orange?style=for-the-badge)](#pinout)
[![Language](https://img.shields.io/badge/language-C-00599C?style=for-the-badge)](#)
[![License](https://img.shields.io/badge/license-MIT-lightgrey?style=for-the-badge)](LICENSE)

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
```

- MCAL/DIO: Digital I/O register map and APIs
- HAL/L298N: Motor driver API and implementation
- LIB: STD_TYPES.h, BIT_MATH.h

Build

Build (portable)

Prereqs: AVR GCC toolchain (`avr-gcc`, `avr-objcopy`, `avr-size`) in PATH.

```bash
make
```

Outputs are in `build/`: `line-follower.elf`, `line-follower.hex`.

Flashing

Use avrdude with your programmer. Example (adjust programmer and port):

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

See also: `docs/ARCHITECTURE.md` for a brief overview of layers and data flow.
