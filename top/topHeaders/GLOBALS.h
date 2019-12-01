#include <stdbool.h>

#ifndef TOP_TOPHEADERS_GLOBALS_H_
#define TOP_TOPHEADERS_GLOBALS_H_

#define aantalTracks 4
#define tekstlengte 16
#define BeatArrLengte 48 * 4

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
	uint8_t kwantisatiePerAantalBeats;
	bool beat[BeatArrLengte];
} tracks[aantalTracks];

//////////////////////
// STATE variables:	//
//////////////////////

//STATE Menu:
#define aantalMenuTiteltjes (aantalTracks + 2)
struct {
	char titeltjes[aantalMenuTiteltjes][tekstlengte];
	uint8_t index;
} menu;

//STATE BPM_inst
#define minimumBPM 40
#define maximumBPM 240
uint8_t huidigeBPM = 100;

//STATE maat_inst
#define aantalMaatSoorten 6
const uint8_t MaatMogelijkheden[] = {3, 4, 6, 8, 12, 16};
uint8_t maatIndex = 0;

//STATE track_menu
#define aantalTrackTiteltjes 5
char trackTiteltjes[aantalTrackTiteltjes][tekstlengte] = {"Terug", "actief", "Kwantisatie", "Geluidje", "Record ..."};
uint8_t huidigTrackTiteltje = 0;

//STATE resolutie_inst
struct kwantisatie {
	char naam[tekstlengte];
	uint8_t perAantalBeats;
};
#define kwartnoot (struct kwantisatie){"kwartnoot", 4}
#define achtstenoot (struct kwantisatie){"achtstenoot", 2}
#define zestiendenoot (struct kwantisatie){"zestiendenoot", 1}
#define aantalKwantisatieOpties 3
struct kwantisatie* kwantisatieOpties[aantalKwantisatieOpties] = {&kwartnoot, &achtstenoot, &zestiendenoot};
uint8_t kwantisatie_index = 0;

//STATE recording
bool recording = false;

#endif /* TOP_TOPHEADERS_GLOBALS_H_ */
