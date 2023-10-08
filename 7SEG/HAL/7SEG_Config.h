/*
*    7SEG_Config.h
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 9-9-2023
*    Desc: Header file contains configurations for 7-segment driver 
*/

#ifndef _7SEG_CONFIG_H_
#define _7SEG_CONFIG_H_

// Macros to define directions and states(low/high)
#define LOW		0
#define HIGH	1
#define INPUT	0x0
#define OUTPUT	0xFF

// Macros to define values for ports
#define PORT_A	1
#define PORT_B	2
#define PORT_C	3
#define PORT_D	4

// Macros to represent ports
#define SEG_PORT PORT_C
#define LED_PORT PORT_D

// Macros to represent numbers binary representation
#define ZERO	0b00111111
#define ONE     0b00000110
#define TWO     0b01011011
#define THREE   0b01001111
#define FOUR    0b01100110
#define FIVE    0b01101101
#define SIX     0b01111101
#define SEVEN   0b00000111
#define EIGHT   0b01111111
#define NINE    0b01101111
#define DOT     0b10000000
#define TEST    0b11111111

#endif 
