#include "driverHeaders/DACdriver.h"


void DAC0_init() {
       SIM->SCGC2 |= (1<<12);   // clock to DAC module
       SIM->SCGC6 |= (1<<31);	//TODO: verkeerde wegdoen

       DAC0->C0 |= 0x80;	//enable DAC

       DAC0->C0 |= 0x20;     //use software trigger? or shall we use hardware trigger?
}
