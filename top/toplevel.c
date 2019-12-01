#include <stdbool.h>
#include <stdint.h>
#include "topHeaders/toplevel.h"


bool PRESSED_DOWN = false;
bool PRESSED_UP = false;
bool PRESSED_FIRE = false;

//////////////////////////
// INTERRUPT HANDLERS	//
//////////////////////////

void knopBoven(void) {
	PRESSED_UP = true;
}

void knopOnder(void) {
	PRESSED_DOWN = true;
}

void knopFire(void) {
	PRESSED_FIRE = true;
}

void beat(void) { //When the beat timer throws an interrupt
	playActiveSounds();

	//update beatIndex
	beatIndex = beatIndex + BeatArrLengte / (MaatMogelijkheden[maatIndex] * 4);
	if (beatIndex >= BeatArrLengte)
		beatIndex = 0;

	print_metronome(beatIndex / 4, BeatArrLengte / 4); //Per kwartnoot tonen
}

//////////
// INIT	//
//////////

void init() {
	initPeripherals(knopBoven, knopOnder, knopFire, beat);
	initStates();
}

//////////////////
// STATEMACHINE	//
//////////////////

void loop() {
	while (true) {
		switch (state) {
		case MENU:
			MENU_state(PRESSED_DOWN, PRESSED_UP, PRESSED_FIRE);
			break;
		case BPM_INST:
			BPM_INST_state(PRESSED_FIRE);
			break;
		case MAAT_INST:
			MAAT_INST_state(PRESSED_DOWN, PRESSED_UP, PRESSED_FIRE);
			break;
		case TRACK_MENU:
			TRACK_MENU_state(PRESSED_DOWN, PRESSED_UP, PRESSED_FIRE);
			break;
		case RESOLUTIE_INST:
			RESOLUTIE_INST_state(PRESSED_DOWN, PRESSED_UP, PRESSED_FIRE);
			break;
		case GELUID_INST:
			GELUID_INST_state(PRESSED_DOWN, PRESSED_UP, PRESSED_FIRE);
			break;
		case REC_PERCUSSIE:
			RECORDING(PRESSED_FIRE);
		}

		PRESSED_DOWN = false;
		PRESSED_UP = false;
		PRESSED_FIRE = false;
	}
}

//////////
// MAIN	//
//////////

void toplevel() {
	//printf("in toplevel \n\r");

	init();

	//testje voor Toplevel:
	for (uint8_t i = 0; i < BeatArrLengte; i++)
		tracks[0].beat[i] = (i % 4 == 0) ? true : false;

	tracks[0].geluidjesIndex = 0;
	tracks[0].active = true;

	while (1) {
		loop();
	}
}

