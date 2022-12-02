

#include <stdio.h>
#include <stdlib.h>
#include "BOARD.h"
#include "Agent.h"
#include "Message.h"
#include "Field.h"
#include "BattleBoats.h"
#include "Oled.h"
#include "Negotiation.h"

BB_Event event;
Field user_Field;

int main() {
    BOARD_Init();
    
    AgentInit();
    
    //AgentInit test
    printf("AgentInit() Test\n");
    printf("\tCurrent State expected: 0\n");
    printf("\tCurrent State actual: %d\n\n", AgentGetState());
    
    //AgentRun Test
    printf("AgentRun() Test\n");
    
    event.type = BB_EVENT_START_BUTTON;
    AgentRun(event);
    printf("\tThe state after pressing start button expected: 1\n");
    printf("\tThe state after pressing start button actual: %d\n\n", AgentGetState());
    
    event.type = BB_EVENT_ACC_RECEIVED;
    AgentRun(event);
    printf("\tThe state after accepting the challenge expected: 4\n");
    printf("\tThe state after accepting the challenge actual: %d\n\n", AgentGetState());
    
    event.type = BB_EVENT_SHO_RECEIVED;
    AgentRun(event);
    printf("\tThe state after Enemy Shot received should be: 5\n");
    printf("\tThe state after Enemy Shot received is: %d\n", AgentGetState());
    printf("\t");
    AgentRun(event);
    
    printf("\n\n");
    AgentInit();
    printf("Restarting Game\n");
    event.type = BB_EVENT_CHA_RECEIVED;
    AgentRun(event);
    printf("\tThe state after receiving challenge expected: 2\n");
    printf("\tThe state after receiving challenge actual: %d\n\n", AgentGetState());
    
    event.type = BB_EVENT_REV_RECEIVED;
    AgentRun(event);
    printf("\tThe state after receiving revealed message expected: 4\n");
    printf("\tThe state after receiving revealed message actual: %d\n\n", AgentGetState());
    
    event.type = BB_EVENT_RES_RECEIVED;
    AgentRun(event);
    printf("\tThe state after receiving result expected: 4\n");
    printf("\tThe state after receiving result actual: %d\n", AgentGetState());
    
    
    while (1);
    BOARD_End();
}

