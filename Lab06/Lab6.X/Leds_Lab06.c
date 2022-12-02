#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

void LEDS_INIT(void){
    TRISE = 0x00;
    LATE = 0x00;
}

void LEDS_SET(char newPattern) {
    LATE = newPattern;
}

char LEDS_GET(void){
    return LATE;
}