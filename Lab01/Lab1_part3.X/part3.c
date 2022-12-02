// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <math.h>

//CMPE13 Support Library
#include "BOARD.h"
#include "Ascii.h"
#include "OledDriver.h"


// User libraries


// **** Set macros and preprocessor directives ****

// **** Define global, module-level, or external variables here ****
typedef enum {
    OLED_COLOR_BLACK = 0,
    OLED_COLOR_WHITE = 1
} OledColor;

// **** Declare function prototypes ****
#define OLED_NUM_LINES 
#define OLED_CHARS_PER_LINE

int main() {
    BOARD_Init();
    {
      OledInit();
      OledDrawString("Hello\nWorld");
      OledUpdate();
                
        
        
        // You can never return from main() in an embedded system (one that lacks an operating system).
        // This will result in the processor restarting, which is almost certainly not what you want!
        while (1);
    }
}


