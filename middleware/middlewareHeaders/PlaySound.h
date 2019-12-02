#ifndef PLAY_H
#define PLAY_H

#include "../../drivers/driverHeaders/DriverTimer1.h"
#include "../../drivers/driverHeaders/DACdriver.h"
#include "Sound.h"
#include <stdint.h>

void playsound_init(uint8_t aantalSounds, struct sound** geluidjesPtr);

void playsound(uint8_t geluidjeNr);

#endif
