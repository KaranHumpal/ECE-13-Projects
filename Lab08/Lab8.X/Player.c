// **** Include libraries here ****
// Standard libraries
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "Player.h"


static int Inventory[INVENTORY_SIZE];
int AddToInventory(uint8_t item) {
    int index = 0;
    if (index < (INVENTORY_SIZE)) {
        Inventory[index] = item;
        index = index + 1;
        return SUCCESS;
    } else {
        return STANDARD_ERROR;
    }
}

int FindInInventory(uint8_t item) {
    int index2 = 0;
    for (index2 = 0; index2 < INVENTORY_SIZE; index2 = index2 + 1) {
        if (Inventory[index2] == item) {
            return SUCCESS;
        }
    }
    return STANDARD_ERROR;
}


