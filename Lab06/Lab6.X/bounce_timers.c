// **** Include libraries here ****
// old bounce
// Standard libraries
#include <stdio.h>
#include <GenericTypeDefs.h>

//CMPE13 Support Library
#include "BOARD.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

// User libraries
#include "Leds_Lab06.h"


// **** Declare any datatypes here ****

struct Timer {
    uint8_t event;
    int16_t timeRemaining;
};

// **** Define global, module-level, or external variables here ***

struct Timer TimerA;
struct Timer TimerB;
struct Timer TimerC;


// **** Declare function prototypes ****

int main(void)
{
    BOARD_Init();
    
    TimerA.timeRemaining = 76; //38x2
    TimerB.timeRemaining = 114; //38x3
    TimerC.timeRemaining = 190; //38x5

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
    printf("Welcome to khumpal's lab6 part1 (timers).  Compiled on %s %s.\n", __TIME__, __DATE__);
    LEDS_INIT();
    
    while (1) {
        
        if (TimerA.event == TRUE) { //if there is an event for timer A, it sets the first LED and returns the event to false
            TimerA.event = FALSE;
            printf("A");
            char x = LEDS_GET();
            LEDS_SET((x^(0x01)));
        }

        if (TimerB.event == TRUE) {
            TimerB.event = FALSE;
            printf("B");
            char y = LEDS_GET();
            LEDS_SET((y^(0x02)));
        }

        if (TimerC.event == TRUE) {
            TimerC.event = FALSE;
            printf("C");
            char z = LEDS_GET();
            LEDS_SET((z^(0x04)));
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
    TimerA.timeRemaining += -1; 
    if (TimerA.timeRemaining == 0) {
        TimerA.event = TRUE;
        TimerA.timeRemaining = 76;
    }
    TimerB.timeRemaining += -1;

    if (TimerB.timeRemaining == 0) {
        TimerB.event = TRUE;
        TimerB.timeRemaining = 114;
    }

    TimerC.timeRemaining += -1;
    if (TimerC.timeRemaining == 0) {
        TimerC.event = TRUE;
        TimerC.timeRemaining = 190;
    }

    
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

}