#include "middlewareHeaders/WriteLED.h"

void initRGB() {
	initLED_B(22); //init Red LED
	initLED_C(4); //init Green LED
	initLED_C(12); //init red LED
	setLED_B(22, 1); //turn of Red LED
	setLED_C(4, 1); //turn of Green LED
	setLED_C(12, 1); //turn of red LED
}

void setLED(RGB color, uint8_t of) {
	switch (color) {
	case RED:
		setLED_B(22, of);
		break;
	case GREEN:
		setLED_C(4, of);
		break;
	case BLUE:
		setLED_C(12, of);
		break;
	}
}
