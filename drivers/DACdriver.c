#include "driverHeaders/DACdriver.h"

void DAC0_init() {
	SIM->SCGC2 |= (1 << 12);  //clock to DAC module

	DAC0->C0 |= (1 << 7);		//enable DAC
	DAC0->C0 |= (1 << 6);		//selecting Vref
	DAC0->C0 |= (1 << 5);		//enable software trigger
}

void DAC0_set(uint16_t value) { //eigenlijk 12 bits breed.

	DAC0->DAT[0].DATL = (uint8_t) (value & 0xFF); //enkel de laagste byte
	DAC0->DAT[0].DATH = (uint8_t) (value >> 8 & 0xF); //van de hoogste byte enkel de onderste 4 bits.

	//trigger the conversion
	DAC0->C0 |= (1 << 4);     //use software trigger and update output
}
