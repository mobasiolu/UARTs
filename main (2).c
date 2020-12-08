/*
 * main.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Maximillian
 */

#include "header.h"


int main (void)
{


int i;
char val = 0;
char response = 'M';
char arr[15] = "Hunter\0";
configure_UART();

for (;;)
{
	val = read_character();

	if(val = 'H')
	{
	transmit_C_string(arr);
	}


		for(i=0;i<60000;i++);


}

}
