#include "middlewareHeaders/PlaySound.h"
#include <stdbool.h>

////GLOBALS:
uint8_t numberOfSounds = 0;

struct sound** alleGeluidjes;

/////////////////////
//IRQ FOR TIMER:
/////////////////////

void playNextSample(){ //THE IRQ for the timer
	uint16_t output = 0;

	for(int i = 0; i < numberOfSounds; i++){
		if(alleGeluidjes[i]->playing == 1){
			output += alleGeluidjes[i]->samples[alleGeluidjes[i]->index] / numberOfSounds;
			alleGeluidjes[i]->index++;

			if(alleGeluidjes[i]->index >= alleGeluidjes[i]->length){
				alleGeluidjes[i]->playing = 0;
				alleGeluidjes[i]->index = 0;
			}
		}
	}

	DAC0_set(output);
}

/////////////////////
//PUBLIC FUNCTIONS
/////////////////////

void playsound_init(uint8_t aantalSounds, struct sound** geluidjesPtr) {
	//init own variables:
	numberOfSounds = aantalSounds;
	alleGeluidjes = geluidjesPtr;

	//set all sounds: not playing and starting index = 0:
	for(uint8_t i = 0; i < aantalSounds; i ++){
		alleGeluidjes[i]->playing = 0;
		alleGeluidjes[i]->index = 0;
		alleGeluidjes[i]->active = false;
	}

	//init driver layer "components":
	DAC0_init();
	initTim1();
	Tim1SetIRQ(playNextSample);
	startTimer1((uint32_t) 1000/fs);
}

void playsound(uint8_t geluidjeNr){
	alleGeluidjes[geluidjeNr]->playing = 1;
	alleGeluidjes[geluidjeNr]->index = 0;
}
