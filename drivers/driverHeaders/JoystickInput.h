#ifndef JS_IN_H
#define JS_IN_H

#include "MK64F12.h"
#include <stdint.h>

/*
 * Enum that represents the direction of the joystick pins.
 * <p>
 * integer assigned to enum = pinnumber + 100 if PORTB or +200 if PORTC.
 * <\p>
 */
typedef enum
{ //integer assigned to enum = pinnumber + 100 if PORTB or +200 if PORTC
    UP = 110,
    DOWN = 111,
    LEFT = 211,
	RIGHT = 210,
	FIRE = 123
} direction;

/**
 * Initialises a pin of joystick.
 * <p>
 * One pin of the joystick is initialised. An interrupt is set on
 * rising edges.
 * </p>
 *
 * @param  dir says which direction should be initialized. UP, DOWN, LEFT, RIGHT or FIRE.
 * @param fp is a pointer to the function that is the ISR.
 * @return zero if succesfull.
 */
int initJoyStick(direction dir, void (*fp)(void));

#endif
