#include "./topHeaders/toplevel.h"

void delay() {
	for (long i = 0; i < 1000000; i++) {
	}
}

void toplevel() {
	printf("in toplevel \n\r");

//	SIM->SCGC5 |= 0x400; //enable Port B Clock Gate Control
//	PORTB->PCR[21] = 0x100; //blue led, configured as Alternative 1 (GPIO)
//	GPIOB->PDDR |= (1 << 21); //setting the bit 21 of the port B as output
//	GPIOB->PDOR = (0 << 21); //turn off blue led
//	printf("print some debugging info, can be seen in console window.\n\r");
//	while (1) {
//		GPIOB->PDOR = (0 << 21); //turn off blue led
//		delay();
//		GPIOB->PDOR = (1 << 21); //turn on blue led
//		delay();
//	}
}
