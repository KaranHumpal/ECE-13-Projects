// **** Include libraries here ****
// Standard libraries
#include <string.h>
#include <math.h>
#include <stdio.h>


//CSE013E Support Library
#include "UNIXBOARD.h"
#include "Player.h"
#include "Game.h"

// User libraries


// **** Set any macros or preprocessor directives here ****

// **** Define any global or external variables here ****
uint8_t leave = 0000;
// **** Declare any data types here ****

struct RPG {
    int north;
    int east;
    int south;
    int west;
    char title[40];
    char description[300];
    char version1[300];
    char version2[300];
} RPG;



int create(uint8_t Room) {
    char room[300];
    sprintf(room, "RoomFiles/room%d.txt", Room);
    
    uint8_t descNum1 = 0;
    uint8_t descNum1a = 0;
    uint8_t descNum2 = 0;
    uint8_t descNum2a = 0;
    

    FILE *file;
    file = fopen(room, "rb");
    if (file == NULL) {
        FATAL_ERROR();
    }

    fseek(file, 3, SEEK_SET);
    int titleLength = fgetc(file);
    fread(RPG.title, 1, titleLength, file);
    
    
    RPG.title[titleLength] = '\0';
    descNum1 = fgetc(file);
    
    if (descNum1 > 0)
    {
        descNum1a = fgetc(file);
    }
    int x = fgetc(file);

    fread(RPG.version1, 1, x, file);
    RPG.version1[x] = '\0';

    fseek(file, 1, SEEK_CUR);

    int north1 = fgetc(file);
    int east1 = fgetc(file);
    int south1 = fgetc(file);
    int west1 = fgetc(file);


    if (descNum1 > 0) {
        fseek(file, 1, SEEK_CUR);
        int descriptionLegnth = fgetc(file);
        fread(RPG.version2, 1, descriptionLegnth, file);
        RPG.version2[descriptionLegnth] = '\0';


        descNum2 = fgetc(file);
        if (descNum2 > 0) {
            descNum2a = fgetc(file);
        }
        int north2 = fgetc(file);
        int east2 = fgetc(file);
        int south2 = fgetc(file);
        int west2 = fgetc(file);

        if (descNum1 > 0 && (FindInInventory(descNum1a) == SUCCESS)) {
            strcpy(RPG.description, RPG.version1);
            RPG.north = north1;
            RPG.east = east1;
            RPG.south = south1;
            RPG.west = west1;
        } else {
            strcpy(RPG.description, RPG.version2);
            RPG.north = north2;
            RPG.east = east2;
            RPG.south = south2;
            RPG.west = west2;
        }
        
    } else {
        strcpy(RPG.description, RPG.version1);
            RPG.north = north1;
            RPG.east = east1;
            RPG.south = south1;
            RPG.west = west1;
    }




    if (descNum2 > 0) {
        AddToInventory(descNum2a);
    }

    fclose(file);

    return SUCCESS;
}


int GameGoNorth(void){
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_NORTH_EXISTS) {
        create(RPG.north);
        return SUCCESS;
    } else{
            
       return STANDARD_ERROR;     
    }
    
}

int GameGoEast(void){
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_EAST_EXISTS) {
        create(RPG.east);
        return SUCCESS;
    } else{
            
       return STANDARD_ERROR;     
    }
    
}

int GameGoSouth(void){
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_SOUTH_EXISTS) {
        create(RPG.south);
        return SUCCESS;
    } else{
            
       return STANDARD_ERROR;     
    }
    
}

int GameGoWest(void){
        if (GameGetCurrentRoomExits() & GAME_ROOM_EXIT_WEST_EXISTS) {
        create(RPG.west);
        return SUCCESS;
    } else{
            
       return STANDARD_ERROR;     
    }
    
}

int GameInit(void){
    create(STARTING_ROOM);
    return SUCCESS;
}

int GameGetCurrentRoomTitle(char *title){
    strcpy(title, RPG.title);
    int a;
    a = strlen(title);
    return a;
}
int GameGetCurrentRoomDescription(char *desc) {
    strcpy(desc, RPG.description);
    int b;
    b = strlen(desc);
    return b;
}
uint8_t GameGetCurrentRoomExits(void) {
    
    if (RPG.north > 0) {
        leave = (leave | GAME_ROOM_EXIT_NORTH_EXISTS);
    }
    if (RPG.east > 0) {
        leave = (leave | GAME_ROOM_EXIT_EAST_EXISTS);
    }
    if (RPG.south > 0) {
        leave = (leave | GAME_ROOM_EXIT_SOUTH_EXISTS);
    }
    if (RPG.west > 0) {
        leave = (leave | GAME_ROOM_EXIT_WEST_EXISTS);
    }
    return leave;
}
