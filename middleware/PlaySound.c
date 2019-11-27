#include "middlewareHeaders/PlaySound.h"

////GLOBALS:
uint8_t amountOfTracks = 0;

struct sound* tracks_geluidjes;

/////////////////////
//IRQ FOR TIMER:
/////////////////////

void playNextSample(){ //THE IRQ for the timer
	uint16_t output = 0;

	for(int i = 0; i < amountOfTracks; i++){
		if(tracks_geluidjes[i].playing == 1){
			output += tracks_geluidjes[i].samples[tracks_geluidjes[i].index] / amountOfTracks;
			tracks_geluidjes[i].index++;

			if(tracks_geluidjes[i].index >= tracks_geluidjes[i].length){
				tracks_geluidjes[i].playing = 0;
				tracks_geluidjes[i].index = 0;
			}
		}
	}

	DAC0_set(output);
}

/////////////////////
//PUBLIC FUNCTIONS
/////////////////////

void playsound_init(uint8_t aantalTracks, struct sound* ActiveTracks) {
	//init own variables:
	amountOfTracks = aantalTracks;
	tracks_geluidjes = ActiveTracks;

	//set all sounds: not playing and starting index = 0:
	for(uint8_t i = 0; i < aantalTracks; i ++){
		tracks_geluidjes[i].playing = 0;
		tracks_geluidjes[i].index = 0;
	}

	//init driver layer "components":
	DAC0_init();
	initTim1();
	Tim1SetIRQ(playNextSample);
	startTimer1((uint32_t) 1000/fs);
}

void playsound(uint8_t trackNr){
	tracks_geluidjes[trackNr].playing = 1;
	tracks_geluidjes[trackNr].index = 0;
}
