#include "driverHeaders/LCDdisplay.h"

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
	printf("Init LCD done\n");
}

void print_Line(int page, char string[], int strLength) {
	pushSPI(0, 0x00);      // set column low nibble 0
	pushSPI(0, 0x10);      // set column hi  nibble 0
	pushSPI(0, 0xB0 | page);      // set page address  0
	pushSPI(1, FONT8x8[34][col % 8]);
}

printf("print_LCD\n");
}
