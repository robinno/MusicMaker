#include "driverHeaders/setLED.h"

/* LED's on port A */
void initLED_A(uint8_t ledNr){
	SIM->SCGC5 |= (1<<9); //enable Port B Clock Gate Control
	PORTA->PCR[ledNr] |= 0x100; //blue led, configured as Alternative 1 (GPIO)
	GPIOA->PDDR |= (1 << ledNr); //setting the bit 21 of the port B as output
}

void setLED_A(uint8_t ledNr, uint8_t of){
	if(of==1){
		GPIOA->PDOR |= (1 << ledNr);
	}else{
		GPIOA->PDOR &= ~(1<<ledNr);
	}
}

/* LED's on port B */
void initLED_B(uint8_t ledNr){
	SIM->SCGC5 |= (1<<10); //enable Port B Clock Gate Control
	PORTB->PCR[ledNr] |= 0x100; //blue led, configured as Alternative 1 (GPIO)
	GPIOB->PDDR |= (1 << ledNr); //setting the bit 21 of the port B as output
}

void setLED_B(uint8_t ledNr, uint8_t of){
	if(of==1){
		GPIOB->PDOR |= (1 << ledNr);
	}else{
		GPIOB->PDOR &= ~(1<<ledNr);
	}
}

/* LED's on port C */
void initLED_C(uint8_t ledNr){
	SIM->SCGC5 |= (1<<11); //enable Port C Clock Gate Control
	PORTC->PCR[ledNr] |= 0x100; //blue led, configured as Alternative 1 (GPIO)
	GPIOC->PDDR |= (1 << ledNr);
}
void setLED_C(uint8_t ledNr, uint8_t of){
	if(of==1){
		GPIOC->PDOR |= (1 << ledNr);
	}else{
		GPIOC->PDOR &= ~(1<<ledNr);
	}
}
