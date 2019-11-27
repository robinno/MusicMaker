#include "middlewareHeaders/WriteDisplay.h"

void print_menuName(char menuname[]){
	char centered[17] = {0};
	centered[16] = '\n';
	uint8_t blanks = 16 - strlen(menuname);
	printf("blanks= %d\n", blanks);
	for(uint8_t i=0; i < strlen(menuname); i++){
		centered[i+blanks/2] = menuname[i];
	}
	print_text(3, centered);
	printf("S%sE\n", centered);
}


void middleware_init_LCD(){
	init_LCD();
	print_stripe(2);
}

void print_metronome(uint8_t teller, uint8_t beatsInMaat){
	print_line((teller+1) * 128/beatsInMaat);
}
