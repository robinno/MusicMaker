#ifndef TOP_TOPHEADERS_STATES_H_
#define TOP_TOPHEADERS_STATES_H_

#include <stdint.h>

//STATEMACHINE variables:
enum states {
	MENU,
	BPM_INST,
	MAAT_INST,
	TRACK_MENU,
	RESOLUTIE_INST,
	GELUID_INST,
	REC_PERCUSSIE
};
uint8_t state = MENU;

#endif /* TOP_TOPHEADERS_STATES_H_ */
