#ifndef SPI_H
#define SPI_H

#include "MK64F12.h"

/*
* Initializes the SPI.
* The SPI works with GPIO pins.
*
* @return zero when no problems occured.
*/
int initSPI();

/*
* Push a byte on the MOSI line of SPI. This is done msb first.
*
* @param  A0 Set the A0 pin high if 1 else it makes the pin low.
* @param  data The byte to send on the MOSI line.
* @return zero when no problems occured.
*/
int pushSPI(int A0, uint8_t data);

/*
* Busy delay of ns10 * 10 ns.
*
* @param  ns10 Number of 10ns delay there should be.
* @return void
*/
void delay_10ns(int ns10);

/*
* Busy delay of ms * 1 ms.
*
* @param  ms Number of milisecond delay.
* @return void
*/
void delay_ms(int ms);

#endif
