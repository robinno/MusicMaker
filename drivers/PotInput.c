#include "driverHeaders/PotInput.h"

void initPot() {
	//Set GPIO pin as input
	SIM->SCGC5 |= 0x0400; //system clockgating for block B
	GPIOB->PDDR |= (0 << 2);   //set pin 2 as input

	//ADC:
	SIM->SCGC6 |= (1<<27); // enable the ADC clock

	//ADC configuration:
	//mode : "0b11" =single ended 16bit conversion with 2's complement
	//mode field = bit 3 and 2 of ADCx_CGF1
	ADC0->CFG1 |= 0xC; //sets ADC to 16bit

	//ADC channel input and single ended, interrupts, ...
	//ADCH field = "0b11111" = module is disabled
	ADC0->SC1[0] |= 0x1F;
}

uint16_t getPotInput() {
	//0b01100 selects AD12 which is default after multiplexing PTB2
	ADC0->SC1[0] = 0b01100; //Write to SC1A to start conversion
	//While conversion in progress, ADACT flag is not raised
	while(ADC0->SC2); //Conversion in progress
	//COCO = conversion complete flag.
	while(!(ADC0->SC1[0])); //Wait until conversion complete
	return (uint16_t) *(ADC0->R); //reads data corresponding to ADC measurement
}
