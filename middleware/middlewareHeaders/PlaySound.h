#ifndef PLAY_H
#define PLAY_H

/**
 * @DEPENDENCY
 */
#include "../../drivers/driverHeaders/DriverTimer1.h"
#include "../../drivers/driverHeaders/DACdriver.h"
#include "Sound.h"
#include <stdint.h>

/**
 * does the initialisation of the Playsound function
 *
 * @param geluidjesPtr: pointer to an array of all the sounds that can be played.
 * @param aantalSounds: the size of the geluidjesPtr array.
 */
void playsound_init(uint8_t aantalSounds, struct sound** geluidjesPtr);

/**
 * plays a sound until the end of that sound's sample array.
 *
 * @param geluidjeNr: position in the array given in the init
 */
void playsound(uint8_t geluidjeNr);

#endif
