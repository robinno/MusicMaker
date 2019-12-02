#ifndef DAC_DRIVER_H
#define DAC_DRIVER_H

#include "MK64F12.h"
#include <stdint.h>
#include <stdbool.h>

void DAC0_init();

void DAC0_set(uint16_t value); //Value = between 0 and 4095!! (12 bit)

#endif
