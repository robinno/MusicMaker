#ifndef D_TIM_0_H
#define D_TIM_0_H

#include "MK64F12.h"
#include <stdint.h>

void initTim0();

void startTim0(uint32_t microseconds);
float tim0Value();

void Tim0SetIRQ(void (*interruptFunctie)(void));

#endif
