#include "MK64F12.h"

/*
* Initialize led on Port_A_ledNr
* @param  ledNr Led that on Port A that should be initialised.
* @return void
*/
void initLED_A(uint8_t ledNr);

/*
* Set led on Port_A_ledNr High if on is equal to 1.
* @param  ledNr Led that on Port A that should be asserted or deasserted.
* @param of Turn led of when 1.
* @return void
*/
void setLED_A(uint8_t ledNr, uint8_t of);

/*
* Initialize led on Port_B_ledNr
* @param  ledNr Led that on Port B that should be initialised.
* @return void
*/
void initLED_B(uint8_t ledNr);

/*
* Set led on Port_B_ledNr High if on is equal to 1.
* @param  ledNr Led that on Port B that should be asserted or deasserted.
* @param of Turn led of when 1.
* @return void
*/
void setLED_B(uint8_t ledNr, uint8_t of);

/*
* Initialize led on Port_C_ledNr
* @param  ledNr Led that on Port C that should be initialised.
* @return void
*/
void initLED_C(uint8_t ledNr);

/*
* Set led on Port_C_ledNr High if on is equal to 1.
* @param  ledNr Led that on Port C that should be asserted or deasserted.
* @param of Turn led of when 1.
* @return void
*/
void setLED_C(uint8_t ledNr, uint8_t of);
