// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

//CMPE13 Support Library
#include "BOARD.h"
#include "Buttons.h"
#include "Leds_Lab06.h"
// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

// User libraries

// **** Set macros and preprocessor directives ****

// **** Declare any datatypes here ****

// **** Define global, module-level, or external variables here ****
uint8_t event;
enum  LED{
    LD1 = 0x01,
    LD2 = 0x02,
    LD3 = 0x04,
    LD4 = 0x08,
    LD5 = 0x10,
    LD6 = 0x20,
    LD7 = 0x40,
    LD8 = 0x80, 
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
    printf("Welcome to khumpal's lab6 part5 (bounce_buttons).  Compiled on %s %s.\n", __TIME__, __DATE__);
    LEDS_INIT();
    ButtonsInit();
    while (1) {
        if (event != BUTTON_EVENT_NONE) {
            char x = LEDS_GET();
            uint8_t switchesState = SWITCH_STATES(); //from Board.H
           
            if ((event & BUTTON_EVENT_1UP)&&(switchesState & SWITCH_STATE_SW1)) {   // when BUTTON 1 is up and SWITCH 1 is on then LEDs 1 and 2 are changed 
                x = x ^ LD1 ^ LD2;                                              
            } 
            else if ((event & BUTTON_EVENT_1DOWN)&&(!(switchesState & SWITCH_STATE_SW1))) { //when BUTTON 1 is pressed down and SWITCH 1 is not on LEDs 1 and 2 are changed
                x = x ^ LD1 ^ LD2;           
            }
            if ((event & BUTTON_EVENT_2UP)&&(switchesState & SWITCH_STATE_SW2)) {
                x = x ^ LD3 ^ LD4;
                
            } 
            else if ((event & BUTTON_EVENT_2DOWN)&&(!(switchesState & SWITCH_STATE_SW2))) {
                x = x ^ LD3 ^ LD4;
                
            }
            
            if ((event & BUTTON_EVENT_3UP)&&(switchesState & SWITCH_STATE_SW3)) {
                x = x ^ LD5 ^ LD6;
            } 
            else if ((event & BUTTON_EVENT_3DOWN)&&(!(switchesState & SWITCH_STATE_SW3))) {
                x = x ^ LD5 ^ LD6;
            }
            
            if ((event & BUTTON_EVENT_4UP)&&(switchesState & SWITCH_STATE_SW4)) {
                x = x ^ LD7 ^ LD8;
            }
            
            else if ((event & BUTTON_EVENT_4DOWN)&& (!(switchesState & SWITCH_STATE_SW4))) {
                x = x ^ LD7 ^ LD8;
            }
            LEDS_SET(x); //sets new pattern 
            event = BUTTON_EVENT_NONE; //resets 
        }
    }
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

    while (1);
}

/**
 * This is the interrupt for the Timer1 peripheral. It should check for button events and stores them in a
 * module-level variable.
 * 
 * You should not modify this function for ButtonsTest.c or bounce_buttons.c!
 */
void __ISR(_TIMER_1_VECTOR, ipl4auto) Timer1Handler(void)
{
    // Clear the interrupt flag.
    IFS0bits.T1IF = 0;

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    event = ButtonsCheckEvents();

    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

}