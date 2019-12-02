#ifndef TIM0_H
#define TIM0_H

#include "../../drivers/driverHeaders/DriverTimer0.h"

void initTimer0();

void startTimer0(uint32_t microseconds);
void startTimer0BPM(uint8_t bpm);

float timer0Value();

void Timer0SetIRQ(void (*interruptFunctie)(void));

#endif
