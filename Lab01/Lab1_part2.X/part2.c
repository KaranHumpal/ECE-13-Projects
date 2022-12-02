// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <math.h>
//Class specific libraries
#include "BOARD.h"


// User libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    BOARD_Init();
    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    float fahr;
    float celsius;
    float kelv;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("    F      C\n"); //print line to format the header using amt of spaces 
    while (fahr <= upper) {
        celsius = (5.0 / 9.0)*(fahr - 32.0);
        int n = (int) (celsius < 0 ? (celsius - 0.5) : (celsius + 0.5)); //used this formula to round the float to the nearest int
        printf("%7.1f  %04d\n", (double) fahr, (int) n); //formatting depends on what was asked for, ex 7 width, 1 precision = %7.1f
        fahr = fahr + step;
    }
    printf("\n");
    printf("     K     F\n");
    while (kelv <= upper) {
        fahr = 1.8*(kelv - 273.15)+32; //equation to convert fahrenheit to Kelvin 
        printf("%3.3f %5f\n", (double) kelv, (double) fahr);
        kelv = kelv + step;
    }

        
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks.
     **************************************************************************************************/

    // Returning from main() is bad form in embedded environments. So we sit and spin.
    while (1);
}
