#include "./topHeaders/toplevel.h"

void delay() {
	for (long i = 0; i < 1000000; i++) {
	}
}

void toplevel() {
	printf("in toplevel \n\r");
	initLED();

	//blue LED app-shield
	SIM->SCGC5 |= (1 << 11);
	PORTC->PCR[4] |= (1 << 8);
	GPIOC->PDDR |= (1 << 4);
	//GPIOC->PTOR |= (1 << 4); //toggle blue
	delay();

	//initJoyStick();
	PORTB->PCR[10] |= (1 << 8);
	GPIOB->PDDR &= !(1 << 10);
	PORTB->PCR[10] |= (9 << 16);
	PORTB->ISFR &= !(1 << 10);
	NVIC_EnableIRQ(60);

	printf("while started\n");
	while (1) {
		delay();
	}

}

void PORTB_IRQHandler(void) {
	GPIOC->PTOR |= (1 << 4);//toggle blue led
	PORTB->ISFR &= !(1 << 10);
}
