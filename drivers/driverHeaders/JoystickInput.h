#include "MK64F12.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

typedef enum
{ //integer assigned to enum = pinnumber + 100 if PORTB or +200 if PORTC
    UP = 110,
    DOWN = 111,
    LEFT = 211,
	RIGHT = 210,
	FIRE = 123
} direction;

/*
 * port is 'b' or 'c';
 * pin is pinnumber
 * *fp is pointer to ISR
 * direction is string: "up", "down", "left", "right" or "fire".
 */
int initJoyStick(direction dir, void (*fp)(void));
