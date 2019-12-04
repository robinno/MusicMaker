#ifndef STATEFUNCTIONS_H
#define STATEFUNCTIONS_H

#include <stdint.h>
#include <stdbool.h>
#include "fsl_debug_console.h"

#include "../../middleware/middlewareHeaders/PlaySound.h"
#include "../../middleware/middlewareHeaders/ReadJoystick.h"
#include "../../middleware/middlewareHeaders/Timer0.h"
#include "../../middleware/middlewareHeaders/ReadPot.h"
#include "../../middleware/middlewareHeaders/WriteDisplay.h"
#include "../../middleware/middlewareHeaders/WriteLED.h"

//STATEMACHINE variables:
enum states {
	MENU,
	BPM_INST,
	MAAT_INST,
	TRACK_MENU,
	RESOLUTIE_INST,
	GELUID_INST,
	REC_PERCUSSIE
} huidigeState = MENU;

uint8_t test = 0;
int hallo = 0;
int test2;

//on every beat:
void playActiveSounds();
void updateBeatIndex();
void printBeatIndexOnLCD();

//init functions:
void initPeripherals(void (*JS_UP_functie)(void), void (*JS_DOWN_functie)(void),
		void (*JS_FIRE_functie)(void), void (*BEAT_functie)(void));
void initStates();

//Functions for all states:
//SWITCHING BETWEEN STATES:
void goto_MENU();
void goto_BPM_INST();
void goto_MAAT_INST();
void goto_TRACK_MENU();
void goto_RESOLUTIE_INST();
void goto_GELUID_INST();
void goto_RECORDING(); //wacht tot de volgende maat begint
bool checkIfEindeMaat();

//STATES ITSELF:
void MENU_state(bool next, bool prev, bool select);
void BPM_INST_state(bool select);
void MAAT_INST_state(bool next, bool prev, bool select);
void TRACK_MENU_state(bool next, bool prev, bool select);
void RESOLUTIE_INST_state(bool next, bool prev, bool select);
void GELUID_INST_state(bool next, bool prev, bool select);
void RECORDING(bool hit);

//STATE MACHINE ITSELF
void stateMachine(bool next, bool prev, bool select); //ik kon niet van 2 plaatsen aan de header file, dus dit moest hierbij

#endif
