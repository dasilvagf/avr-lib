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

#include "include/avr-base/SPI.h"

// Units are in Mhz
static uint8_t SPI_TRANSFER_RATE = 0u;

void init_spi(uint16_t osc_freq)
{
	//
	// Config SPI for data transfer
	//
	SPCR = 0x0; // Clear
	SET_BIT(SPCR, 6); // Enable SPI
	SET_BIT(SPCR, 4); // Act as the Master
	
	// SPR0 and SPR1 (register 0 and 1) both are set to 0,
	// so we can use the maximum transfer rate. 
	// The equation for the transfer rate is the following: 
	SPI_TRANSFER_RATE = osc_freq / 4u;
}

void close_spi()
{
	SPCR = 0x0; // Clear
}

uint8_t avr_spi_bidrec_transfer(uint8_t data)
{
	SPDR = data;
	while (!(SPSR & 0x80));
	return SPDR;
}



