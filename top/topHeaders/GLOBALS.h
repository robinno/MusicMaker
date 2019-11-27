#include <stdbool.h>

#ifndef TOP_TOPHEADERS_GLOBALS_H_
#define TOP_TOPHEADERS_GLOBALS_H_

#define aantalTracks 4

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

//struct for tracks:
struct {
	bool active;
	uint8_t geluidjesIndex;
} tracks[aantalTracks];

//////////////////////
// STATE variables:	//
//////////////////////

//STATE Menu:
#define aantalMenuTiteltjes (aantalTracks + 2)
#define tekstlengte 14
struct {
	char titeltjes[aantalMenuTiteltjes][tekstlengte];
	uint8_t index;
} menu;

//STATE BPM_inst
#define minimumBPM 40
#define maximumBPM 240
uint8_t huidigeBPM;

//STATE maat_inst
#define aantalMaatSoorten 6
#define MaatMogelijkheden {3, 4, 6, 8, 12, 16}
uint8_t maatIndex = 0;

//STATE track_menu
#define aantalTrackTiteltjes 5
#define trackTiteltjes {"Terug", "actief", "Kwantisatie", "Geluidje", "Record ..."}
uint8_t huidigTrackTiteltje = 0;

#endif /* TOP_TOPHEADERS_GLOBALS_H_ */
