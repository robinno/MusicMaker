#ifndef soundHeader
#define soundHeader

#include <stdint.h>
#include <stdbool.h>

//this file is for the declaration of the "sound" struct:

#define fs 50 //sample frequency in kHz

#define nameBufferSize 10
#define samplesBufferSize 10000 //Eventueel aanpassen als te klein.

/**
 * This struct is used as a "class" for the sounds that can be played in playsound
 *
 * @param name = the name of the sound
 * @param length = the size of the samples array (maximum 10000).
 * @param samples = an array of the 12 bit values that need to be played at the sample frequency, in order
 * @param active = boolean if the sound should be playing when it is asked to
 * @param playing = boolean that indicates that this sound is currently being played.
 * @param index = the position in the samples array which sample is currently being outputted.
 */
struct sound{
	char name[nameBufferSize];
	uint16_t length;
	uint16_t samples[samplesBufferSize];

	bool active; //nodig bij toekenning aan track in hoger level.
	uint8_t playing; //nodig bij afspelen
	uint16_t index; //huidige index bij afspelen
};

#endif
