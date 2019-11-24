#include "driverHeaders/LCDcommands.h"


void display_OnOff(int on){ //0 for off, 1 for on
	uint8_t teVersturen;

	if(on == 1)
		teVersturen = 0xAF;
	else
		teVersturen = 0xAE;

	pushSPI(0, teVersturen);
}

void display_startLineSet(uint8_t StartAddr){
	uint8_t teVersturen = 0x40 | (StartAddr & 0x3F);
	pushSPI(0, teVersturen);
}

void display_setPageAddress(uint8_t pageAddr){
	uint8_t teVersturen = 0xB0 | (pageAddr & 0xF);
	pushSPI(0, teVersturen);
}

void display_setColumnAddr(uint8_t columnAddr){
	uint8_t teVersturen = 0x10 | (columnAddr >> 4); //most significant 4 bits
	pushSPI(0, teVersturen);
	teVersturen = (columnAddr & 0xF); //least significant 4 bits
	pushSPI(0, teVersturen);
}

void display_dataWrite(uint8_t data){
	pushSPI(1, data);
}

void display_allPoints(int on){ //0 for normal mode, 1 for all points on
	uint8_t teVersturen;

	if(on == 1)
		teVersturen = 0xA5;
	else
		teVersturen = 0xA4;

	pushSPI(0, teVersturen);
}

void display_reset(){
	pushSPI(0, 0xE2);
}

void display_NOP(){
	pushSPI(0, 0xE3);
}
