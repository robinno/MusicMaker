#include "middlewareHeaders/Timer0.h"

void initTimer0(){
	initTim0();
}

void startTimer0(uint32_t microseconds){
	startTim0(microseconds);
}

void startTimer0BPM(uint8_t bpm){
	float freq = bpm / 60; //de frequentie van de timer die nodig is
	float period = 1 / freq;
	uint32_t microseconds = (uint32_t) (period * 1000000);

	startTimer0(microseconds);
}

float timer0Value(){
	return tim0Value();
}

void Timer0SetIRQ(void (*interruptFunctie)(void)){
	Tim0SetIRQ(interruptFunctie);
}
