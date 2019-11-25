#include "middlewareHeaders/ReadPot.h"

uint8_t rangeMin = 0;
uint8_t rangeMax = 0;

void initReadPot(uint8_t min, uint8_t max){
	initPot();
	rangeMin = min;
	rangeMax = max;
}

uint8_t readPot(){
	uint16_t value = getPotInput();
	uint16_t result = value * ((rangeMax + 1 - rangeMin) / (float) (1<<16)) + rangeMin;
	return result;
}
