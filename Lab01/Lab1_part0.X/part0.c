/* 
 * File:   part0.c
 * Author: Karan Humpal
 *
 * Created on March 30, 2022, 4:55 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "BOARD.h"

/*
 * 
 */
int main(void) 
{
    BOARD_Init();
    printf("Hello World\n");
    
    BOARD_End();
    while (1);

}

