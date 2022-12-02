
// **** Include libraries here ****
// old bounce
// Standard libraries
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

				
//CMPE13 Support Library
#include "BOARD.h"
#include "Leds_Lab06.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

// **** Declare any datatypes here ****

struct Timer {
    uint8_t event;
    int16_t timeRemaining;
};
// **** Define global, module-level, or external variables here ****
struct Timer Timer;


enum position {
    LEFT = 0x80,
    RIGHT = 0x01
};

// **** Declare function prototypes ****


int main(void)
{
    BOARD_Init();

    // Configure Timer 1 using PBCLK as input. This default period will make the LEDs blink at a
    // pretty reasonable rate to start.
    T1CON = 0; // everything should be off
    T1CONbits.TCKPS = 1; // 1:8 prescaler
    PR1 = 0xFFFF; // interrupt at max interval
    T1CONbits.ON = 1; // turn the timer on

    // Set up the timer interrupt with a priority of 4.
    IFS0bits.T1IF = 0; //clear the interrupt flag before configuring
    IPC1bits.T1IP = 4; // priority of  4
    IPC1bits.T1IS = 0; // subpriority of 0 arbitrarily 
    IEC0bits.T1IE = 1; // turn the interrupt on

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    printf("Welcome to CRUZID's lab6 part2 (bounce_switch).  Compiled on %s %s.\n",__TIME__,__DATE__);
    
    LEDS_INIT();
    int state;
    uint8_t led1 = 0x01;
    
							 
	while(1){
        LEDS_SET(led1);
        if (Timer.event == TRUE) {
            if (led1 == LEFT) {
                state = FALSE;
            } else if (led1 == RIGHT) {
                state = TRUE;
            }
            if (state == FALSE) {
                led1 = led1 >> 1;
            }
            if (state == TRUE) {
                led1 = led1 << 1;
            }
            
        Timer.event = FALSE;
        } 
    }


    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/
}



/**
 * This is the interrupt for the Timer1 peripheral. It will trigger at the frequency of the peripheral
 * clock, divided by the timer 1 prescaler and the interrupt interval.
 * 
 * It should not be called, and should communicate with main code only by using module-level variables.
 */
void __ISR(_TIMER_1_VECTOR, ipl4auto) Timer1Handler(void)
{
    // Clear the interrupt flag.
    IFS0bits.T1IF = 0;

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
   Timer.timeRemaining += 1;
    if (Timer.timeRemaining > SWITCH_STATES()) {
        Timer.event = TRUE;
        Timer.timeRemaining = FALSE;
    }
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/									
	 
}