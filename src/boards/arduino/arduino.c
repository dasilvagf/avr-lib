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

#include <util/delay.h>

#include "include/boards/arduino/arduino.h"

//
// Testing Utilities
//

void flash_led(enum arduino_board_type board_type, uint8_t n_times)
{
    // Map ports from the avr micro-controler into the arduino board
    io_data_direction_register* io_ports = (io_data_direction_register*)&DDRB;

    // Most of the boards use pin5 for LED, so we set it as output
    io_ports->pin_5 = 1u;

    // Where we read/write from register according to DDRB direction (write/read)
    io_port_register* io_data_port = (io_port_register*)&PORTB;

    for (uint8_t n = 0u; n < n_times; ++n){
        io_data_port->pin_5 = 1u; // turn on LED
        _delay_ms(250);
        
        io_data_port->pin_5 = 0u; // turn off LED
        _delay_ms(250);
    }
}