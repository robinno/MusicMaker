#include "topHeaders/toplevel.h"
#include "topHeaders/Geluidjes.h"
#include <stdbool.h>

bool PRESSED_DOWN = false;
bool PRESSED_UP = false;
bool PRESSED_FIRE = false;
bool loop = false;

uint8_t huidigeMenuTitel = 0;
uint8_t track = 0;

//////////////////
// STATEMACHINE	//
//////////////////

//INIT stateVars:
void initstates(){
	//menutiteltjes:
	MENU_titeltjes[0] = "BPM instellen";
	MENU_titeltjes[1] = "Maat instellen";
	MENU_titeltjes[2] = "spelende tracks";
	for(int i = 0; i < aantalTracks; i++){
		sprintf(MENU_titeltjes[i], "track %i menu", someInt);
	}
}

void state_machine_opInterrupt(){
	do{
		loop = false;

		switch(state){
			case MENU:
				if(PRESSED_DOWN){
					huidigeMenuTitel = (huidigeMenuTitel + 1) % AantalMenuTiteltjes;
				}
				if(PRESSED_UP){
					huidigeMenuTitel = (huidigeMenuTitel == 0) ? (AantalMenuTiteltjes - 1) : (huidigeMenuTitel - 1);
				}
				if(PRESSED_FIRE){
					switch(huidigeMenuTitel){
						case 0: //BPM instellen
							state = BPM_INST;
							break;
						case 1: //MAAT instellen
							state = MAAT_INST;
							break;
						case 2: //SPELENDE TRACKS instellen
							state = SPELENDE_TRACKS_INST;
							break;
						default: //ALLE TRACKS:
							state = TRACK_MENU;
							track = huidigeMenuTitel - 3;
							break;
					}

					loop = true; //redo the switch(state)
				}

				//show MENU_titeltjes[huidigeMenuTitel] op LCD
				break;
			case BPM_INST:

				break;
			case MAAT_INST:

				break;
			case SPELENDE_TRACKS_INST:

				break;
			case TRACK_MENU:

				break;
			case RESOLUTIE_INST:

				break;
			case GELUID_INST:

				break;
			case REC_PERCUSSIE:

				break;
		}

		PRESSED_DOWN = false;
		PRESSED_UP = false;
		PRESSED_FIRE = false;
	}while(loop);
}


//////////////////////////
// INTERRUPT HANDLERS	//
//////////////////////////


void knopBoven(void){
	PRESSED_UP = true;
	state_machine_opInterrupt();
}

void knopOnder(void){
	PRESSED_DOWN = true;
	state_machine_opInterrupt();
}

void knopFire(void){
	PRESSED_FIRE = true;
	state_machine_opInterrupt();
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

	while(1); //wait loop.
}

