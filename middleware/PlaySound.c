#include "middlewareHeaders/PlaySound.h"

/////////////////////
//GLOBALS:
/////////////////////

uint16_t fs = 50; //sample frequency in kHz

bool testSinePlaying = false;
uint16_t testSine[113] = {
		2048, 2161, 2274, 2386, 2497, 2607, 2715, 2821, 2925, 3026, 3124, 3218, 3309, 3397, 3480, 3558, 3633, 3702, 3766, 3825, 3879, 3927, 3969, 4005, 4035, 4060, 4078, 4090, 4095, 4095, 4088, 4075, 4056, 4030, 3999, 3962, 3918, 3869, 3815, 3755, 3690, 3619, 3544, 3465, 3381, 3293, 3201, 3106, 3007, 2906, 2802, 2696, 2587, 2477, 2366, 2254, 2141, 2027, 1914, 1802, 1690, 1579, 1469, 1362, 1256, 1153, 1052, 955, 861, 771, 684, 602, 524, 450, 382, 319, 261, 208, 161, 120, 85, 56, 33, 16, 5, 0, 2, 10, 24, 44, 71, 103, 142, 186, 236, 292, 353, 419, 490, 566, 646, 731, 819, 912, 1008, 1107, 1209, 1313, 1420, 1529, 1639, 1751, 1863
}; //A: 440Hz = test sine => CAREFULL: 12 bit !!!!!
uint8_t testSineIndex = 0;



/////////////////////
//IRQ FOR TIMER:
/////////////////////

void playNextSample(){ //THE IRQ for the timer
	if(testSinePlaying){
		DAC0_set(testSine[testSineIndex]);
		testSineIndex = (testSineIndex + 1) % 113;
	}
}



/////////////////////
//PUBLIC FUNCTIONS
/////////////////////

void playsound_init() {
	DAC0_init();

	initTim1();
	Tim1SetIRQ(playNextSample);
	startTimer1((uint32_t) 1000/fs);
}

void playsound_testSineWave() {
	testSinePlaying = true;
}
