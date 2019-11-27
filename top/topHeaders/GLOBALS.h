#ifndef TOP_TOPHEADERS_GLOBALS_H_
#define TOP_TOPHEADERS_GLOBALS_H_

#define aantalTracks 4

//STATEMACHINE variables:
enum states{MENU, BPM_INST, MAAT_INST, SPELENDE_TRACKS_INST, TRACK_MENU, RESOLUTIE_INST, GELUID_INST, REC_PERCUSSIE};
uint8_t state = MENU;

//////////////////////
// STATE variables:	//
//////////////////////

//STATE Menu:
#define aantalMenuTiteltjes (aantalTracks + 3)
#define tekstlengte 15

struct{
	char titeltjes[aantalMenuTiteltjes][tekstlengte];
	uint8_t index;
}menu;

//STATE BPM_inst
#define minimumBPM 40
uint8_t huidigeBPM = 100;
#define maximumBPM 240

//STATE maat_inst
//TODO

//WHEN a selected track menu:
uint8_t selected_track = 0;

#endif /* TOP_TOPHEADERS_GLOBALS_H_ */
