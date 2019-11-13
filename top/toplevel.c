#include "topHeaders/toplevel.h"

void delay() {
	for (long i = 0; i < 1000000; i++) {
	}
}

//void c10(void) {
//	printf("c10\n");
//}
//void b10(void) {
//	printf("b10\n");
//}
//void b23(void) {
//	printf("b23\n");
//}
//void c11(void) {
//	printf("c11\n");
//}
//void b11(void) {
//	printf("b11\n");
//}
//
//void timer1_IRQ(){
//	printf("in IRQ van timer\n");
//}

void toplevel() {
	printf("in toplevel \n\r");
	//turn off leds on app-board
//	initLED_A(2); //red
//	setLED_A(2, 0);
//	initLED_C(4); //green
//	setLED_C(4, 1);
//	initLED_C(12); //blue
//	setLED_C(12, 1);
//	printf("all leds off\n");
//
//	initJoyStick(RIGHT, c10);
//	initJoyStick(UP, b10);
//	initJoyStick(FIRE, b23);
//	initJoyStick(LEFT, c11);
//	initJoyStick(DOWN, b11);

//	printf("begin aan Timer1 test\n");
//	initTim0();
//	Tim0SetIRQ(timer1_IRQ);
//	startTimer0(1000000);//1 seconds



//	initSPI();
//	printf("starting sending commands to LCD\n");
//	while(1){
//		display_OnOff(1);
//		display_allPoints(1);
//	}
//	printf("end\n");

	printf("starting testSine");
	playsound_init();
	playsound_testSineWave();

	pushSPI(1, 0xaa);

	while (1) {
		delay();
		//printf("while %x\n", ~(0 << 24));l
	}

	/*
	 printf("begin aan DAC test\n");
	 uint16_t waarde = 0;
	 while(1){
	 scanf("%i", &waarde);
	 printf("setting value of DAC to %i\n", waarde);
	 DAC0_set(waarde);
	 printf("set!\n");
	 delay();
	 }
	 */
}

