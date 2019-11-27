#include <stdint.h>
#include <stdbool.h>

#ifndef soundHeader
#define soundHeader

//this file is for the declaration of the "sound" struct:

#define fs 50 //sample frequency in kHz

#define nameBufferSize 10
#define samplesBufferSize 65535 //Eventueel aanpassen als te klein.

//struct for sounds:
struct sound{
	char name[nameBufferSize];
	uint16_t length;
	uint16_t samples[samplesBufferSize];

	bool active; //nodig bij toekenning aan track in hoger level.
	uint8_t playing; //nodig bij afspelen
	uint16_t index; //huidige index bij afspelen
};

#endif
