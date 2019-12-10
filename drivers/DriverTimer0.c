#include "driverHeaders/DriverTimer0.h"

#ifndef PIT_clock_Freq
#define PIT_clock_Freq 60
//60 = in MHz => bus clock
#endif

void (*tim0IRQ)(void);
uint32_t tim_0_LDVAL = 1;

void initTim0(){
	//System Clock Gating Control Register 6 (SIM_SCGC6)
	SIM -> SCGC6 |= (1 << 23); 			//enable clock to PIT

	//PIT Module Control Register (PIT_MCR):
	PIT -> MCR = 0; 					//enable PIT module

	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[0].TCTRL = (1 << 1); 	//enable interrupts

	//Timer Flag Register (PIT_TFLGn)
	PIT -> CHANNEL[0].TFLG = 1;				//clear interrupt flag before starting.
											// -> cleared by writing '1'

	//set interrupt:
	NVIC_EnableIRQ(48);
}

void Tim0SetIRQ(void (*interruptFunctie)(void)){
	tim0IRQ = interruptFunctie;
}

void startTim0(uint32_t microseconds){
	tim_0_LDVAL = (uint32_t)(microseconds * PIT_clock_Freq) - 1;

	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[0].TCTRL &= ~1; 			//disable timer

	//Timer Load Value Register (PIT_LDVALn)
	PIT -> CHANNEL[0].LDVAL = tim_0_LDVAL; 	//set the startvalue on timer 0

	//Timer Control Register (PIT_TCTRLn)
	PIT -> CHANNEL[0].TCTRL |= 1; 			//enable timer
}

float tim0Value(){
	uint32_t read = PIT -> CHANNEL[0].CVAL;
	return ((float) read) / tim_0_LDVAL;
}

void PIT0_IRQHandler(void){
	tim0IRQ(); //spring naar IRQ in hoger niveau

	//Timer Flag Register (PIT_TFLGn)
	PIT -> CHANNEL[0].TFLG = 1;					//clear interrupt flag.
												// -> cleared by writing '1'
}
