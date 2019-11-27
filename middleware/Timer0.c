#include "middlewareHeaders/Timer0.h"

void initTimer0(){
	initTim0();
}

void startTimer0(uint32_t microseconds){
	startTim0(microseconds);
}
float timer0Value(){
	return tim0Value();
}

void Timer0SetIRQ(void (*interruptFunctie)(void)){
	Tim0SetIRQ(interruptFunctie);
}
