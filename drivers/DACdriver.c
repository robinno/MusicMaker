#include "driverHeaders/DACdriver.h"


void DAC0_init() {
       SIM->SCGC2 |= (1<<12);   // clock to DAC module
       SIM->SCGC6 |= (1<<31);	//TODO: verkeerde wegdoen

       DAC0->C0 |= 0x80;	//enable DAC

       DAC0->C0 |= 0x20;     //use software trigger? or shall we use hardware trigger?
}

void DAC0_set(uint16_t value){ //eigenlijk 12 bits breed.
	DAC0->DAT[0].DATL = (uint8_t) (value & 0xFF); //enkel de laagste byte
	DAC0->DAT[0].DATH = (uint8_t) (value >> 8 & 0xF); //van de hoogste byte enkel de onderste 4 bits.
}
