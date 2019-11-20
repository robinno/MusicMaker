#include "middlewareHeaders/PlaySound.h"

////GLOBALS:
uint8_t amountOfTracks = 0;
uint8_t amountOfSounds = 0;

struct sound* sounds;

///////////////////////
////IRQ FOR TIMER:
///////////////////////

void playNextSample(){ //THE IRQ for the timer

	uint16_t output = 0;

	//TODO
//	if(bambooPlaying){
//			output += (bamboo[bambooIndex] / amountOfTracks); //output sample
//			bambooIndex++;
//
//			if(bambooIndex >= bambooLength){ //when at the end of the bamboo array
//				bambooPlaying = false;
//				bambooIndex = 0;
//			}
//		}

	DAC0_set(output);
}



///////////////////////
////PUBLIC FUNCTIONS
///////////////////////

void playsound_init(uint8_t aantalTracks, uint8_t aantalGeluidjes, struct sound* geluidjes) {
	DAC0_init();

	amountOfTracks = aantalTracks;
	amountOfSounds = aantalGeluidjes;
	sounds = geluidjes;

	//set all sounds: not playing and starting index = 0:
	for(uint8_t i = 0; i < amountOfSounds; i ++){
		sounds[i].playing = 0;
		sounds[i].index = 0;
	}

	initTim1();
	Tim1SetIRQ(playNextSample);
	startTimer1((uint32_t) 1000/fs);
}

void playsound(uint8_t indexVanGeluidje){
	sounds[indexVanGeluidje].playing = 1;
	sounds[indexVanGeluidje].index = 0;
}
