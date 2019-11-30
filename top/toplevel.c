#include <stdbool.h>
#include <stdint.h>
#include "topHeaders/toplevel.h"
#include "topHeaders/GLOBALS.h"
#include "topHeaders/Geluidjes.h"

bool PRESSED_DOWN = false;
bool PRESSED_UP = false;
bool PRESSED_FIRE = false;

uint8_t trackIndex = 0;
uint8_t beatIndex = 0;

char trackMenuNaam[] = "TRACK   INST";
#define trackIndexPosInMenuNaam 6

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
	for (uint8_t i = 0; i < aantalTracks; i++)
		if (tracks[i].active && tracks[i].beat[beatIndex])
			playsound(tracks[i].geluidjesIndex);

	beatIndex = (beatIndex + 1) % BeatArrLengte;
}

//////////
// INIT	//
//////////

void init() {
	//INIT peripherals:
	//TODO: init joystick
	initReadPot(minimumBPM, maximumBPM);
	initTimer0();
	Timer0SetIRQ(beat);
	initRGB();
	middleware_init_LCD();

	//INIT MENU:
	menu.index = 0;

	sprintf(menu.titeltjes[0], "BPM instellen");
	sprintf(menu.titeltjes[1], "Maat instellen");
	for (int i = 0; i < aantalTracks; i++) {
		sprintf(menu.titeltjes[i + 2], "track %i menu", i);
	}

	//INIT BPM:
	startTimer0((uint16_t) (((uint32_t) huidigeBPM * 1000000) / 60));

	//INIT TRACKS:
	for (int i = 0; i < aantalTracks; i++) {
		tracks[i].active = false;
	}

	//INIT RECORD:
	setLED(RED, 0);

	//PASS TRACKS TO LOWER LEVEL:
	playsound_init(aantalGeluidjes, geluidjes);

	//starting state:
	print_menuName("MENU");
	print_menuItem(menu.titeltjes[menu.index]);
	state = MENU;
}

//////////////////
// STATEMACHINE	//
//////////////////

