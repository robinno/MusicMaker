#include "middlewareHeaders/PlaySound.h"
#include "middlewareHeaders/Geluidjes.h"

//TESTSIGNALS:

bool testSinePlaying = false;
uint8_t testSineIndex = 0;

bool testSine2Playing = false;
uint8_t testSine2Index = 0;

bool kickPlaying = false;
uint16_t kickIndex = 0;


/////////////////////
//IRQ FOR TIMER:
/////////////////////

void playNextSample(){ //THE IRQ for the timer
//	if(testSine2Playing && testSinePlaying){
//		DAC0_set((testSine[testSineIndex] + testSine2[testSine2Index]) / 2);
//		testSineIndex = (testSineIndex + 1) % testSineLength;
//		testSine2Index = (testSine2Index + 1) % testSine2Length;
//	}else if(testSinePlaying){
//		DAC0_set(testSine[testSineIndex]);
//		testSineIndex = (testSineIndex + 1) % testSineLength;
//	}

	if(kickPlaying){
		DAC0_set(kick[kickIndex]); //output sample
		kickIndex++;

		if(kickIndex >= kickLength){ //when at the end of the kick array
			kickPlaying = false;
			kickIndex = 0;
		}
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

void playsound_kick(){
	kickPlaying = true;
}
