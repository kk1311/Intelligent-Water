/* 
 * File:   EEPROM KWHR from Tom Austin.h
 * Author: Jacqui
 *
 * Created on August 13, 2015, 1:18 PM
 */

//#include "C:\Program Files\Microchip\xc16\v1.21\support\PIC24F\h\p24FV32KA301.h"




/* Function Definitions *******************************************************/

unsigned long EEPROMreadLong();
unsigned int EEPROMreadInt(void);
void EEPROMwriteLong(unsigned long);
void EEPROMwriteInt(unsigned int);


/* Variable Definitions *******************************************************/

int __attribute__ ((space(eedata))) ee_addr;


/* Functions ******************************************************************/

unsigned int EEPROMreadInt(void) {
    while(_WR);// wait for write or erase to finish

    // Set up a pointer to the EEPROM location to be read
    TBLPAG = __builtin_tblpage(&ee_addr);
    unsigned int offset = __builtin_tbloffset(&ee_addr);
    // Read the EEPROM data
    return __builtin_tblrdl(offset);
}

void EEPROMwriteInt(unsigned int data) {
    while(_WR);
//    int __attribute__ ((space(eedata))) eeData = 0x1234; // Global variable located in EEPROM
    // Set up NVMCON to write one word of data EEPROM
    NVMCON = 0x4004;
    // Set up a pointer to the EEPROM location to be written
    TBLPAG = __builtin_tblpage(&ee_addr);
    unsigned int offset = __builtin_tbloffset(&ee_addr);
    // Write Data Value To Holding Latch
    __builtin_tblwtl(offset, data);
    // Disable Interrupts For 5 Instructions
    asm volatile ("disi #5");
    // Issue Unlock Sequence & Start Write Cycle
    __builtin_write_NVM();
}
