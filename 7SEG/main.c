/*
 * 7SEG
 * Author: OmarElsherif
 */

// Include libraries
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "DIO_Interface.h"

// Functions declarations
void display_numbers(u8 Port_Seg, u8 Port_Led);

// Main function
void main(void)
{
	// Display values from 0 to 8 in the 7 segment connected to port c and 8 leds to port d
	display_numbers(2, 3);

}

// Function to display from n to n in the 7 segment
void display_numbers(u8 Port_Seg, u8 Port_Led)
{
	// Initialize Data Direction Register (DDR) for portc
	DIO_VoidSetPortDirection(Port_Seg, 0b11111111);

	// Initialize Data Direction Register (DDR) for portd
	DIO_VoidSetPortDirection(Port_Led, 0b11111111);

	// Create an array to represent numbers from 0 to 9 for common cathode 7 segment
	const uint8_t seven_segment[] = {
	    0b00111111, // 0
	    0b00000110, // 1
	    0b01011011, // 2
	    0b01001111, // 3
	    0b01100110, // 4
	    0b01101101, // 5
	    0b01111101, // 6
	    0b00000111, // 7
	    0b01111111, // 8
	    0b01101111  // 9
	};

	// Initialize a variable to hold leds states
	u8 led = 0b00000000;

	// Program loop
	while(1)
	{
		// Loop and display values from n1 to n2 in 7 segement
		for(int i=0; i<=9; i++)
		{
			// Display nimber in the 7 segment
			DIO_VoidSetPortValue(Port_Seg, seven_segment[i]);

			// turn on leds
			DIO_VoidSetPortValue(Port_Led, led);
			if(i<=8)
			{
				led |= (1 << i);
			}
			else
			{
				DIO_VoidSetPortValue(Port_Led, 0);
			}
			_delay_ms(1000);
		}

		// Reset led counter
		led = 0x0;
	}
}

