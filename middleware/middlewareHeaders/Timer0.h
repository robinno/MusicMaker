#ifndef TIM0_H
#define TIM0_H

#include "../../drivers/driverHeaders/DriverTimer0.h"

/**
 * The initialisation of the timer 0
 *
 * @dependency DriverTimer0
 *
 * @author Robin Nollet
 */
void initTimer0();

/**
 * starts the timer on the provided BPM.
 *
 * BPM is the amount of beats per minut (so the frequency times 60).
 *
 * @author Robin Nollet
 * @param bpm
 */
void startTimer0BPM(uint8_t bpm);

/**
 * returns the value of the timer.
 *
 * @dependency DriverTimer0
 *
 * @author Robin Nollet
 * @return a percentage of how close to completion the timer is.
 * 			-> e.g. if the timer counts to 10 seconds and 0.2 seconds has past, the return will be 0.02.
 */
float timer0Value();

/**
 * this sets the method that needs to be called when an interrupt is thrown.
 *
 * @dependency DriverTimer0
 *
 * @author Robin Nollet
 * @param a prototype of a function that needs to be called.
 * 		-> of this prototype: 	- return void
 * 								- param void
 */
void Timer0SetIRQ(void (*interruptFunctie)(void));

#endif
