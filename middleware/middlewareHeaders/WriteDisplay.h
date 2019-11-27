#include "../../drivers/driverHeaders/LCDdisplay.h"

void middleware_print_text(uint8_t page, char string[]);

void middleware_init_LCD();

/*
* Prints a bar consisting of beatsInMaat pieces.
*
*
* @param  teller gives to number of pieces + 1 to paint black.
* @param  beatsInMaat speciefies in how many pieces the line should be divided.
* @return void
*/
void print_metronome(uint8_t teller, uint8_t beatsInMaat);
