#include "./driverHeaders/setLED.h"

int initLED(){
	SIM->SCGC5 |= 0x400; //enable Port B Clock Gate Control
	PORTB->PCR[21] |= 0x100; //blue led, configured as Alternative 1 (GPIO)
	GPIOB->PDDR |= (1 << 21); //setting the bit 21 of the port B as output
	return 0;
}

int setLED(int on){
	if(on==1){
		GPIOB->PDOR |= (1 << 21);
	}else{
		GPIOB->PDOR &= !(1<<21);
	}
	return 0;
}
