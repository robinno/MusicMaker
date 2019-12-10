#ifndef POT_INPUT_H
#define POT_INPUT_H

#include "MK64F12.h"
#include <stdint.h>

/**
 * The initialisation of the ADC-component in the K64F microchip.
 *
 * @author Robin Nollet
 */
void initPot();

/**
 * reads the current analog input on the ADC component.
 *
 * @author Robin Nollet
 * @return the read analog value with a 16 bit integer as a measure
 * 		-> actual input is a map between 0-Vcc and 0-65565
 */
uint16_t getPotInput();

#endif
