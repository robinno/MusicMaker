#include "driverHeaders/DriverTimer1.h"

#ifndef PIT_clock_Freq
#define PIT_clock_Freq 60
//60 = in MHz => bus clock
#endif

void (*tim1IRQ)(void);

void initTim1(){
	//System Clock Gating Control Register 6 (SIM_SCGC6)
	SIM -> SCGC6 |= (1 << 23); 			//enable clock to PIT

	//PIT Module Control Register (PIT_MCR):
	PIT -> MCR = 0; 					//enable PIT module

	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[1].TCTRL = (1 << 1); 	//enable interrupts

	//Timer Flag Register (PIT_TFLGn)
	PIT -> CHANNEL[1].TFLG = 1;				//clear interrupt flag before starting.
											// -> cleared by writing '1'

	//set interrupt:
	NVIC_EnableIRQ(49);
}

void Tim1SetIRQ(void (*interruptFunctie)(void)){
	tim1IRQ = interruptFunctie;
}

void startTimer1(uint32_t microseconds){
	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[1].TCTRL |= ~1; 			//disable timer

	//Timer Load Value Register (PIT_LDVALn)
	PIT -> CHANNEL[1].LDVAL = (uint32_t)(microseconds * PIT_clock_Freq) - 1; 	//set the startvalue on timer 0

	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[1].TCTRL |= 1; 			//enable timer
}


void PIT1_IRQHandler(void){
	tim1IRQ(); //spring naar IRQ in hoger niveau

	//Timer Flag Register (PIT_TFLGn)
	PIT -> CHANNEL[1].TFLG = 1;					//clear interrupt flag.
												// -> cleared by writing '1'
}
