#include "topHeaders/toplevel.h"

bool PRESSED_DOWN = false;
bool PRESSED_UP = false;
bool PRESSED_FIRE = false;

#define state_refresh_rate_ms 20

//delay function
void delay_to_refresh() {
	for (long i = 0; i < 1700 * state_refresh_rate_ms; i++)
		;
}

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
		delay_to_refresh();

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

