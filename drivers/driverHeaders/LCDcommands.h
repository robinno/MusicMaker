#include "SPI.h"
#include <stdint.h>

/*
 * sets LCD display ON/OFF
 */
inline void display_OnOff(int on); //0 for off, 1 for on

/*
 * sets the display start line address in RAM
 */
inline void display_startLineSet(uint8_t StartAddr);

/*
 * sets the display page address in RAM
 */
inline void display_setPageAddress(uint8_t pageAddr);

/*
 * sets the display column address in RAM
 */
inline void display_setColumnAddr(uint8_t columnAddr);

/*
 * writes data to the display RAM
 */
inline void display_dataWrite(uint8_t data);


/*
 * displays all points on: used for testing
 */
inline void display_allPoints(int on); //0 for normal mode, 1 for all points on

/*
 * reset display
 */
inline void display_reset();

/*
 * command for No Operation
 */
inline void display_NOP();
