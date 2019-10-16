#include "driverHeaders/PotInput.h"

void initPot() {
	//Set GPIO pin as input
	SIM->SIM_SCGC5 |= 0x0400; //system clockgating for block B
	//PORTB->PCR[2] = 0x100;    //set pin 2 as GPIO (multiplexer)
	GPIOB->PDDR |= (0 << 2);   //set pin 2 as input

	///ADC:
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK; // enable the ADC clock

	///ADC config:
	//mode : "0b11" =single ended 16bit conversion with 2's complement
	//mode field = bit 3 and 2 of ADCx_CGF1
	ADC0_CFG1 |= 0xC; //sets ADC to 16bit

	//ADC channel input and single ended, interrupts, ...
	//ADCH field = "0b11111" = module is disabled
	ADC0_SC1A |= 0x1F;

}

int16_t getPotInput() {
	//0b01100 selects AD12 which is default after multiplexing PTB2
	ADC0_SC1A = 0b01100 ADC_SC1_ADCH_MASK; //Write to SC1A to start conversion
	//While conversion in progress, ADACT flag is not raised
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK); //Conversion in progress
	//COCO = conversion complete flag.
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); //Wait until conversion complete
	return ADC0_RA; //reads data corresponding to ADC measurement
}
