

// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

//CSE13E Support Library
#include "BOARD.h"
#include "Leds.h"
#include "Adc.h"
#include "Ascii.h"
#include "Oled.h"
#include "OledDriver.h"
#include "Buttons.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>



// **** Set any macros or preprocessor directives here ****

#define OFF 0x00


// **** Set any local typedefs here ****

typedef enum {
    SETUP, SELECTOR_CHANGE_PENDING, COOKING, RESET_PENDING
} OvenState;

enum {
    BAKE, TOAST, BROIL, TIME, TEMP
};

typedef struct {
    OvenState state;
    int cook;
    int timeLeft;
    int temp;
    int time0;
    int enter;
    int press;
} OvenData;




// **** Declare any datatypes here ****
 OvenData Oven;

// **** Define any module-level, global, or external variables here ****

static uint8_t adc = FALSE;
static uint8_t timerTick = 0;
static uint8_t button = FALSE;
static uint8_t timerStart = 0;
static uint8_t countdown = 0;
static uint8_t freeRunTime = 0;
static uint8_t runningTime = 0;
static uint8_t runningTime2 = 0;
static uint8_t eventTime = TRUE;
static uint8_t check = FALSE;



// **** Put any helper functions here ****
int a =1 ;

/*This function will update your OLED to reflect the state .*/

void updateOvenOLED(OvenData ovenData) {
    

    const char o1[] = "\x01\x01\x01\x01\x01";
    const char o2[] = "\x02\x02\x02\x02\x02";
    const char o3[] = "\x03\x03\x03\x03\x03";
    const char o4[] = "\x04\x04\x04\x04\x04";
    char text[75];

    if ((Oven.cook == BAKE) && (Oven.timeLeft > 0)) {  //If baking prints the baking oven
        if (Oven.enter == TIME) {
            int minutes = Oven.timeLeft / 60;  //gets time min
            int seconds = Oven.timeLeft % 60;  //gets time sec
            sprintf(text, "|%s|\t Mode: Bake \n|     |\t>Time: %d:%02d\n"
                    "|-----|\t Temp: %d\n|%s|", o1, minutes, seconds, Oven.temp, o3);
        }     
        else if (Oven.enter == TEMP) {
            int minutes = Oven.timeLeft / 60;
            int seconds = Oven.timeLeft % 60;
            sprintf(text, "|%s|\t Mode: Bake \n|     |\t Time: %d:%02d\n"
                    "|-----|\t>Temp: %d\n|%s|", o1, minutes, seconds, Oven.temp,  o3);
        }
    }       
    else if ((Oven.cook == BAKE) && (Oven.enter == TIME)) { //in this case it prints baking oven (when input on time)
        int minutes1 = Oven.time0 / 60;
        int seconds1 = Oven.time0 % 60;
        sprintf(text, "|%s|\t Mode: Bake \n|     |\t>Time: %d:%02d\n"
                "|-----|\t Temp: %d\n|%s|", o2, minutes1, seconds1, Oven.temp, o4);
    }
        
    else if ((Oven.cook == BAKE) && (Oven.enter == TEMP)) { //also prints baking oven (when input is on temp)
        int minutes1 = Oven.time0 / 60;
        int seconds1 = Oven.time0 % 60;
        sprintf(text, "|%s|\t Mode: Bake \n|     |\t Time: %d:%02d\n"
                "|-----|\t>Temp: %d\n|%s|", o2, minutes1, seconds1, Oven.temp, o4);
    }    
    else if ((Oven.cook == TOAST) && (Oven.timeLeft > 0)) {  //if toasting, prints toasting oven
        int minutes = Oven.timeLeft / 60;
        int seconds = Oven.timeLeft % 60;
        sprintf(text, "|%s|\t Mode: Toast\n|     |\t>Time: %d:%02d\n"
                "|-----|            \n|%s|", o2, minutes, seconds, o3);
    }      
    else if (Oven.cook == TOAST) {  //when oven is not on, prints empty oven
        int minutes = Oven.time0 / 60;
        int seconds = Oven.time0 % 60;
        sprintf(text, "|%s|\t Mode: Toast\n|     |\t>Time: %d:%02d\n"
                "|-----|            \n|%s|", o2, minutes, seconds, o4);
    }       
    else if ((Oven.cook == BROIL) && (Oven.timeLeft > 0)) { //when broiling, prints broiling oven
        int minutes = Oven.timeLeft / 60;
        int seconds = Oven.timeLeft % 60;
        sprintf(text, "|%s|\t Mode: Broil\n|     |\t>Time: %d:%02d\n"
                "|-----|\t Temp: 500\n|%s|", o1, minutes, seconds, o4);
    }        
    else if (Oven.cook == BROIL) {  //when off prints off oven
        int minutes = Oven.time0 / 60;
        int seconds = Oven.time0 % 60;
        sprintf(text, "|%s|\t Mode: Broil\n|     |\t>Time: %d:%02d\n"
                "|-----|\t Temp: 500\n|%s|", o2, minutes, seconds,  o4);
    }
    OledDrawString(text);
    OledUpdate();
}

