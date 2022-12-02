// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//CMPE13 Support Library
#include "BOARD.h"



// User libraries
#include "rpn.h"
#include "stack.h"
struct Stack stack;

/*int validToken(char *z){
    
    for(int k=0;k<strlen(z);k++){
        if(!(isdigit(z[k])==1 || z[k] == '+' || z[k]=='-'||z[k]=='*'||z[k]=='/')){
            return RPN_ERROR_INVALID_TOKEN;       
        }  
    }
    return 1;
} 
 */
int RPN_Evaluate(char * rpn_string, double * result){
    double pop1, pop2,result1,resultneg,result3;
    char *rpn[500];
    int i = 0;
    //taking out the spaces
    rpn[i] = strtok(rpn_string, " ");
    while (rpn[i] != NULL) {
        i += 1;
        rpn[i] = strtok(NULL, " ");
    }
    StackInit(&stack);
    for(int j=0;j<strlen(*rpn);j++){
        if(*rpn[j]== '+'){
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
         StackPop(&stack, &pop1); 
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
          StackPop(&stack, &pop2);
          result1=pop1+pop2;
           if (stack.currentItemIndex == (STACK_SIZE - 1)) {
            return RPN_ERROR_STACK_OVERFLOW;
        }
          StackPush(&stack,result1);
    }
        else if(*rpn[j]== '-'){
            if((rpn[j])[1]){
              resultneg = atof(rpn[j]);
            StackPush(&stack, resultneg);
            }
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
         StackPop(&stack, &pop1); 
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
          StackPop(&stack, &pop2);
          result1=pop2-pop1;
           if (stack.currentItemIndex == (STACK_SIZE - 1)) {
            return RPN_ERROR_STACK_OVERFLOW;
        }
          StackPush(&stack,result1);
    }
        else if(*rpn[j]== '*'){
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
         StackPop(&stack, &pop1); 
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
          StackPop(&stack, &pop2);
          result1=pop1*pop2;
           if (stack.currentItemIndex == (STACK_SIZE - 1)) {
            return RPN_ERROR_STACK_OVERFLOW;
        }
          StackPush(&stack,result1);
    }
        else if(*rpn[j]== '/'){
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
         StackPop(&stack, &pop1); 
           if (stack.currentItemIndex == -1) {
            return RPN_ERROR_STACK_UNDERFLOW;
        }
          StackPop(&stack, &pop2);
          if(pop1==0){
              return RPN_ERROR_DIVIDE_BY_ZERO;
          }else{
          result1=pop2/pop1;
           if (stack.currentItemIndex == (STACK_SIZE - 1)) {
            return RPN_ERROR_STACK_OVERFLOW;
        }
          StackPush(&stack,result1);
    }
    
    
    }
        else if(isdigit(*rpn[j])==1){
        result3 = atof(rpn[j]);
        StackPush(&stack, result3);
        }  
        else{
            return RPN_ERROR_INVALID_TOKEN;
            
        }
} *result = result1;
    
        if (stack.currentItemIndex > 0) {
        return RPN_ERROR_TOO_MANY_ITEMS_REMAIN;
        }
    
        if (stack.currentItemIndex < 0) {
        return RPN_ERROR_TOO_FEW_ITEMS_REMAIN;
        }
    return RPN_NO_ERROR;
}