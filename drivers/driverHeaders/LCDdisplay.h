#include "LCDcommands.h"
#include "font.h"

void print_text(uint8_t page, char string[]);
void init_LCD();

/*
 * prints a line of 8 pixels high and a width of ratio pixels.

 * @param  ratio can vary from 0 to 127. 0 is an empty line, 127 is a full line.
 * @return void
 */
void print_line(uint8_t ratio);
void print_stripe(uint8_t page);
