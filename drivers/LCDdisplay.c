#include "driverHeaders/LCDdisplay.h"
const uint8_t nr_columns = 128;

void init_LCD() {
	initSPI();

	display_OnOff(0);
	pushSPI(0, 0xA2);   //  bias voltage (1/9)
	pushSPI(0, 0xA0);   //ADC select normal
	pushSPI(0, 0xC0);   //  COM normal
	pushSPI(0, 0x2F);   //  operating mode
	pushSPI(0, 0x22);   //  voltage resistor ratio
	pushSPI(0, 0x81);   //  electronic volume mode set
	pushSPI(0, 0x10);   //  set most significant 4b of ram column adr
	pushSPI(0, 0x00);   //  set least significant 4b of ram column adr
	pushSPI(0, 0xA6);    // display normal
	pushSPI(0, 0x40);   // start line = 0
	display_OnOff(1);
	//printf("Init LCD done\n");
}

void print_text(uint8_t page, char string[]) {   //strlen(str)
	uint8_t strLength = strlen(string);
	if (page < 4) {
		pushSPI(0, 0x00);      // set column low nibble 0
		pushSPI(0, 0x10);      // set column hi  nibble 0
		pushSPI(0, 0xB0 | page);      // set page address to page
		strLength = (strLength > nr_columns / 8) ? nr_columns / 8 : strLength; //print no more than there is screen
		for (uint8_t i = 0; i < strLength; i++) {      //print string
			uint32_t fontIndex = string[i] - 32; //first entry in font table is ascii 32 (= space)
			for (uint8_t j = 0; j < 8; j++) {
				pushSPI(1, FONT8x8[fontIndex][j]); //print colomn
			}
		}
		for (uint8_t i = strLength; i < nr_columns; i++) {
			pushSPI(1, 0x00); //fill rest of line whit zeros
		}
	}
}

void print_line(uint8_t ratio) {
	uint8_t width = (ratio >= nr_columns) ? nr_columns - 1 : ratio;
	pushSPI(0, 0x00);      // set column low nibble 0
	pushSPI(0, 0x10);      // set column hi  nibble 0
	pushSPI(0, 0xB0);      // set page address to 0
	for (uint8_t i = 0; i < width; i++) {
		pushSPI(1, 0x7e);      //print colomn
	}
	for (uint8_t i = width; i < nr_columns; i++) {
		pushSPI(1, 0x18);      //print colomn
	}
}

void print_stripe(uint8_t page) {
	pushSPI(0, 0x00);      // set column low nibble 0
	pushSPI(0, 0x10);      // set column hi  nibble 0
	pushSPI(0, 0xB0 | page);      // set page address to page
	for (uint8_t i = 0; i < nr_columns; i++) {
		pushSPI(1, 0x18);      //print colomn
	}
}
