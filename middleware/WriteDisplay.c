#include "middlewareHeaders/WriteDisplay.h"
#define maxChars 16

void print_menuName(char menuname[]){
	char centered[] = "                ";//{' '};//maxChars+1
	//centered[16] = '\n';
	printf("1S%sE\n", centered);
	printf("1strlen= %d\n", strlen(centered));
	uint8_t menunameLength = (strlen(menuname) > maxChars)? maxChars : strlen(menuname);
	printf("menuname=%s\n",menuname);
	printf("strlen= %d\n", menunameLength);
	uint8_t blanks = maxChars - menunameLength;
	printf("blanks=%d\n", blanks);
	for(uint8_t i=0; i < strlen(menuname); i++){
		centered[i+blanks/2] = menuname[i];
	}
	printf("S%sE\n", centered);
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
