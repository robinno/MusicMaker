#ifndef TOP_TOPHEADERS_GLOBALS_H
#define TOP_TOPHEADERS_GLOBALS_H

#include <stdbool.h>
#include <stdint.h>

#define aantalTracks 4
#define tekstlengte 16
#define BeatArrLengte 48 * 4

//struct for tracks:
struct {
	bool active;
	uint8_t geluidjesIndex;
	uint8_t kwantisatiePerAantalBeats;
	bool beat[BeatArrLengte];
} tracks[aantalTracks];

uint8_t trackIndex = 0;
volatile uint8_t beatIndex = 0;

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

#endif /* TOP_TOPHEADERS_GLOBALS_H_ */
