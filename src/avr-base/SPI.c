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
#include "include/avr-base/io_ports.h"

// Units are in Mhz
static uint32_t SPI_TRANSFER_RATE = 0u;

void avr_spi_init_master()
{
	// Cast register to structs
	volatile spi_init_register*   		 spcr = (volatile spi_init_register*)&SPCR;
	volatile spi_status_register* 		 spsr = (volatile spi_status_register*)&SPSR;
	volatile io_data_direction_register* ddrb = (volatile io_data_direction_register*)&DDRB;

	//
	// Config SPI for data transfer as master
	//
	spcr->enable_spi 	= ENABLE_BIT;
	spcr->act_as_master = ENABLE_BIT;

	// Enable outputs (1u) for SPI master control
	ddrb->pin_2 = ENABLE_BIT; // SS - 
	ddrb->pin_3 = ENABLE_BIT; // MOSI - 
	ddrb->pin_5 = ENABLE_BIT; // SCK - 

	// SPR0 and SPR1 (register 0 and 1) both are set to 0 and SPIF set to 1,
	// so we can use the maximum transfer rate. 
	// The equation for the transfer rate is the following: 
	spsr->double_spi_speed = ENABLE_BIT;
	SPI_TRANSFER_RATE = CPU_FREQ / 2u;
}

void avr_spi_init_slave()
{
	
}

void avr_spi_close()
{
	// Clear registers
	SPCR = 0x0; 
	SPSR = 0X0;
}

uint8_t avr_spi_bidrec_transfer(uint8_t data)
{
	volatile spi_status_register* spsr = (volatile spi_status_register*)&SPSR;
	volatile spi_data_register*   spdr = (volatile spi_data_register*)&SPDR;
	
	// start writing
	spdr->data = data; // MOSI
	
	// copy bit and shift until MSB is set, then we end. (little-endian)
	while (!(spsr->spi_interput_flag));

	return SPDR; // MISO
}