void loop() {
	uint8_t vorigeBPM = 0;

	while (true) {
		switch (state) {
		case MENU:
			if (PRESSED_DOWN) {
				menu.index = (menu.index + 1) % aantalMenuTiteltjes;
				print_menuItem(menu.titeltjes[menu.index]);
			}
			if (PRESSED_UP) {
				menu.index =
						(menu.index == 0) ?
								(aantalMenuTiteltjes - 1) : (menu.index - 1);
				print_menuItem(menu.titeltjes[menu.index]);
			}
			if (PRESSED_FIRE) {
				switch (menu.index) {
				case 0: //BPM instellen
					state = BPM_INST;
					print_menuName("BPM INSTELLEN");
					break;
				case 1: //MAAT instellen
					state = MAAT_INST;
					print_menuName("MAAT INSTELLEN");
					break;
				default: //ALLE TRACKS:
					state = TRACK_MENU;
					trackIndex = menu.index - 2;

					trackMenuNaam[trackIndexPosInMenuNaam] = trackIndex + 48; //naar ASCII cijfer
					print_menuName(trackMenuNaam);
					break;
				}
			}
			break;
		case BPM_INST:
			huidigeBPM = readPot();
			if (huidigeBPM != vorigeBPM) //Edge detectie: timer en scherm updaten als nodig.
				startTimer0(
						(uint16_t) (((uint32_t) huidigeBPM * 1000000) / 60));

			if (PRESSED_FIRE) {
				state = MENU;
				print_menuName("MENU");
			}

			vorigeBPM = huidigeBPM;
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
				print_menuName("MENU");
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
					print_menuName("MENU");
					break;
				case 1:
					tracks[trackIndex].active = !(tracks[trackIndex].active); //toggle active.
					break;
				case 2: //Kwantisatie
					state = RESOLUTIE_INST;
					print_menuName("RESOLUTIE");
					break;
				case 3: //geluidje:
					state = GELUID_INST;
					print_menuName("GELUID");
					break;
				case 4: //Record:
					state = REC_PERCUSSIE;
					print_menuName("RECORDING");
					break;
				}
			}
			//show on LCD
			break;
		case RESOLUTIE_INST:
			if (PRESSED_DOWN) {
				kwantisatie_index = (kwantisatie_index + 1)
						% aantalKwantisatieOpties;
			}
			if (PRESSED_UP) {
				kwantisatie_index =
						(kwantisatie_index == 0) ?
								(aantalKwantisatieOpties - 1) :
								(kwantisatie_index - 1);
			}
			if (PRESSED_FIRE) {
				state = TRACK_MENU;
				tracks[trackIndex].kwantisatiePerAantalBeats =
						kwantisatieOpties[kwantisatie_index]->perAantalBeats;
				print_menuName(trackMenuNaam);
			}
			break;
		case GELUID_INST:
			//zet eigen active geluidje als false:
			geluidjes[tracks[trackIndex].geluidjesIndex]->active = false;

			if (PRESSED_DOWN) {
				do {
					tracks[trackIndex].geluidjesIndex =
							(tracks[trackIndex].geluidjesIndex + 1)
									% aantalGeluidjes;
				} while (geluidjes[tracks[trackIndex].geluidjesIndex]->active
						== true);
			}
			if (PRESSED_UP) {
				do {
					tracks[trackIndex].geluidjesIndex =
							(tracks[trackIndex].geluidjesIndex == 0) ?
									(aantalGeluidjes - 1) :
									(tracks[trackIndex].geluidjesIndex - 1);
				} while (geluidjes[tracks[trackIndex].geluidjesIndex]->active
						== true);
			}
			if (PRESSED_FIRE) {
				state = TRACK_MENU;
				print_menuName(trackMenuNaam);
			}

			//zet geselecteerde active geluidje als true:
			geluidjes[tracks[trackIndex].geluidjesIndex]->active = true;
			tracks[trackIndex].active = true;
			break;
		case REC_PERCUSSIE:
			//wachten met record tot start van de maat:
			if (beatIndex == 0) {
				recording = true;
				for (uint8_t i = 0; i < BeatArrLengte; i++) { //clear current content of track
					tracks[trackIndex].beat[i] = false;
				}
				setLED(RED, 1);
			} else if (beatIndex >= BeatArrLengte - 1) {
				recording = false;
				setLED(RED, 0);
				state = TRACK_MENU;
				print_menuName(trackMenuNaam);
			}

			//When recording:
			if (recording) {
				if (PRESSED_FIRE) {
					//choose closest beat
					uint8_t rechtGetrokkenVoorKwantisatie =
							(timer0Value() < 0.5) ?
									beatIndex : (beatIndex + 1) % BeatArrLengte;

					//perform quantization:
					uint8_t deler =
							kwantisatieOpties[kwantisatie_index]->perAantalBeats;
					uint8_t middenVanInterval = (beatIndex / deler) * deler
							+ (deler / 2);

					uint8_t naKwantisatie = 0;
					if (rechtGetrokkenVoorKwantisatie <= middenVanInterval) {
						naKwantisatie = (beatIndex / deler) * deler;
					} else {
						naKwantisatie = ((beatIndex / deler + 1) * deler)
								% BeatArrLengte;
					}

					//toekennen aan beat array voor die track
					tracks[trackIndex].beat[naKwantisatie] = true;
				}
			}
			break;
		}

		PRESSED_DOWN = false;
		PRESSED_UP = false;
		PRESSED_FIRE = false;
	}
}

//////////
// MAIN	//
//////////

void toplevel() {
	//printf("in toplevel \n\r");

	//korte test:
	middleware_init_LCD();
	print_menuName("MENU");

//	init();
//	while(1){
//		loop();
//	}
}

