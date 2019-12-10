#ifndef DAC_DRIVER_H
#define DAC_DRIVER_H

#include "MK64F12.h"
#include <stdint.h>
#include <stdbool.h>


/**
 * The initialisation of the DAC-component in the K64F microchip.
 *
 * @author Robin Nollet
 */
void DAC0_init();

/**
 * sets the ouput of the DAC-component to the specified value.
 *
 * @author Robin Nollet
 * @param value: is a 12 bit integer value that represents the output voltage needed at the output of the DAC
 * 			-> the ouput voltage is calculatable by linear interpolation: 0-4095 translates to 0-Vcc with Vcc = board voltage
 * 			-> carefull: value = 12 bit (so no bigger than 4095 is allowed).
 */
void DAC0_set(uint16_t value); //Value = between 0 and 4095!! (12 bit)

#endif
