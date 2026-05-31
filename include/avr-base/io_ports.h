/*
			AVR LIB
Exactly what the name implies, nothing less, nothing more. Just for fun! :)

Copyright (C) 2023-2026  Gabriel Felipe S. da Silva

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _AVR_IO_H_
#define _AVR_IO_H_

#include "avr_registers.h"

// I/O Ports Documentation
// https://developerhelp.microchip.com/xwiki/bin/view/products/mcu-mpu/8-bit-avr/structure/ioports/

// 8bit DDRB register
typedef struct io_data_direction_register_t
{
    uint8_t pin_0 : 1; // DDRB0(bit0)
    uint8_t pin_1 : 1; // DDRB1(bit1)
    uint8_t pin_2 : 1; // DDRB2(bit2)
    uint8_t pin_3 : 1; // DDRB3(bit3)
    uint8_t pin_4 : 1; // DDRB4(bit4)
    uint8_t pin_5 : 1; // DDRB5(bit5)
    uint8_t pin_6 : 1; // DDRB6(bit6)
    uint8_t pin_7 : 1; // DDRB7(bit7)
}io_data_direction_register;

// 8bit PORTB register
typedef struct io_data_port_register_t
{
    uint8_t pin_0 : 1; // PORTB0(bit0)
    uint8_t pin_1 : 1; // PORTB1(bit1)
    uint8_t pin_2 : 1; // PORTB2(bit2)
    uint8_t pin_3 : 1; // PORTB3(bit3)
    uint8_t pin_4 : 1; // PORTB4(bit4)
    uint8_t pin_5 : 1; // PORTB5(bit5)
    uint8_t pin_6 : 1; // PORTB6(bit6)
    uint8_t pin_7 : 1; // PORTB7(bit7)
}io_port_register;

#endif