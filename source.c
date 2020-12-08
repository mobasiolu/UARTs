/*
 * source.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Maximillian
 */


#include "header.h"


void reset_UART()
{

	UART1_CR = 3;	//assert the tx and rx resets

		while(UART1_CR&0x3);	//wait for reset to occur

}

void configure_UART() //UART1 for a baud-rate of 115200, 8 data bits, no parity bits, and 1 stop bit.
{
	  uint32_t mode_reg_config_code; // will be used to configure mode register

	  reset_UART(); //FIRST reset the UART module by the setting TX and RX reset bits in the control register

	  mode_reg_config_code = 0b0000100000;
	  UART1_MR = mode_reg_config_code; //configure the mode register for desired mode

	  UART1_CR = 0b000010100; //enable transmitter and reciever by setting enable bits in the control register

	  UART1_BDGEN = 0x7C; //62 is the right number
	  UART1_BDDIV = 6;//(13 is the right numberconfigure the baudrate by writing to the baudgen and bauddive registers

	  UART1_CR = 0x117; //uncomment this later
}

int uart1_tx_full()
	{
		//check to see if bit 4 (TX fifo full) in the SR is set
		//return 1 if set, otherwise 0
		return (UART1_SR & 16)!=0;
	}


void write_character(char letter)
{


	while(uart1_tx_full()); //wait for room in FIFO

		UART1_DATA = letter;	//write to TX FIFO

}


//checks whether or not there are entries
//in the rx FIFO
int uart1_rx_empty()
{
	//check if bit 1 is set (bit 1 is 'RX fifo empty')
	//if bit 1 set return 1, otherwise 0
	return ((UART1_SR & 2)!=0);
}

char read_character(void)
{
	char dat = 0;

		while(uart1_rx_empty());	//wait for data in FIFO

		dat = UART1_DATA;	//read from FIFO
		return dat;

}

void transmit_C_string(char arr[])
{
	int n = 0;

	while (arr[n] != '\0')
	{
		 write_character(arr[n]);
		 n++;
	}

}
