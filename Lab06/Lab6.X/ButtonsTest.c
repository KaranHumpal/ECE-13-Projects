// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

//CMPE13 Support Library
#include "BOARD.h"
#include "Buttons.h"
#include "Oled.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

// User libraries

// **** Set macros and preprocessor directives ****

// **** Declare any datatypes here ****

// **** Define global, module-level, or external variables here ****
uint8_t buttonEvents;

// **** Declare function prototypes ****

int main(void) {
    BOARD_Init();
    // Configure Timer 1 using PBCLK as input. This default period will make the LEDs blink at a
    // pretty reasonable rate to start.
    T1CON = 0; // everything should be off
    T1CONbits.TCKPS = 2; // 1:64 prescaler
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
    printf("Welcome to khumpal's lab6 part4 (ButtonsTest).  Compiled on %s %s.\n", __TIME__, __DATE__);


    printf("Please press some buttons!\n");

    ButtonsInit();
    OledInit();
    while (1) {
        char message[35];
        sprintf(message,"Press Buttons");
        OledDrawString(message);
        OledUpdate();
        int b1 = 0;
        int b2 = 0;
        int b3 = 0;
        int b4 = 0;
        if (buttonEvents) {
            if (buttonEvents & BUTTON_EVENT_1DOWN) {
                 b1 = 1;
            }
            if (buttonEvents & BUTTON_EVENT_1UP) {
                 b1 =2;
            }
            if (buttonEvents & BUTTON_EVENT_2DOWN) {
                b2 = 1;
            }
            if (buttonEvents & BUTTON_EVENT_2UP) {
                b2 = 2;
            }
            if (buttonEvents & BUTTON_EVENT_3DOWN) {
                b3 = 1;
            }
            if (buttonEvents & BUTTON_EVENT_3UP) {
                b3 = 2;
            }
            if (buttonEvents & BUTTON_EVENT_4DOWN) {
                b4 = 1;
            }
            if (buttonEvents & BUTTON_EVENT_4UP) {
                b4 = 2;
            }
            buttonEvents = BUTTON_EVENT_NONE;
            printf("EVENT:  ");
            if (b1 == 0) {
                printf("1:----  ");
            }
            if (b1 == 1) {
                printf("1: DOWN ");
            }
    
            if (b1 == 2) {
                printf("1:   UP ");
            }
            if (b2 == 0) {
                printf("2:----  ");
            }
            if (b2 == 1) {
                printf("2: DOWN ");
            }
            if (b2 == 2) {
                printf("2:   UP ");
            }
            if (b3 == 0) {
                printf("3:----  ");
            }
            if (b3 == 1) {
                printf("3: DOWN ");
            }
            if (b3 == 2) {
                printf("3:   UP ");
            }
            if (b4 == 0) {
                printf("4:----\n");
            }
            if (b4 == 1) {
                printf("4: DOWN\n");
            }
            if (b4 == 2) {
                printf("4:   UP\n");
            }
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
void __ISR(_TIMER_1_VECTOR, ipl4auto) Timer1Handler(void) {
    // Clear the interrupt flag.
    IFS0bits.T1IF = 0;

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    buttonEvents = ButtonsCheckEvents();

    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

}