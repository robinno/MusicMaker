#ifndef READ_POT_H
#define READ_POT_H

#include "../../drivers/driverHeaders/PotInput.h"

void initReadPot(uint8_t min, uint8_t max);
uint8_t readPot();

#endif
