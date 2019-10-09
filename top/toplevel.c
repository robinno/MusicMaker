#include <MusicMaker/top/topHeaders/toplevel.h>
#include "fsl_debug_console.h"


void toplevel(){
	initLED();
	setLED(1);
	while(1){
		for (long i = 0; i < 1000000; i++) {
		}
		setLED(1);
		for (long i = 0; i < 1000000; i++) {
				}
		setLED(0);
	}
}
