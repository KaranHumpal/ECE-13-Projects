#include <stdio.h>
#include <stdlib.h>
#include "BOARD.h"
#include "Agent.h"
#include "Message.h"
#include "Field.h"
#include "BattleBoats.h"
#include "Oled.h"
#include "Negotiation.h"

/*
 * 
 */
static Field user_Field;
static Field opponent_Field;
static int turn;
static int cheating;
static int win;
static int loss;
static NegotiationData A;
static NegotiationData hashA;
static NegotiationData B;
static AgentState status;
static GuessData guess;
static uint8_t check;


void AgentInit(void) {
    status = AGENT_STATE_START;
    turn = 0;
}

Message AgentRun(BB_Event event) {
    Message output;
    
    switch(status) {
        case(AGENT_STATE_START):
            if (event.type == BB_EVENT_START_BUTTON) {
                A = (NegotiationData)rand();
                hashA = NegotiationHash(A);
                output.type = MESSAGE_CHA;
                output.param0 = hashA;
                FieldInit(&user_Field, &opponent_Field);
                FieldAIPlaceAllBoats(&user_Field);    
                status = AGENT_STATE_CHALLENGING;
            }
            if (event.type == BB_EVENT_CHA_RECEIVED) {
                B = (NegotiationData)rand();
                output.type = MESSAGE_ACC;
                output.param0 = B;
                FieldInit(&user_Field, &opponent_Field);
                FieldAIPlaceAllBoats(&user_Field);
                
                status = AGENT_STATE_ACCEPTING;
            }
            break;
            
        case AGENT_STATE_CHALLENGING:
            if (event.type == BB_EVENT_ACC_RECEIVED) {
                output.type = MESSAGE_REV;
                output.param0 = A;
                if (NegotiateCoinFlip(A, B) == HEADS) {
                    //printf("a");
                    status = AGENT_STATE_WAITING_TO_SEND;
                } else {
                    //printf("b");
                    status = AGENT_STATE_DEFENDING;
                }
            }
            break;
            
        case AGENT_STATE_ACCEPTING:
            if (event.type == BB_EVENT_REV_RECEIVED) {
                if (NegotiationVerify(A, hashA) == TRUE) {
                    if (NegotiateCoinFlip(A, B) == HEADS) {
                        status = AGENT_STATE_DEFENDING;
                    } else {
                        guess = FieldAIDecideGuess(&opponent_Field);
                        output.type = MESSAGE_SHO;
                        output.param0 = guess.row;
                        output.param1 = guess.col;
                        status = AGENT_STATE_ATTACKING;
                    }
                } else {
                    cheating = TRUE;
                    status = AGENT_STATE_END_SCREEN;
                }
            }
            break;
            
        case AGENT_STATE_DEFENDING:
            if (event.type == BB_EVENT_SHO_RECEIVED) {
                guess.row = event.param0;
                guess.col = event.param1;
                FieldRegisterEnemyAttack(&user_Field, &guess);
                        
                output.type = MESSAGE_RES;
                output.param0 = guess.row;
                output.param1 = guess.col;
                output.param2 = guess.result;
                
                check = FieldGetBoatStates(&user_Field);
                if (check == 0) {
                    loss = TRUE;
                    status = AGENT_STATE_END_SCREEN;
                } else {
                    status = AGENT_STATE_WAITING_TO_SEND;
                }
            }
            break;
            
        case AGENT_STATE_WAITING_TO_SEND:
            if (event.type == BB_EVENT_MESSAGE_SENT) {
                turn += 1;
                guess = FieldAIDecideGuess(&opponent_Field);
                output.type = MESSAGE_SHO;
                output.param0 = guess.row;
                output.param1 = guess.col;
                status = AGENT_STATE_ATTACKING;
            } 
            break;
            
        case AGENT_STATE_ATTACKING:
            if (event.type == BB_EVENT_RES_RECEIVED) {
                FieldUpdateKnowledge(&opponent_Field, &guess);
                check = FieldGetBoatStates(&opponent_Field);
                if (check == 0) {
                    win = TRUE;
                    status = AGENT_STATE_END_SCREEN;
                } else {
                    status = AGENT_STATE_DEFENDING;
                }
            }
            break;
            
        case AGENT_STATE_SETUP_BOATS:

        case AGENT_STATE_END_SCREEN:
            if (cheating == TRUE) {
                OledInit();
                OledDrawString("CHEATING!");
                OledUpdate();
            } else if (loss == TRUE) {
                OledInit();
                OledDrawString("You Lose!");
                OledUpdate();
            } else if (win == TRUE) {
                OledInit();
                OledDrawString("You Win!");
                OledUpdate();
            }
            
    } 
    return output;
}

AgentState AgentGetState(void) {
    return status;
}

void AgentSetState(AgentState newState) {
    status = newState;
    return;
}
