#include "../../drivers/driverHeaders/DriverTimer0.h"

void initTimer0();

void startTimer0(uint32_t microseconds);
float timer0Value();

void Timer0SetIRQ(void (*interruptFunctie)(void));
