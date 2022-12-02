
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BOARD.h"
#include "Field.h"

Field userField;
Field opponentField; 
GuessData userGuess;
GuessData opponentGuess;

void printField(Field *own_field);
void printField(Field *own_field){
    int c=0;
    printf("\t    0 1 2 3 4 5 6 7 8 9\n");
    printf("\t    | | | | | | | | | |\n");
    printf("\t%d - ",c);
    for (int a = 0; a < FIELD_ROWS; a =a+ 1) {
        for (int b = 0; b < FIELD_COLS; b =b+ 1) {
            printf("%d ", own_field->grid[a][b]);
        }
        if (c < 5){
            printf("\n");
            c =c+ 1;
            printf("\t%d - ", c);
        }    
    }
        
}

int main() {
    BOARD_Init(); 
    printf("FIELD.C TESTS:\n");
    
    //FieldInit Test
    printf("FieldInit();\n");
    printf("\tOpponent's Field before FieldInit(): %d\n", opponentField.grid[0][0]);
    FieldInit(&userField, &opponentField);
    printf("\tOpponent's Field after FieldInit(): %d\n\n", opponentField.grid[0][0]);
    
    //FieldGetSquareStatus Test
    printf("FieldGetSquareStatus():\n");
    printf("\tSquare Status userField expected: 0\n");
    printf("\tSquare Status userField actual: %d\n\n", FieldGetSquareStatus(&userField, 0, 0));
    printf("\tSquare Status opponentField expected: 5\n");
    printf("\tSquare Status opponentField actual: %d\n\n", FieldGetSquareStatus(&opponentField, 0, 0));
    
    //FieldSetSquareStatus Test
    printf("FieldSetSquareStatus():\n");
    printf("\t Set Status (0, 1) to 3\n");
    FieldSetSquareStatus(&userField, 0, 1, FIELD_SQUARE_LARGE_BOAT);
    printf("\tGet Status: %d\n\n", FieldGetSquareStatus(&userField, 0, 1));
    printf("\t Set Status (4, 2) to 2\n");
    FieldSetSquareStatus(&userField, 4, 2, FIELD_SQUARE_MEDIUM_BOAT);
    printf("\t Get Status: %d\n\n", FieldGetSquareStatus(&userField, 4, 2));
    
    
    //FieldAddBoat Test
    FieldInit(&userField, &opponentField);
    printf("FieldAddBoat():\n");
    FieldAddBoat(&userField, 0, 0, FIELD_DIR_SOUTH, FIELD_BOAT_TYPE_HUGE);
    printf("\tAdding a Huge boat (0,0) pointing south: \n");
    printField(&userField);
    printf("\n\tChecking lives of Huge boat: ");
    printf("%d\n\n", userField.hugeBoatLives);
    FieldAddBoat(&userField, 4, 6, FIELD_DIR_EAST, FIELD_BOAT_TYPE_SMALL);
    printf("\tAdding a Small boat (4,6) pointing east:\n");
    printField(&userField);
    printf("\n\tChecking lives of small boat: ");
    printf("%d\n\n", userField.smallBoatLives);
    
    //FieldRegisterEnemyAttacks Test
    printf("FieldRegisterEnemyAttacks():\n");
    
    opponentGuess.row = 4;
    opponentGuess.col = 6;
    FieldRegisterEnemyAttack(&userField, &opponentGuess);
    printf("\tResult of Square (4,6) expected: 6\n");
    printf("\tResult of Square (4,6) actual: ");
    printf("%d\n", FieldGetSquareStatus(&userField, 4, 6));
    printf("\tChecking lives of small boat ");
    printf("%d\n\n", userField.smallBoatLives);
    
    opponentGuess.col = 7;
    FieldRegisterEnemyAttack(&userField, &opponentGuess);
    
    opponentGuess.col = 8;
    FieldRegisterEnemyAttack(&userField, &opponentGuess);
    printf("\tExpected result after sinking Small boat: 2\n");
    printf("\tActual result after sinking Small boat: ");
    printf("%d\n\n", opponentGuess.result);
    
    
    //FieldUpdateKnowledge() Tests
    printf("FieldUpdateKnowledge():\n");
    printf("\tResult of Hit on (2,3): \n");
    FieldAddBoat(&opponentField, 2, 3, FIELD_DIR_SOUTH, FIELD_BOAT_TYPE_SMALL);
    userGuess.row = 2;
    userGuess.col = 3;
    userGuess.result = RESULT_HIT;
    FieldUpdateKnowledge(&opponentField, &userGuess);
    printField(&opponentField);
    printf("\n");
    
    //FieldGetBoatStates() Tests
    printf("\nFieldGetBoatStates():\n");
    uint8_t state = FieldGetBoatStates(&userField);
    printf("\tCurrent Boat Status with Huge Boat alive expected: 8\n");
    printf("\tCurrent Boat Status with Huge Boat alive actual: ");
    printf("%d\n\n", state);

    //FieldAIPlaceAllBoats Tests
    printf("FieldAIPlaceAllBoats():\n");
    printf("\t Trial 1: \n");
    FieldInit(&userField, &opponentField);
    FieldAIPlaceAllBoats(&userField);
    printField(&userField);
    
    printf("\n\n\tTrial 2: \n");
    FieldInit(&userField, &opponentField);
    FieldAIPlaceAllBoats(&userField);
    printField(&userField);
    
    //FieldAIDecideGuess Test
    printf("\n\nFieldAIDecideGuess():\n");
    userGuess = FieldAIDecideGuess(&opponentField);
    printf("My First Guess: (%d, %d)\n", userGuess.row, userGuess.col);
    userGuess = FieldAIDecideGuess(&opponentField);
    printf("My Second Guess: (%d, %d)\n\n", userGuess.row, userGuess.col);
    
    
    FieldInit(&userField, &opponentField);
    BOARD_End();
    return SUCCESS;
    

}


