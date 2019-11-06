#include "MK64F12.h"
#include <stdint.h>

void initTim1();

void startTimer1(uint32_t microseconds);

void Tim1SetIRQ(void (*interruptFunctie)(void));
