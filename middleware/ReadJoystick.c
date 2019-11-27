#include "middlewareHeaders/ReadJoystick.h"

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
void middleware_initJoyStick(direction dir, void (*fp)(void)) {
	initJoyStick(dir, fp);
}
