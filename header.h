/*
 * header.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Maximillian
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <xil_exception.h>

#define UART1_CR *((uint32_t *) 0xE0001000)
#define UART1_MR	*((uint32_t *) 0xE0001004)
#define UART1_BDGEN *((uint32_t *) 0xE0001018)
#define UART1_BDDIV *((uint32_t *) 0xE0001034)
#define UART1_SR	*((uint32_t *) 0xE000102C)
#define UART1_DATA	*((uint32_t *) 0xE0001030)


void reset_UART();
void configure_UART();

void write_character(char letter);
char read_character(void);








#endif /* HEADER_H_ */
