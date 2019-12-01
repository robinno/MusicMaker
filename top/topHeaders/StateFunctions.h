#include <stdbool.h>

#ifndef TOP_TOPHEADERS_STATEFUNCTIONS_H_
#define TOP_TOPHEADERS_STATEFUNCTIONS_H_

//INCLUDES
#include "../../middleware/middlewareHeaders/PlaySound.h"
#include "../../middleware/middlewareHeaders/ReadJoystick.h"
#include "../../middleware/middlewareHeaders/Timer0.h"
#include "../../middleware/middlewareHeaders/ReadPot.h"
#include "../../middleware/middlewareHeaders/WriteDisplay.h"
#include "../../middleware/middlewareHeaders/WriteLED.h"

#include "GLOBALS.h"
#include "Geluidjes.h"

//on every beat:
void playActiveSounds();

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


#endif
