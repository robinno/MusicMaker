#include "middlewareHeaders/PlaySound.h"

/////////////////////
//GLOBALS:
/////////////////////

uint16_t fs = 50; //sample frequency in kHz


//TESTSIGNALS:

bool testSinePlaying = false;
uint16_t testSine[113] = {
		2048, 2161, 2274, 2386, 2497, 2607, 2715, 2821, 2925, 3026, 3124, 3218, 3309, 3397, 3480, 3558, 3633, 3702, 3766, 3825, 3879, 3927, 3969, 4005, 4035, 4060, 4078, 4090, 4095, 4095, 4088, 4075, 4056, 4030, 3999, 3962, 3918, 3869, 3815, 3755, 3690, 3619, 3544, 3465, 3381, 3293, 3201, 3106, 3007, 2906, 2802, 2696, 2587, 2477, 2366, 2254, 2141, 2027, 1914, 1802, 1690, 1579, 1469, 1362, 1256, 1153, 1052, 955, 861, 771, 684, 602, 524, 450, 382, 319, 261, 208, 161, 120, 85, 56, 33, 16, 5, 0, 2, 10, 24, 44, 71, 103, 142, 186, 236, 292, 353, 419, 490, 566, 646, 731, 819, 912, 1008, 1107, 1209, 1313, 1420, 1529, 1639, 1751, 1863
}; //A: 440Hz = test sine => CAREFULL: 12 bit !!!!!
uint8_t testSineIndex = 0;

bool testSine2Playing = true;
uint16_t testSine2[151] = {
		2048, 2133, 2218, 2302, 2386, 2470, 2552, 2634, 2715, 2795, 2873, 2950, 3026, 3099, 3171, 3241, 3309, 3375, 3439, 3500, 3558, 3614, 3668, 3718, 3766, 3811, 3853, 3891, 3927, 3959, 3988, 4013, 4035, 4054, 4070, 4081, 4090, 4095, 4096, 4094, 4088, 4079, 4066, 4050, 4030, 4007, 3981, 3951, 3918, 3882, 3843, 3800, 3755, 3706, 3655, 3601, 3544, 3485, 3423, 3359, 3293, 3225, 3154, 3082, 3007, 2932, 2854, 2776, 2696, 2614, 2532, 2449, 2366, 2282, 2197, 2112, 2027, 1943, 1858, 1773, 1690, 1606, 1524, 1442, 1362, 1282, 1204, 1127, 1052, 979, 908, 838, 771, 705, 642, 582, 524, 468, 416, 366, 319, 275, 234, 196, 161, 130, 102, 77, 56, 38, 23, 12, 5, 1, 0, 3, 10, 20, 33, 50, 71, 95, 122, 152, 186, 223, 263, 307, 353, 402, 454, 508, 566, 626, 688, 752, 819, 888, 959, 1032, 1107, 1183, 1261, 1340, 1420, 1501, 1584, 1667, 1751, 1835, 1919
}; //E: 330Hz = test sine => CAREFULL: 12 bit !!!!!
uint8_t testSine2Index = 0;


/////////////////////
//IRQ FOR TIMER:
/////////////////////

void playNextSample(){ //THE IRQ for the timer
	if(testSine2Playing && testSinePlaying){
		DAC0_set((testSine[testSineIndex] + testSine2[testSine2Index]) / 2);
		testSineIndex = (testSineIndex + 1) % 113;
		testSine2Index = (testSine2Index + 1) % 151;
	}else if(testSinePlaying){
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

void playsound_testSineWave(uint8_t on) {
	testSinePlaying = (on == 1)? true: false;
}

void playsound_test2SineWaves(uint8_t on) {
	testSinePlaying = (on == 1)? true: false;
	testSine2Playing = (on == 1)? true: false;
}
