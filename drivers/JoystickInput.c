#include "driverHeaders/JoystickInput.h"

int initJoyStick(){
	SIM->SCGC5 |= (1<<11); //enable Port C Clock Gate Control
	SIM->SCGC5 |= (1<<10); //enable Port B Clock Gate Control

	//mux alt1 GPIO, set interupt on rising edge (IRQS)
	PORTB->PCR[10] |= (1<<8);
	PORTB->PCR[10] |= (9<<16);

	PORTB->ISFR &= ~(1<<10);

	//GPIO direction
	GPIOB->PDDR &= ~(1<<10);
	GPIOB->PDDR &= ~(1<<11);
	GPIOC->PDDR &= ~(1<<10);
	GPIOC->PDDR &= ~(1<<11);
	//enabable interrupt on pin C and pin B
	NVIC_EnableIRQ(60); //port B
	NVIC_EnableIRQ(61); //Port C



	printf("initJoystick completer\n");
	return 0;
}
