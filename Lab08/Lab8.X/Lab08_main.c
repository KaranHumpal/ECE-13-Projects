
// **** Include libraries here ****
// Standard libraries
#include <string.h>
#include <math.h>
#include <stdio.h>

//CSE013E Support Library
#include "UNIXBOARD.h"
#include "Game.h"
#include "Player.h"



// User libraries


// **** Set any macros or preprocessor directives here ****

// **** Declare any data types here ****

// **** Define any global or external variables here ****

// **** Declare any function prototypes here ****

int main()
{



    /******************************** Your custom code goes below here ********************************/
 char title[GAME_MAX_ROOM_TITLE_LENGTH];
    char desc[GAME_MAX_ROOM_DESC_LENGTH];

    if (GameInit() != SUCCESS) {
        FATAL_ERROR();
    }
    while(1) {
        GameGetCurrentRoomTitle(title);
        printf("\n\t\t\t\t%s\n\n",title);
        GameGetCurrentRoomDescription(desc);
        printf("%s\n\n", desc);

        int north;
        int south;
        int east;
        int west;
        printf("Available Exit(s): ");
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_NORTH_EXISTS) {
            north = 1;
            printf("North ");
        }
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_SOUTH_EXISTS) {
            south = 1;
            printf("South ");
        }
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_EAST_EXISTS) {
            east = 1;
            printf("East ");
        }
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_WEST_EXISTS) {
            west = 1;
            printf("West ");
        }

        printf("\n\n");
        printf("North, South, East, or West (Press: n, s, e, w, or q to quit): \n");
        char input = getchar();
        while ((getchar()) != '\n');
        if ((input == 'n') && (north == 1)) {
            GameGoNorth();
        } else if (input == 's' && south == 1) {
            GameGoSouth();
        } else if (input == 'e' && east == 1) {
            GameGoEast();
        } else if (input == 'w' && west == 1) {
            GameGoWest();
        } else if (input == 'q') {
            break;
        } else {
            printf("ERROR");
            
        }
    }




    /**************************************************************************************************/
}