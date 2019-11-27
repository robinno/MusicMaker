#include "LCDcommands.h"
#include "font.h"

/*
* Prints text on the LCD on the specified page.
*
* A page is a horizontal line on the LCD. There are four pages, page zero is the lowest on the screen.
*
* @param  page specifies which page to write to.
* @param  text The text to write on the page. If lenght of text is more than 16 the rest of the characters are ignored.
* @return void
*/
void print_text(uint8_t page, char text[]);

/*
* Initialize the LCD-screen and als the SPI.
*
* @return void
*/
void init_LCD();

/*
 * Prints a line of 8 pixels high and a width of 'ratio' pixels.
 * Past 'ratio' pixels a line is drawn of 2 pixels high. The line is printed on the lowest of 4 lines on the LCD-screen.
 *
 * @param  ratio can vary from 0 to 127. 0 is an empty line, 127 is a full line.
 * @return void
 */
void print_line(uint8_t ratio);

/*
* Prints a line of 2 pixels high across the specified page.
*
* @param  page specifies which page to write to.
* @return void
*/
void print_stripe(uint8_t page);
