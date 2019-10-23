#include "driverHeaders/JoystickInput.h"

int initJoyStick(){
	printf("d1 ");
	//mux alt1 GPIO, set interupt on rising edge (IRQS)
	PORTB->PCR[10] |= (1<<8);
	PORTB->PCR[10] |= (9<<16);

	PORTB->ISFR &= !(1<<10);

	printf("d2 ");
	//GPIO direction
	GPIOB->PDDR &= !(1<<10);
	GPIOB->PDDR &= !(1<<11);
	GPIOC->PDDR &= !(1<<10);
	GPIOC->PDDR &= !(1<<11);
	//printf("d3 ");
	//enabable interrupt on pin C and pin B
	NVIC_EnableIRQ(60);
	NVIC_EnableIRQ(61);



	printf("initJoystick completer\n");
	return 0;
}
