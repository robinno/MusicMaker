#include "topHeaders/StateFunctions.h"
#include "topHeaders/GLOBALS.h"
#include "topHeaders/Geluidjes.h"

//STATEMACHINE VARIABLES
//werkte niet in de .h files, dus alles moest in deze file. (Ik heb mr. Espeel geraadpleegd)
enum states {
	MENU,
	BPM_INST,
	MAAT_INST,
	TRACK_MENU,
	RESOLUTIE_INST,
	GELUID_INST,
	REC_PERCUSSIE
} huidigeState = MENU;

//ANDERE GLOBALS
bool recording = false;
uint8_t bpm_teller = 0;

//on every beat:
void playActiveSounds() {
	for (uint8_t i = 0; i < aantalTracks; i++)
		if (tracks[i].active && tracks[i].beat[beatIndex])
			playsound(tracks[i].geluidjesIndex);
}

void updateBeatIndex(){
	beatIndex = beatIndex + BeatArrLengte / (MaatMogelijkheden[maatIndex] * 4);
	if (beatIndex >= BeatArrLengte){
		beatIndex = 0;
		if(recording == true)
			recording = false;
	}
}

void printBeatIndexOnLCD(){
	//only update metronome every 4 beats: (per kwartnoot tonen)
	bpm_teller++;
	if(bpm_teller == 4){
		print_metronome(beatIndex, BeatArrLengte);
		bpm_teller = 0;
	}
}

//init functions:
void initPeripherals(void (*JS_UP_functie)(void), void (*JS_DOWN_functie)(void),
		void (*JS_FIRE_functie)(void), void (*BEAT_functie)(void)) {

	middleware_initJoyStick(UP, JS_UP_functie);
	middleware_initJoyStick(DOWN, JS_DOWN_functie);
	middleware_initJoyStick(FIRE, JS_FIRE_functie);
	initReadPot(minimumBPM, maximumBPM);
	initTimer0();
	Timer0SetIRQ(BEAT_functie);
	initRGB();
	middleware_init_LCD();

	//PASS TRACKS TO LOWER LEVEL:
	playsound_init(aantalGeluidjes, geluidjes);
}

void initStates() {
	//INIT MENU:
	menu.index = 0;

	sprintf(menu.titeltjes[0], "BPM instellen");
	sprintf(menu.titeltjes[1], "Maat instellen");
	for (int i = 0; i < aantalTracks; i++) {
		sprintf(menu.titeltjes[i + 2], "track %i menu", i);
	}

	//INIT BPM:
	startTimer0BPM(huidigeBPM);

	//INIT TRACKS:
	for (int i = 0; i < aantalTracks; i++){
		tracks[i].active = false;
		tracks[i].geluidjesIndex = i;
	}

	//starting state:
	goto_MENU();
}

//Functions for all states:

/////////////////////////////
//SWITCHING BETWEEN STATES://
/////////////////////////////

void goto_MENU() {
	huidigeState = MENU;
	print_menuName("MENU");
	print_menuItem(menu.titeltjes[menu.index]);
}

void goto_BPM_INST() {
	huidigeState = BPM_INST;
	print_menuName("BPM INSTELLEN");
}

void goto_MAAT_INST() {
	//clear all tracks:
	for (uint8_t i = 0; i < aantalTracks; i++) {
		tracks[i].active = false;
		for (uint8_t j = 0; j < BeatArrLengte; j++) {
			tracks[i].beat[j] = false;
		}
	}

	huidigeState = MAAT_INST;
	print_menuName("MAAT INSTELLEN");
	char maatTekst[16];
	sprintf(maatTekst, "maat = %i/4", MaatMogelijkheden[maatIndex]);
	print_menuItem(maatTekst);
}

void goto_TRACK_MENU() {
	huidigeState = TRACK_MENU;
	trackIndex = menu.index - 2;

	char trackMenuNaam[tekstlengte];
	sprintf(trackMenuNaam, "TRACK %i INST", trackIndex);
	print_menuName(trackMenuNaam);
	huidigTrackTiteltje = 0;
	print_menuItem(trackTiteltjes[huidigTrackTiteltje]);
}

void goto_RESOLUTIE_INST() {
	huidigeState = RESOLUTIE_INST;
	print_menuName("RESOLUTIE");
	print_menuItem(kwantisatieOpties[kwantisatie_index]->naam);
}

void goto_GELUID_INST() {
	huidigeState = GELUID_INST;
	print_menuName("GELUID");
	print_menuItem(geluidjes[tracks[trackIndex].geluidjesIndex]->name);
}

void goto_RECORDING() {
	huidigeState = REC_PERCUSSIE;
	print_menuName("RECORDING");
	print_menuItem("wait ...");

	while (beatIndex != 0)
		; //wacht tot in begin van de maat

	for (uint8_t i = 0; i < BeatArrLengte; i++) { //clear current content of track
		tracks[trackIndex].beat[i] = false;
	}
	setLED(RED, 1);
	print_menuItem("recording ...");
	recording = true;
}

bool checkIfEindeMaat() {
	bool einde = (beatIndex >= BeatArrLengte - 1);
	if (einde) {
		setLED(RED, 0);
	}
	return einde;
}

//////////////////
//STATES ITSELF://
//////////////////

void MENU_state(bool next, bool prev, bool select) {
	//update index
	if (next)
		menu.index = (menu.index + 1) % aantalMenuTiteltjes;
	if (prev)
		menu.index =
				(menu.index == 0) ?
						(aantalMenuTiteltjes - 1) : (menu.index - 1);

	//update display
	if (next || prev)
		print_menuItem(menu.titeltjes[menu.index]);

	//on select
	if (select) {
		switch (menu.index) {
		case 0: //BPM instellen
			goto_BPM_INST();
			break;
		case 1: //MAAT instellen
			goto_MAAT_INST();
			break;
		default: //ALLE TRACKS:
			goto_TRACK_MENU();
			break;
		}
	}
}

