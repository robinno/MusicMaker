#include "driverHeaders/DriverTimer0.h"

const uint32_t PIT_clock_period = 10; //in nanoSeconds => 1 / clkfreq van de PIT


void initTim0(uint32_t microseconds){

	//System Clock Gating Control Register 6 (SIM_SCGC6)
	SIM -> SCGC6 |= (1 << 23); 			//enable clock to PIT

	//PIT Module Control Register (PIT_MCR):
	PIT -> MCR = 0; 					//enable PIT module

	//Timer Load Value Register (PIT_LDVALn)
	PIT -> CHANNEL[0].LDVAL = (microseconds / PIT_clock_period) * 1000 - 1; 	//set the startvalue on timer 0

	//Timer Flag Register (PIT_TFLGn)
	PIT -> CHANNEL[0].TFLG = 1;				//clear interrupt flag before starting.
											// -> cleared by writing '1'

	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[0].TCTRL |= (1 << 1); 	//enable interrupts

	//set interrupt:
	NVIC_EnableIRQ(48);
}

void startTimer0(){
	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[0].TCTRL |= 1; 			//enable timer
}

void stopTimer0(){
	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[0].TCTRL |= ~1; 			//disable timer
}

void PIT0_IRQHandler(void){
	//Timer Flag Register (PIT_TFLGn)
	PIT -> CHANNEL[0].TFLG = 1;					//clear interrupt flag.
												// -> cleared by writing '1'

	printf("interrupt van timer");

	//TODO
}
