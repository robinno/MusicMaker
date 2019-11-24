/*
 * STATES.h
 *
 *  Created on: 24 nov. 2019
 *      Author: robin
 */

#ifndef TOP_TOPHEADERS_GLOBALS_H_
#define TOP_TOPHEADERS_GLOBALS_H_

#define aantalTracks 4

//STATEMACHINE variables:
enum states{MENU, BPM_INST, MAAT_INST, SPELENDE_TRACKS_INST, TRACK_MENU, RESOLUTIE_INST, GELUID_INST, REC_PERCUSSIE};
uint8_t state = MENU;
uint8_t huidigeTrack_Trackmenu = 0;


#endif /* TOP_TOPHEADERS_GLOBALS_H_ */
