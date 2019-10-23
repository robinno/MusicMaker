#include "./topHeaders/toplevel.h"

void delay() {
	for (long i = 0; i < 1000000; i++) {
	}
}

void toplevel() {
	printf("in toplevel \n\r");
	//turn off leds on app-board
	initLED_A(2); //red
	setLED_A(2, 0);
	initLED_C(4); //green
	setLED_C(4, 1);
	initLED_C(12); //blue
	setLED_C(12, 1);
	printf("all leds off\n");

	PORTB->PCR[10] |= (1 << 8); //mux alt1
	GPIOB->PDDR &= ~(1 << 10); //port direction
	PORTB->PCR[10] |= (9 << 16); //Interrupt on rising-edge
	//PORTB->ISFR &= !(1 << 10); //ISRF resetten
	NVIC_EnableIRQ(60);

	printf("while started\n");
	while (1) {
		delay();
		//printf("while %x\n", ~(0 << 24));
	}

}

void PORTB_IRQHandler(void) {
	printf("Voor reset: PORTB->ISFR %x\n", PORTB->ISFR);
	PORTB->ISFR |= (1<<24);
	//printf("PORTB->PCR[10] %x\n", PORTB->PCR[10]);
	printf("Na reset: PORTB->ISFR %x\n", PORTB->ISFR);
}
