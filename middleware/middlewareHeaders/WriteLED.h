#ifndef WRITE_LED_H
#define WRITE_LED_H

#include "../../drivers/driverHeaders/SetLED.h"

/*
 * Enumumeration with RGB colors.
 */
typedef enum
{ //integer assigned to enum = pinnumber + 100 if PORTB or +200 if PORTC
    RED,
	GREEN,
	BLUE
} RGB;

/*
* Initialize a red, a green and a blue LED en turn them of.
*
* @return void
*/
void initRGB();

/*
* Set LED of one of the enum RGB colors on or of.
* @param  color Specifies color to RED, GREEN or BLUE.
* @param of Turn led of when 1 else turn on led.
* @return void
*/
void setLED(RGB color, uint8_t of);

#endif
