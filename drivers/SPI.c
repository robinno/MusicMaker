#include "driverHeaders/SPI.h"

int initSPI() {
	SIM->SCGC5 |= (3 << 11); //clock gate on PORT C and D (resp. b11 and b12)
	const int muxAlt2 = (2 << 8);
	PORTC->PCR[3] |= (1 << 8); //set mux of Port C3 to alt1
	GPIOC->PDDR |= (1 << 3); //set Port C3 as output
	for (int i = 0; i < 4; i++) {
		PORTD->PCR[i] |= (1 << 8); //set mux of Port D 0-3 to alt1.
		GPIOD->PDDR |= (1 << i); //set Port Di as output
	}
	GPIOD->PDOR |= (1 << 0); //set nCS to 1
	GPIOD->PDOR |= (1 << 1); //set SCK to 1
	printf("initSPI completed.\n");
	return 0;
}

int pushSPI(int A0, uint8_t data) {
	GPIOD->PDOR |= (1 << 0); //set nCS to 0
	if (A0 == 1) {
		GPIOC->PDOR |= (1 << 3); //A0 to 1
	} else {
		GPIOC->PDOR &= ~(1 << 3); //A0 to 0
	}
	for (int32_t i = 7; i >= 0; i--) {
		GPIOD->PDOR &= ~(1 << 1); //SCK to 0
		if (data >> i == 1) {
			GPIOD->PDOR |= (1 << 2); //MOSI to 1
		} else {
			GPIOD->PDOR &= ~(1 << 2); //MOSI to 0
		}
		delay_10ns(3);
		GPIOD->PDOR |= (1 << 1); //SCK to 1
		delay_10ns(3);
	}
	GPIOD->PDOR |= (1 << 0); //set nCS to 1
	printf("data is send.\n");
	return 0;
}

void delay_10ns(int ns10) {
	for (long i = 0; i < (1 * ns10); i++) {
	} //timed measurements
}
