#include "topHeaders/toplevel.h"
#include "topHeaders/Geluidjes.h"
#include "topHeaders/GLOBALS.h"
#include <stdbool.h>

bool PRESSED_DOWN = false;
bool PRESSED_UP = false;
bool PRESSED_FIRE = false;

uint8_t trackIndex = 0;

void init() {
	//INIT peripherals:
	initReadPot(minimumBPM, maximumBPM);

	//INIT MENU:
	menu.index = 0;

	sprintf(menu.titeltjes[0], "BPM instellen");
	sprintf(menu.titeltjes[1], "Maat instellen");
	for (int i = 0; i < aantalTracks; i++) {
		sprintf(menu.titeltjes[i + 2], "track %i menu", i);
	}

	//INIT TRACKS:
	for (int i = 0; i < aantalTracks; i++) {
		tracks[i] = false;
	}
}

//////////////////
// STATEMACHINE	//
//////////////////

void loop() {
	while (true) {
		switch (state) {
		case MENU:
			if (PRESSED_DOWN) {
				menu.index = (menu.index + 1) % aantalMenuTiteltjes;
			}
			if (PRESSED_UP) {
				menu.index =
						(menu.index == 0) ?
								(aantalMenuTiteltjes - 1) : (menu.index - 1);
			}
			if (PRESSED_FIRE) {
				switch (menu.index) {
				case 0: //BPM instellen
					state = BPM_INST;
					break;
				case 1: //MAAT instellen
					state = MAAT_INST;
					break;
				default: //ALLE TRACKS:
					state = TRACK_MENU;
					trackIndex = menu.index - 2;
					break;
				}
			}

			//show MENU_titeltjes[huidigeMenuTitel] op LCD
			break;
		case BPM_INST:
			huidigeBPM = readPot();
			if (PRESSED_FIRE) {
				state = MENU;
			}
			//show on LCD
			break;
		case MAAT_INST:
			if (PRESSED_DOWN) {
				maatIndex = (maatIndex + 1) % aantalMaatSoorten;
			}
			if (PRESSED_UP) {
				maatIndex =
						(maatIndex == 0) ?
								(aantalMaatSoorten - 1) : (maatIndex - 1);
			}
			if (PRESSED_FIRE) {
				state = MENU;
			}
			//show on LCD
			break;
		case TRACK_MENU:
			if (PRESSED_DOWN) {
				huidigTrackTiteltje = (huidigTrackTiteltje + 1)
						% aantalTrackTiteltjes;
			}
			if (PRESSED_UP) {
				huidigTrackTiteltje =
						(huidigTrackTiteltje == 0) ?
								(aantalTrackTiteltjes - 1) :
								(huidigTrackTiteltje - 1);
			}
			if (PRESSED_FIRE) {
				switch (huidigTrackTiteltje) {
				case 0: //terug naar menu
					state = MENU;
					break;
				case 1: //Kwantisatie
					state = RESOLUTIE_INST;
					break;
				case 2: //geluidje:
					state = GELUID_INST;
					break;
				case 3: //Record:
					state = REC_PERCUSSIE
					break;
				}
			}
			//show on LCD
			break;
		case RESOLUTIE_INST:
			//TODO
			break;
		case GELUID_INST:
			//TODO
			break;
		case REC_PERCUSSIE:
			//TODO
			break;
		}

		PRESSED_DOWN = false;
		PRESSED_UP = false;
		PRESSED_FIRE = false;
	}
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

//////////
// MAIN	//
//////////

void toplevel() {
	printf("in toplevel \n\r");

	init_LCD();
	print_Line(3, "", 0);
	print_Line(2, "Kijk Robin!!", 12);
	print_Line(1, "", 0);
	print_Line(0, "", 0);

	init();
	while (1)
		printf("%i\n", readPot());

	while (1)
		; //wait loop.
}

