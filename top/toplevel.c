#include "topHeaders/toplevel.h"

volatile bool PRESSED_DOWN = false;
volatile bool PRESSED_UP = false;
volatile bool PRESSED_FIRE = false;

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
	updateBeatIndex();
	printBeatIndexOnLCD();
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
		stateMachine(PRESSED_DOWN, PRESSED_UP, PRESSED_FIRE);

		PRESSED_DOWN = false;
		PRESSED_UP = false;
		PRESSED_FIRE = false;
	}
}

//////////
// MAIN	//
//////////

void toplevel() {
	//printf("in toplevel\n");
	init();
	//printf("init finished\n");
	while (1)
		loop();
}

