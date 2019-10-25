#include "driverHeaders/JoystickInput.h"

void (*up)(void);
void (*down)(void);
void (*left)(void);
void (*right)(void);
void (*fire)(void);

int initJoyStick(direction dir, void (*fp)(void)) {
	if (100 <= dir && dir < 200) { //PORTB
		int pin = dir - 100;
		SIM->SCGC5 |= (1 << 10); //enable Port B Clock Gate Control
		PORTB->PCR[pin] |= (1 << 8); //mux alt1
		GPIOB->PDDR &= ~(1 << pin); //port direction
		PORTB->PCR[pin] |= (9 << 16); //Interrupt on rising-edge
		PORTB->ISFR |= (1 << pin); //ISRF resetten
		NVIC_EnableIRQ(60);
	} else if (200 <= dir && dir < 300) { //PORTC
		int pin = dir - 200;
		SIM->SCGC5 |= (1 << 11); //enable Port C Clock Gate Control
		PORTC->PCR[pin] |= (1 << 8); //mux alt1
		GPIOC->PDDR &= ~(1 << pin); //port direction
		PORTC->PCR[pin] |= (9 << 16); //Interrupt on rising-edge
		PORTC->ISFR |= (1 << pin); //ISRF resetten
		NVIC_EnableIRQ(61);
	} else {
		printf("direction does not exist\n");
	}

	switch (dir) {
		case UP:
			up = fp;
			break;
		case DOWN:
			down = fp;
			break;
		case LEFT:
			left = fp;
			break;
		case RIGHT:
			right = fp;
			break;
		case FIRE:
			fire = fp;
			break;
		default:
			printf("direction can only be \"up\" \"down\" \"left\" \"right\" or \"fire\"\n");
	}
	printf("initJoystick completed for %d\n", dir);
	return 0;
}

void PORTB_IRQHandler(void) {
	switch (PORTB->ISFR) {
		case 1<<10:
			up();
			break;
		case 1<<11:
			down();
			break;
		case 1<<23:
			fire();
			break;
		default:
			printf("interrupt not recognized.\n");
	}
	PORTB->ISFR &= ~0; //reset all interrupts on PORTB by writing a '1'.
}

void PORTC_IRQHandler(void) {
	switch (PORTC->ISFR) {
		case 1<<10:
			right();
			break;
		case 1<<11:
			left();
			break;
		default:
			printf("interrupt not recognized.\n");
	}
	PORTC->ISFR &= ~0; //reset all interrupts on PORTC by writing a '1'.
}

