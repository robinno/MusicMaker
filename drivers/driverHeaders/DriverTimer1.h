#ifndef D_TIM_1_H
#define D_TIM_1_H

#include "MK64F12.h"
#include <stdint.h>

/**
 * The initialisation of the PIT-component in the K64F microchip, more specifically channel 1
 *
 * @author Robin Nollet
 */
void initTim1();

/**
 * starts the timer on the provided amount of microseconds.
 *
 * Be aware: this is a PIT timer, so there when the timer runs out,
 * it throws an interrupt, and restarts counting immediatly.
 *
 * @author Robin Nollet
 * @param microseconds: the period of the PIT-timer, in µs
 */
void startTimer1(uint32_t microseconds);

/**
 * this sets the method that needs to be called when an interrupt is thrown.
 *
 * @author Robin Nollet
 * @param a prototype of a function that needs to be called.
 * 		-> of this prototype: 	- return void
 * 								- param void
 */
void Tim1SetIRQ(void (*interruptFunctie)(void));

#endif
