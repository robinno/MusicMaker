#ifndef READ_POT_H
#define READ_POT_H

#include "../../drivers/driverHeaders/PotInput.h"

/**
 * initialises the analog input (ADC) and the mapping between the measured value and the given range.
 *
 * @dependency potInput
 *
 * @author Robin Nollet
 * @param min, max: the values which between the mapping of the measured value
 */

void initReadPot(uint8_t min, uint8_t max);

/**
 * reads the current analog input, mapped between min & max
 *
 * @dependency potInput
 *
 * @author Robin Nollet
 * @return the read analog value mapped between min & max, given in the init.
 */
uint8_t readPot();

#endif
