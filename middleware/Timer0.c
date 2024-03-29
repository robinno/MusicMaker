#include "middlewareHeaders/Timer0.h"

void initTimer0(){
	initTim0();
}


void startTimer0BPM(uint8_t bpm){
	double freq = (((double) bpm) / 60) * 4; //de frequentie van de timer die nodig is (maal 4 want per zestiende noot ipv kwartnoot)
	double period = 1 / freq;
	uint32_t microseconds = (uint32_t) (period * 1000000);

	startTim0(microseconds);
}

float timer0Value(){
	return tim0Value();
}

void Timer0SetIRQ(void (*interruptFunctie)(void)){
	Tim0SetIRQ(interruptFunctie);
}
