#ifndef D_TIM_0_H
#define D_TIM_0_H

#include "MK64F12.h"
#include <stdint.h>

/**
 * The initialisation of the PIT-component in the K64F microchip, more specifically channel 0
 *
 * @author Robin Nollet
 */
void initTim0();

/**
 * starts the timer on the provided amount of microseconds.
 *
 * Be aware: this is a PIT timer, so there when the timer runs out,
 * it throws an interrupt, and restarts counting immediatly.
 *
 * @author Robin Nollet
 * @param microseconds: the period of the PIT-timer, in µs
 */
void startTim0(uint32_t microseconds);

/**
 * returns the value of the timer.
 *
 * @author Robin Nollet
 * @return a percentage of how close to completion the timer is.
 * 			-> e.g. if the timer counts to 10 seconds and 0.2 seconds has past, the return will be 0.02.
 */
float tim0Value();

/**
 * this sets the method that needs to be called when an interrupt is thrown.
 *
 * @author Robin Nollet
 * @param a prototype of a function that needs to be called.
 * 		-> of this prototype: 	- return void
 * 								- param void
 */
void Tim0SetIRQ(void (*interruptFunctie)(void));

#endif
