#include "driverHeaders/LCDdisplay.h"

void init_LCD() {
	initSPI();
	pushSPI(0, 0xAE);   //  display off
	pushSPI(0, 0xA2);   //  bias voltage

	pushSPI(0, 0xA0);
	pushSPI(0, 0xC8);   //  colum normal

	pushSPI(0, 0x22);   //  voltage resistor ratio
	pushSPI(0, 0x2F);   //  power on
	//wr_cmd(0xA4);   //  LCD display ram
	pushSPI(0, 0x40);   // start line = 0
	pushSPI(0, 0xAF);     // display ON

	pushSPI(0, 0x81);   //  set contrast
	pushSPI(0, 0x17);   //  set contrast

	pushSPI(0, 0xA6);     // display normal
	printf("Init LCD done\n");
}
