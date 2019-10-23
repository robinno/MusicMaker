#include "driverHeaders/setLED.h"

/* LED's on port A */
int initLED_A(int ledNr){
	SIM->SCGC5 |= (1<<9); //enable Port B Clock Gate Control
	PORTA->PCR[ledNr] |= 0x100; //blue led, configured as Alternative 1 (GPIO)
	GPIOA->PDDR |= (1 << ledNr); //setting the bit 21 of the port B as output
	return 0;
}

int setLED_A(int ledNr, int on){
	if(on==1){
		GPIOA->PDOR |= (1 << ledNr);
	}else{
		GPIOA->PDOR &= ~(1<<ledNr);
	}
	return 0;
}

/* LED's on port B */
int initLED_B(int ledNr){
	SIM->SCGC5 |= (1<<10); //enable Port B Clock Gate Control
	PORTB->PCR[ledNr] |= 0x100; //blue led, configured as Alternative 1 (GPIO)
	GPIOB->PDDR |= (1 << ledNr); //setting the bit 21 of the port B as output
	return 0;
}

int setLED_B(int ledNr, int on){
	if(on==1){
		GPIOB->PDOR |= (1 << ledNr);
	}else{
		GPIOB->PDOR &= ~(1<<ledNr);
	}
	return 0;
}

/* LED's on port C */
int initLED_C(int ledNr){
	SIM->SCGC5 |= (1<<11); //enable Port C Clock Gate Control
	PORTC->PCR[ledNr] |= 0x100; //blue led, configured as Alternative 1 (GPIO)
	GPIOC->PDDR |= (1 << ledNr);
	return 0;
}
int setLED_C(int ledNr, int on){
	if(on==1){
		GPIOC->PDOR |= (1 << ledNr);
	}else{
		GPIOC->PDOR &= ~(1<<ledNr);
	}
	return 0;
}
