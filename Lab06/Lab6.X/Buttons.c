#include <stdio.h>
#include <stdlib.h>
#include "Buttons.h"


/*
 * 
 */
uint8_t current;
int press1 = FALSE;
int press2 = FALSE;
int press3 = FALSE;
int press4 = FALSE;
int b1 = FALSE;
int b2 = FALSE;
int b3 = FALSE;
int b4 = FALSE;


void ButtonsInit(void) {
    TRISD |= 0x00E0;
    TRISF |= 0x0002;
}

uint8_t ButtonsCheckEvents(void) {
    uint8_t current = 0;
    uint8_t buttonsState = BUTTON_STATES();
        while (1) {
        if (press1 == TRUE) {
            if ((buttonsState & BUTTON_STATE_1) != BUTTON_STATE_1) {
                current = current | BUTTON_EVENT_1UP;
                press1 = FALSE;
                b1 = TRUE;
            }

        } else if (buttonsState & BUTTON_STATE_1) {
            current = current | BUTTON_EVENT_1DOWN;
            press1 = TRUE;
            b1 = FALSE;
        } else if (b1 == press1) {
            b1 = FALSE;
            return BUTTON_EVENT_NONE;
        }

        if (press2 == TRUE) {
            if ((buttonsState & BUTTON_STATE_2) != BUTTON_STATE_2) {
                current = current | BUTTON_EVENT_2UP;
                press2 = FALSE;
                b2 = TRUE;
            }
        } else if (buttonsState & BUTTON_STATE_2) {
            current = current | BUTTON_EVENT_2DOWN;
            press2 = TRUE;
            b2 = FALSE;
        } else if (b2 == press2) {
            b2 = FALSE;
            return BUTTON_EVENT_NONE;
        }

        if (press3 == TRUE) {
            if ((buttonsState & BUTTON_STATE_3) != BUTTON_STATE_3) {
                current = current | BUTTON_EVENT_3UP;
                press3 = FALSE;
                b3 = TRUE;
            }
        } else if (buttonsState & BUTTON_STATE_3) {
            current = current | BUTTON_EVENT_3DOWN;
            press3 = TRUE;
            b3 = FALSE;
        } else if (b3 == press3) {
            b3 = FALSE;
            return BUTTON_EVENT_NONE;
        }

        if (press4 == TRUE) {
            if ((buttonsState & BUTTON_STATE_4) != BUTTON_STATE_4) {
                current = current | BUTTON_EVENT_4UP;
                press4 = FALSE;
                b4 = TRUE;
            }
        } else if (buttonsState & BUTTON_STATE_4) {
            current = current | BUTTON_EVENT_4DOWN;
            press4 = TRUE;
            b4 = FALSE;
        } else if (b4 == press4) {
            b4 = FALSE;
            return BUTTON_EVENT_NONE;
        }
        return current;


    }
}

