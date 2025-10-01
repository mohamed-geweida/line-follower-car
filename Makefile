# Portable build for AVR firmware (ATmega32)

PROJECT := line-follower
MCU := atmega32
F_CPU ?= 8000000UL

BUILD_DIR := build
SRC_DIR := firmware/src
INC_DIR := firmware/include

CC := avr-gcc
OBJCOPY := avr-objcopy
SIZE := avr-size

C_SOURCES := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/mcal/dio/DIO_program.c \
	$(SRC_DIR)/hal/l298n/MOTOR_PROGRAM.c

OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SOURCES))
DEPS := $(OBJECTS:.o=.d)

CFLAGS := -mmcu=$(MCU) -DF_CPU=$(F_CPU) -std=gnu99 -Wall -Wextra -Werror \
	-Og -g2 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums \
	-I$(INC_DIR)
LDFLAGS := -Wl,--gc-sections -mmcu=$(MCU)

ELF := $(BUILD_DIR)/$(PROJECT).elf
HEX := $(BUILD_DIR)/$(PROJECT).hex

.PHONY: all clean size flash

all: $(HEX) size

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(ELF): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

size: $(ELF)
	$(SIZE) $<

clean:
	rm -rf $(BUILD_DIR)

# Example flash target (adjust programmer and port)
flash: $(HEX)
	@echo "Use avrdude to flash $(HEX) to $(MCU)"