void BPM_INST_state(bool select) {
	//reset maat
	beatIndex = 0;

	huidigeBPM = readPot();

	char bpmTekst[16];
	sprintf(bpmTekst, "BPM = %i", huidigeBPM);
	print_menuItem(bpmTekst);

	if (select) {
		startTimer0BPM(huidigeBPM);
		goto_MENU();
	}
}

void MAAT_INST_state(bool next, bool prev, bool select) {
	//reset maat
	beatIndex = 0;

	//update index
	if (next)
		maatIndex = (maatIndex + 1) % aantalMaatSoorten;
	if (prev)
		maatIndex =
				(maatIndex == 0) ? (aantalMaatSoorten - 1) : (maatIndex - 1);

	//update display
	if (next || prev) {
		char maatTekst[16];
		sprintf(maatTekst, "maat = %i/4", MaatMogelijkheden[maatIndex]);
		print_menuItem(maatTekst);
	}

	//on select
	if (select)
		goto_MENU();
}

void TRACK_MENU_state(bool next, bool prev, bool select) {
	//update index
	if (next)
		huidigTrackTiteltje = (huidigTrackTiteltje + 1) % aantalTrackTiteltjes;
	if (prev)
		huidigTrackTiteltje =
				(huidigTrackTiteltje == 0) ?
						(aantalTrackTiteltjes - 1) : (huidigTrackTiteltje - 1);

	//update display
	if (next || prev)
		print_menuItem(trackTiteltjes[huidigTrackTiteltje]);

	//on select
	if (select) {
		switch (huidigTrackTiteltje) {
		case 0: //terug naar menu
			goto_MENU();
			break;
		case 1:
			tracks[trackIndex].active = !(tracks[trackIndex].active); //toggle active.
			break;
		case 2: //Kwantisatie
			goto_RESOLUTIE_INST();
			break;
		case 3: //geluidje:
			goto_GELUID_INST();
			break;
		case 4: //Record:
			goto_RECORDING();
			break;
		}
	}
}

void RESOLUTIE_INST_state(bool next, bool prev, bool select) {
	//update index
	if (next)
		kwantisatie_index = (kwantisatie_index + 1) % aantalKwantisatieOpties;
	if (prev)
		kwantisatie_index =
				(kwantisatie_index == 0) ?
						(aantalKwantisatieOpties - 1) : (kwantisatie_index - 1);
	//update display
	if (next || prev)
		print_menuItem(kwantisatieOpties[kwantisatie_index]->naam);

	//on select
	if (select) {
		tracks[trackIndex].kwantisatiePerAantalBeats =
				kwantisatieOpties[kwantisatie_index]->perAantalBeats;
		goto_TRACK_MENU();
	}
}

void GELUID_INST_state(bool next, bool prev, bool select) {
	//zet eigen active geluidje als false:
	geluidjes[tracks[trackIndex].geluidjesIndex]->active = false;

	//update index:
	if (next)
		do {
			tracks[trackIndex].geluidjesIndex =
					(tracks[trackIndex].geluidjesIndex + 1) % aantalGeluidjes;
		} while (geluidjes[tracks[trackIndex].geluidjesIndex]->active == true);

	if (prev)
		do {
			tracks[trackIndex].geluidjesIndex =
					(tracks[trackIndex].geluidjesIndex == 0) ?
							(aantalGeluidjes - 1) :
							(tracks[trackIndex].geluidjesIndex - 1);
		} while (geluidjes[tracks[trackIndex].geluidjesIndex]->active == true);

	//update display
	if (next || prev)
		print_menuItem(geluidjes[tracks[trackIndex].geluidjesIndex]->name);
	//on select;
	if (select)
		goto_TRACK_MENU();

	//zet geselecteerde active geluidje als true:
	geluidjes[tracks[trackIndex].geluidjesIndex]->active = true;
	tracks[trackIndex].active = true;
}

void RECORDING(bool hit) {
	if (hit) {
		//choose closest beat
		uint8_t rechtGetrokkenVoorKwantisatie =
				(timer0Value() < 0.5) ?
						beatIndex : (beatIndex + 1) % BeatArrLengte;

		//perform quantization:
		uint8_t deler = kwantisatieOpties[kwantisatie_index]->perAantalBeats;
		uint8_t middenVanInterval = (beatIndex / deler) * deler + (deler / 2);

		uint8_t naKwantisatie = 0;
		if (rechtGetrokkenVoorKwantisatie <= middenVanInterval) {
			naKwantisatie = (beatIndex / deler) * deler;
		} else {
			naKwantisatie = ((beatIndex / deler + 1) * deler) % BeatArrLengte;
		}

		//toekennen aan beat array voor die track
		tracks[trackIndex].beat[naKwantisatie] = true;

		//tracks[trackIndex].beat[naKwantisatie] = true;
	}

	if (recording == false)
		goto_TRACK_MENU();
}

//STATE MACHINE ITSELF
void stateMachine(bool next, bool prev, bool select){
	switch (huidigeState) {
			case MENU:
				MENU_state(next, prev, select);
				break;
			case BPM_INST:
				BPM_INST_state(select);
				break;
			case MAAT_INST:
				MAAT_INST_state(next, prev, select);
				break;
			case TRACK_MENU:
				TRACK_MENU_state(next, prev, select);
				break;
			case RESOLUTIE_INST:
				RESOLUTIE_INST_state(next, prev, select);
				break;
			case GELUID_INST:
				GELUID_INST_state(next, prev, select);
				break;
			case REC_PERCUSSIE:
				RECORDING(select);
			}
}