/*This function will execute your state machine.  
 * It should ONLY run if an event flag has been set.*/
void runOvenSM(void) {
    //write your SM logic here.
    switch (Oven.state) {
        case SETUP:
            if (adc == TRUE) {
                if (Oven.enter == TIME) { 
                    Oven.time0 = ((AdcRead() >> 2) + 1);//changes ADC from dial
                }
                else if (Oven.enter == TEMP) {
                    Oven.temp = ((AdcRead() >> 2) + 300);//changes ADC from dial. floor at 300
                }
                updateOvenOLED(Oven);
                Oven.state = SETUP;
            }
            if (check & BUTTON_EVENT_3DOWN) { 
                timerStart = freeRunTime;
                Oven.state = SELECTOR_CHANGE_PENDING;
            }
            if (check & BUTTON_EVENT_4DOWN) { //when you press BTN4 cooking stars and appropriate oven is displayed
                timerStart = freeRunTime;
                updateOvenOLED(Oven);
                Oven.state = COOKING;
                Oven.timeLeft = Oven.time0;
            }
            updateOvenOLED(Oven);
            break;

        case SELECTOR_CHANGE_PENDING:
            Oven.press = freeRunTime - timerStart;
            if (check & BUTTON_EVENT_3UP) {
                runningTime = Oven.press / 5;
                if (runningTime < 1) {      //if BTN 3 is pressed for > 1 sec, toggles between Bake,Broil,and Toast 
                    if (a == 0) {
                        Oven.cook = BAKE;
                        a = 1;
                    } else if (a == 1) {
                        Oven.cook = TOAST;
                        a = 2;
                    } else if (a == 2) {
                        Oven.cook = BROIL;
                        a = 0;
                    }
                    updateOvenOLED(Oven);
                    Oven.state = SETUP;
                } else {                    //if BTN 3 is pressed for < 1 sec, toggles temp and time if applicable (Bake mode) 
                    if (Oven.enter == TEMP) {
                        Oven.enter = TIME;
                    } else {
                        Oven.enter = TEMP;
                    }
                    updateOvenOLED(Oven);
                    Oven.state = SETUP;
                }
            }
            break;

        case COOKING:
            if (timerTick == TRUE) {        //Making the LEDS countdown with the timer
                if (Oven.timeLeft > 0) {  
                    uint8_t divisor = (Oven.time0 / 7);
                    uint8_t updateLed = divisor;
                    if (Oven.timeLeft == Oven.time0) {
                        LEDS_SET(0xFF);
                    }
                    if (Oven.timeLeft == Oven.time0 - 1) {
                        LEDS_SET(0xFE);
                    }
                    divisor = divisor + 1;
                    if (Oven.timeLeft == Oven.time0 - divisor) {
                        LEDS_SET(0xFC);
                    }
                    divisor = divisor + updateLed;
                    if (Oven.timeLeft == Oven.time0 - divisor) {
                        LEDS_SET(0xF8);
                    }
                    divisor = divisor + updateLed;
                    if (Oven.timeLeft == Oven.time0 - divisor) {
                        LEDS_SET(0xF0);
                    }
                    divisor = divisor + updateLed;
                    if (Oven.timeLeft == Oven.time0 - divisor) {
                        LEDS_SET(0xE0);
                    }
                    divisor = divisor + updateLed;
                    if (Oven.timeLeft == Oven.time0 - divisor) {
                        LEDS_SET(0xC0);
                    }
                    divisor = divisor + updateLed;
                    if (Oven.timeLeft == Oven.time0 - divisor) {
                        LEDS_SET(0x80);
                    }
                    divisor = divisor + updateLed;
                    if (Oven.timeLeft == Oven.time0 - divisor) {
                        LEDS_SET(OFF);
                    }


                    Oven.press = freeRunTime - timerStart;
                    countdown = (Oven.press - Oven.timeLeft);
                    if ((countdown % 7) == 0) { //was going too fast
                        Oven.timeLeft =Oven.timeLeft - 1;
                    }
                    Oven.state = COOKING;
                    timerTick = FALSE;
                    updateOvenOLED(Oven);
                } else {
                    //reset 
                    LEDS_SET(OFF);
                    updateOvenOLED(Oven);
                    Oven.state = SETUP;
                }
            }       //if BTN 4 pressed, reset 
            if (BUTTON_EVENT_4DOWN & check) {
                timerStart = freeRunTime;
                Oven.state = RESET_PENDING;
            }
            break;

        case RESET_PENDING:

            if (timerTick == TRUE) {
                if (BUTTON_EVENT_4UP & check) { //when oven is cooking and BTN4 is pressed for >1sec, leds turn off, oven returns to non cooking state, timer reset
                    Oven.press = freeRunTime - timerStart;
                    runningTime2 = Oven.press / 5;
                    if (runningTime2 >= 1) {
                        Oven.state = SETUP;
                        LEDS_SET(OFF);
                        updateOvenOLED(Oven);
                    } else {
                        Oven.state = COOKING;
                        updateOvenOLED(Oven);
                    }
                }
            }
            break;
    }
}

