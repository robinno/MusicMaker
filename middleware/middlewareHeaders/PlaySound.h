#include "../../drivers/driverHeaders/DriverTimer1.h"
#include "../../drivers/driverHeaders/DACdriver.h"
#include "Sound.h"
#include <stdint.h>

void playsound_init(uint8_t aantalTracks, struct sound* ActiveTracks);

void playsound(uint8_t trackNr);
