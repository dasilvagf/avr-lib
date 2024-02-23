/*
			AVR LIB
Exactly what the name implies, nothing less, nothing more. Just for fun! :)

Copyright (C) 2023-2024  Gabriel Felipe S. da Silva

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

#ifndef _AVR_REGISTERS_H_
#define _AVR_REGISTERS_H_

#include <stdint.h>

//
// Utils
//
#define SET_BIT(REG, N) REG |= (0x1 << (N + 1u))
#define CLEAR_BIT(REG, N) REG &= ~(0x1 << (N + 1u))

//
// Data Port
//
#define PORTB 	*((volatile uint8_t*)0x25)
#define PORTC 	*((volatile uint8_t*)0x28)
#define PORTD 	*((volatile uint8_t*)0x2B)

//
// Data Direction 
//
#define DDRB	*((volatile uint8_t*)0x24)
#define DDRC	*((volatile uint8_t*)0x27)
#define DDRD	*((volatile uint8_t*)0x2A)

//
// SPI
//
#define SPCR	*((volatile uint8_t*)0x4C)	// Control register
#define SPDR 	*((volatile uint8_t*)0x4E)	// Data register (MOSI)

#endif