int main() {
    BOARD_Init();

    //initialize TIMErs and TIMEr ISRs:
    // <editor-fold defaultstate="collapsed" desc="TIMER SETUP">

    // Configure Timer 2 using PBCLK as enter. We configure it using a 1:16 prescalar, so each TIMEr
    // tick is actually at F_PB / 16 Hz, so setting PR2 to F_PB / 16 / 100 yields a .01s TIMEr.

    T2CON = 0; // everything should be off
    T2CONbits.TCKPS = 0b100; // 1:16 prescaler
    PR2 = BOARD_GetPBClock() / 16 / 100; // interrupt at .5s divisors
    T2CONbits.ON = 1; // turn the TIMEr on

    // Set up the TIMEr interrupt with a priority of 4.
    IFS0bits.T2IF = 0; //clear the interrupt flag before configuring
    IPC2bits.T2IP = 4; // priority of  4
    IPC2bits.T2IS = 0; // subpriority of 0 arbitrarily 
    IEC0bits.T2IE = 1; // turn the interrupt on

    // Configure Timer 3 using PBCLK as enter. We configure it using a 1:256 prescaler, so each TIMEr
    // tick is actually at F_PB / 256 Hz, so setting PR3 to F_PB / 256 / 5 yields a .2s TIMEr.

    T3CON = 0; // everything should be off
    T3CONbits.TCKPS = 0b111; // 1:256 prescaler
    PR3 = BOARD_GetPBClock() / 256 / 5; // interrupt at .5s divisors
    T3CONbits.ON = 1; // turn the TIMEr on

    // Set up the TIMEr interrupt with a priority of 4.
    IFS0bits.T3IF = 0; //clear the interrupt flag before configuring
    IPC3bits.T3IP = 4; // priority of  4
    IPC3bits.T3IS = 0; // subpriority of 0 arbitrarily 
    IEC0bits.T3IE = 1; // turn the interrupt on;

    // </editor-fold>

    printf("Welcome to khumpal's Lab07 (Toaster Oven).  Compiled on %s %s.", __TIME__, __DATE__);

    //initialize state machine (and anything else you need to init) here
    BOARD_Init();
    LEDS_INIT();
    OledInit();
    AdcInit();
    
    Oven.state = SETUP;
    Oven.enter = TIME;
    Oven.time0 = (AdcRead() >> 2) + 1;
    Oven.cook = BAKE;
    Oven.temp = 350;
    updateOvenOLED(Oven);

    while (1) {
        // Add main loop code here:
        // check for events
        if ((adc == TRUE) || (button == TRUE)) {
            runOvenSM();
            // clear event flags
            adc = FALSE;
            button = FALSE;
        }
    }
}

/*The 5hz TIMEr is used to update the free-running TIMEr and to generate timerTick events*/
void __ISR(_TIMER_3_VECTOR, ipl4auto) TimerInterrupt5Hz(void) {
    // Clear the interrupt flag.
    IFS0CLR = 1 << 12;

    //add event-checking code here
    if (eventTime == TRUE) {
        freeRunTime++;
        timerTick = TRUE;
    }
}

/*The 100hz TIMEr is used to check for button and ADC events*/
void __ISR(_TIMER_2_VECTOR, ipl4auto) TimerInterrupt100Hz(void) {
    // Clear the interrupt flag.
    IFS0CLR = 1 << 8;

    //add event-checking code here
    if (AdcChanged()) {
        adc = TRUE;
        timerTick = TRUE;
    }
    if ((BUTTON_EVENT_4DOWN) || (BUTTON_EVENT_4UP) || (BUTTON_EVENT_3DOWN) || (BUTTON_EVENT_3UP)) { 
        check = ButtonsCheckEvents();
        button = TRUE;
    }

}