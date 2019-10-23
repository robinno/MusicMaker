#include "./topHeaders/toplevel.h"

void delay() {
	for (long i = 0; i < 1000000; i++) {
	}
}

void toplevel() {
	printf("in toplevel \n\r");

	/*
	// test pot driver
	initPot();

	while(1){
		delay();
		printf("%i\n\r", getPotInput());
	}
	*/
}
