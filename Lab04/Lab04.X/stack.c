// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//CMPE13 Support Library
#include "BOARD.h"



// User libraries
#include "rpn.h"
#include "stack.h"



void StackInit(struct Stack *stack){
    stack -> currentItemIndex = -1; //initializing currentItemIndex to -1 , Empty Stack
    stack ->initialized = TRUE; // setting initialized to TRUE
}

int StackPush(struct Stack *stack, double value){
  if(stack ->initialized == TRUE && stack->currentItemIndex != (STACK_SIZE -1) ){
        stack ->currentItemIndex += 1;              //adds one to the Stack
        value = stack->stackItems[stack->currentItemIndex]; // Updates Stack Items
        return SUCCESS;
  }else {
      return STANDARD_ERROR;
  }
}
int StackPop(struct Stack *stack, double *value){
     if(stack->currentItemIndex == (-1)){ //Stack is already empty and there is nothing that can be removed
        return STANDARD_ERROR;
    } else if(stack ->initialized != TRUE){
        return STANDARD_ERROR;
    } else {
        *value=stack->stackItems[stack->currentItemIndex];
        stack ->currentItemIndex -= 1;
        return SUCCESS;
    }
}
int StackIsEmpty(const struct Stack *stack){
    if(stack->currentItemIndex == -1){
        return TRUE;
    }else if(stack ->initialized != TRUE){
        return STANDARD_ERROR;
    }else{
          return FALSE;
    }
}

int StackIsFull(const struct Stack *stack){
    if(stack->currentItemIndex == (STACK_SIZE -1)){ 
        return TRUE;
    }else{
        return FALSE;
    }
}
int StackGetSize(const struct Stack *stack){
    if(stack ->initialized != TRUE){
        return SIZE_ERROR;
    }else{
        
     return ((stack->currentItemIndex) + 1);
    }
}