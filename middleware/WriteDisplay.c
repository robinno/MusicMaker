#include "middlewareHeaders/WriteDisplay.h"
#define maxChars 16

void print_menuName(char menuname[]){
	char centered[17] = {' '};
	centered[maxChars] = '\n';
	uint8_t menunameLength = (strlen(menuname) > maxChars)? maxChars : strlen(menuname);
	uint8_t blanks = maxChars - menunameLength;
	for(uint8_t i=0; i < strlen(menuname); i++){
		centered[i+blanks/2] = menuname[i];
	}
	print_text(3, centered);
}


void middleware_init_LCD(){
	init_LCD();
	print_stripe(2);
}

void print_metronome(uint8_t teller, uint8_t beatsInMaat){
	print_line((teller+1) * 128/beatsInMaat);
}

void print_menuItem(char menuItem[]){
	print_text(1, menuItem);
}
