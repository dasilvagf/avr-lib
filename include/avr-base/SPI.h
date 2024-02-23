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

#ifndef _AVR_SPI_H_
#define _AVR_SPI_H_

#include "avr_registers.h"

//
//		Initialization/Shutdown
//

// 8bit SPCR register
typedef struct spi_init_register_t
{
	uint8_t enable_spi : 1; // SPE (bit6)
	uint8_t enable_spi_interrupt : 1; // SPIE (bit7)
	uint8_t send_MSB_first : 1; // DORD (bit5)
	uint8_t act_as_master : 1; // MSTR (bit4)
	uint8_t clock_polarity_iddle_high : 1; // CPOL(bit3)
	uint8_t clock_phase_ouput_after_cs : 1; // CPHA(bit2)

	// Plase, refer to the transfer rate speed table to see the meaning
	// of the bitmaks and how to multiplex them to index into it.
	// https://www.coursehero.com/file/p23h12k0/Table-19-5-Relationship-Between-SCK-and-the-Oscillator-Frequency-SPI2X-SPR1-SPR0/
	uint8_t transfer_rate_bitmask_0 : 1; // SPR1(bit1)
	uint8_t transfer_rate_bitmask_1 : 1; // SPR0(bit0)
}spi_init_register;

void avr_spi_init(uint16_t osc_freq);
void avr_spi_close();

//
//		SPI Protocol Interface
//

// This function bidirecionally transfer [send(MOSI)/receive(MISO)] 2 bit in parallel. 
// It takes 8 serial iterations at SPI_TRANSFER_RATE to completely transfer a byte. During
// this time the function blocks (spins).
uint8_t avr_spi_bidrec_transfer(uint8_t data);

#endif
