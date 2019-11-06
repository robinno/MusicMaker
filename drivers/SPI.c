#include "driverHeaders/SPI.h"

int initSPI(){
	SIM->SCGC6 |= (1<<12); //clock gate for SPI0
	SIM->SCGC5 |= (3<<11); //clock gate on PORT C and D (resp. b11 and b12)
	const int muxAlt2 = (2<<8);
	PORTC->PCR[3] |= muxAlt2; //set mux of Port C3 to alt2
	for(int i =0; i<4; i++){
		PORTD->PCR[i] |= muxAlt2; //set mux of Port D 0-3 to alt2.
	}

	/*MCR*/
	SPI0->MCR |= (1<<31);//enable Master mode
	//SPI0->MCR |= (0<<31); //no continuous clk.
	SPI0->MCR |= (1<<16); //The inactive state of PCS0 is high
	//SPI0->MCR |= (0<<10);//Do not clear the RX FIFO counter.

	/*CTAR use CTAR0*/
	SPI0->CTAR[0] &= 0;//initialize with zeros
	SPI0->CTAR[0] |= (7<<27);
	SPI0->CTAR[0] |= (1<<26);//The inactive state value of SCK is high.
	SPI0->CTAR[0] |= (1<<25);//Data is changed on the leading edge of SCK and captured on the following edge.
	SPI0->CTAR[0] |= (1<<8); // ASC = 4
	SPI0->CTAR[0] |= (1<<4); // DT = 4

	printf("initSPI completed.\n");
	return 0;
}

int pushSPI(int A0, uint8_t data){

}
