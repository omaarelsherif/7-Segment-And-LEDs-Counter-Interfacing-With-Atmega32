/*
*    7SEG_Program.c
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 9-9-2023
*    Desc: Code file contains the code for 7-segment driver 
*/

// Include header files
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "7SEG_Config.h"
#include "7SEG_Interface.h"
#include <avr/delay.h>

// Create array to represent numbers to be displayed in 7 segment
static u8 Numbers[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

// Function to display a number in 7 segment
void SEG_VoidDisplaySeg(u8 Number)
{
	// Set DDR of segment port as output
	DIO_VoidSetPortDirection(SEG_PORT, 255);

	// Display the number in the
	DIO_VoidSetPortValue(SEG_PORT, Numbers[Number]);
}

// Function to count numbers in 7 segment and indicate count with leds
void SEG_VoidCountSeg(void)
{
	// Initialize Data Direction Register (DDR) for portc
	DIO_VoidSetPortDirection(SEG_PORT, OUTPUT);

	// Initialize Data Direction Register (DDR) for portd
	DIO_VoidSetPortDirection(LED_PORT, 0b11111111);

	// Initialize a variable to hold leds states
	u8 led = 0b00000000;

	// Program loop
	while(1)
	{
		// Loop and display values from n1 to n2 in 7 segement
		for(int i=0; i<=9; i++)
		{
			// Display number in the 7 segment
			DIO_VoidSetPortValue(SEG_PORT, Numbers[i]);

			// Turn on leds
			if(i > 0)
			{
				SET_BIT(led, i-1);
			}
			DIO_VoidSetPortValue(LED_PORT, led);
			if(i == 9)
			{
				DIO_VoidSetPortValue(LED_PORT, 0);
			}
			_delay_ms(750);
		}

		// Reset led counter
		led = 0x0;
	}
}
