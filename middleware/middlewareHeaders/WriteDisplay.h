#ifndef WRITE_DISPL_H
#define WRITE_DISPL_H

#include "../../drivers/driverHeaders/LCDdisplay.h"
#include <string.h>

/*
* Prints menuname on the center of the first line of the LCD-screen.
*
* @param  menuname String to print.
* @return void
*/
void print_menuName(char menuname[]);

/*
* Initializes the LCD and prints a line on the second line of the LCD-screen.
*
* @return void
*/
void middleware_init_LCD();

/*
* Prints a bar consisting of beatsInMaat pieces.
*
* @param  teller gives to number of pieces + 1 to paint black.
* @param  beatsInMaat specifies in how many pieces the line should be divided.
* @return void
*/
void print_metronome(uint8_t teller, uint8_t beatsInMaat);

/*
* Prints menuitem on the third line of the LCD-screen.
*
* @param  menuitem String that will be printed on the LCD.
* @return void
*/
void print_menuItem(char menuItem[]);

#endif
