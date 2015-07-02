/*
* File: InternalClock.c
* Author: jy1189
*
* Created on April 23, 2015, 11:05 AM
*/

//*****************************************************************************


#include "IWPUtilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <xc.h>
#include <string.h>


// ****************************************************************************
// *** PIC24F32KA302 Configuration Bit Settings *******************************
// ****************************************************************************
// FBS
#pragma config BWRP = OFF // Boot Segment Write Protect (Disabled)
#pragma config BSS = OFF // Boot segment Protect (No boot program flash segment)
// FGS
#pragma config GWRP = OFF // General Segment Write Protect (General segment may be written)
#pragma config GSS0 = OFF // General Segment Code Protect (No Protection)
// FOSCSEL
#pragma config FNOSC = FRC // Oscillator Select (Fast RC Oscillator (FRC))
#pragma config SOSCSRC = ANA // SOSC Source Type (Analog Mode for use with crystal)
#pragma config LPRCSEL = HP // LPRC Oscillator Power and Accuracy (High Power, High Accuracy Mode)
#pragma config IESO = OFF // Internal External Switch Over bit (Internal External Switchover mode enabled (Two-speed Start-up enabled))
// FOSC
#pragma config POSCMOD = NONE // Primary Oscillator Configuration bits (Primary oscillator disabled)
#pragma config OSCIOFNC = OFF // CLKO Enable Configuration bit (CLKO output disabled)
#pragma config POSCFREQ = HS // Primary Oscillator Frequency Range Configuration bits (Primary oscillator/external clock input frequency greater than 8MHz)
#pragma config SOSCSEL = SOSCHP // SOSC Power Selection Configuration bits (Secondary Oscillator configured for high-power operation)
#pragma config FCKSM = CSDCMD // Clock Switching and Monitor Selection (Both Clock Switching and Fail-safe Clock Monitor are disabled)
// FWDT
#pragma config WDTPS = PS32768 // Watchdog Timer Postscale Select bits (1:32768)
#pragma config FWPSA = PR128 // WDT Prescaler bit (WDT prescaler ratio of 1:128)
#pragma config FWDTEN = OFF // Watchdog Timer Enable bits (WDT disabled in hardware; SWDTEN bit disabled)
#pragma config WINDIS = ON // Windowed Watchdog Timer Disable bit (Windowed WDT enabled)
// FPOR
#pragma config BOREN = BOR3 // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware, SBOREN bit disabled)
#pragma config LVRCFG = OFF // (Low Voltage regulator is not available)
#pragma config PWRTEN = ON // Power-up Timer Enable bit (PWRT enabled)
#pragma config I2C1SEL = PRI // Alternate I2C1 Pin Mapping bit (Use Default SCL1/SDA1 Pins For I2C1)
//#pragma config BORV = V20 // Brown-out Reset Voltage bits (Brown-out Reset set to lowest voltage (2.0V))
#pragma config MCLRE = ON // MCLR Pin Enable bit (RA5 input pin disabled,MCLR pin enabled)
// FICD
#pragma config ICS = PGx1 // ICD Pin Placement Select bits (EMUC/EMUD share PGC1/PGD1)
// FDS
#pragma config DSWDTPS = DSWDTPSF // Deep Sleep Watchdog Timer Postscale Select bits (1:2,147,483,648 (25.7 Days))
#pragma config DSWDTOSC = LPRC // DSWDT Reference Clock Select bit (DSWDT uses Low Power RC Oscillator (LPRC))
#pragma config DSBOREN = ON // Deep Sleep Zero-Power BOR Enable bit (Deep Sleep BOR enabled in Deep Sleep)
#pragma config DSWDTEN = ON // Deep Sleep Watchdog Timer Enable bit (DSWDT enabled)




// ****************************************************************************
// *** Main Function **********************************************************
// ****************************************************************************
void main(void)
{
    initialization();
    TRISAbits.TRISA1 = 0; // pin 3 is an output

//------------------------------------------------------------------------------
// read seconds  works
//------------------------------------------------------------------------------
 while (1)
    {
    // change the rate that pin 3 blinks
     if (getHandleAngle() <= 15){
         PORTAbits.RA1 = 1;
         delayMs(10);
         PORTAbits.RA1 = 0;
         delayMs(10);
     }
     else if (getHandleAngle() <= 30){
         PORTAbits.RA1 = 1;
         delayMs(100);
         PORTAbits.RA1 = 0;
         delayMs(100);
    }
     else if (getHandleAngle() <= 45){
         PORTAbits.RA1 = 1;
         delayMs(250);
         PORTAbits.RA1 = 0;
         delayMs(250);
    }
     else if (getHandleAngle() <= 60){
         PORTAbits.RA1 = 1;
         delayMs(500);
         PORTAbits.RA1 = 0;
         delayMs(500);
    }
     else if (getHandleAngle() <= 75){
         PORTAbits.RA1 = 1;
         delayMs(750);
         PORTAbits.RA1 = 0;
         delayMs(750);
    }
     else if (getHandleAngle() <= 90){
         PORTAbits.RA1 = 1;
         delayMs(1000);
         PORTAbits.RA1 = 0;
         delayMs(1000);
    }
     else if (getHandleAngle() <= 105){
         PORTAbits.RA1 = 1;
         delayMs(1250);
         PORTAbits.RA1 = 0;
         delayMs(1250);
    }
     else if (getHandleAngle() <= 120){
         PORTAbits.RA1 = 1;
         delayMs(1500);
         PORTAbits.RA1 = 0;
         delayMs(1500);
    }
     else if (getHandleAngle() <= 135){
         PORTAbits.RA1 = 1;
         delayMs(1750);
         PORTAbits.RA1 = 0;
         delayMs(1750);
    }
     else if (getHandleAngle() <= 150){
         PORTAbits.RA1 = 1;
         delayMs(2000);
         PORTAbits.RA1 = 0;
         delayMs(2000);
    }
     else if (getHandleAngle() <= 165){
         PORTAbits.RA1 = 1;
         delayMs(2250);
         PORTAbits.RA1 = 0;
         delayMs(2250);
    }
     else if (getHandleAngle() <= 180){
         PORTAbits.RA1 = 1;
         delayMs(250);
         PORTAbits.RA1 = 0;
         delayMs(250);
    }
     else {
         PORTAbits.RA1 = 1;
     }
}
}