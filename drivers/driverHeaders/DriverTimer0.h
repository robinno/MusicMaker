#include "MK64F12.h"
#include <stdint.h>

void initTim0();

void startTimer0(uint32_t microseconds);

void Tim0SetIRQ(void (*interruptFunctie)(void));
