// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

//CMPE13 Support Library
#include "BOARD.h"


// User libraries
#include "stack.h"
#include "rpn.h"
#include "rpn.c"
int main()
{
    BOARD_Init();

    printf("\n###### Beginning khumpal's stack test harness: ####\n\n");

    //What follows is starter code.  You will need to modify it!
    
    printf("Does StackInit() set the currentItemIndex appropriately?\n");
    struct Stack stack = {};
    StackInit(&stack);
    if (stack.currentItemIndex == -1) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }

    // Stack Push Testing
     printf("Does StackPush() increment the index?\n");
    double a = 12;
    StackPush(&stack, a);
    if (stack.currentItemIndex == 0) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }

 /*   printf("Does StackPush() return an error if the stack is not initialized?\n");
    double b = 12;
    if ((StackPush(&stack2, b)) == FALSE) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }
*/
    //StackPop Tests
    printf("Does StackPop() decrement the index?\n");
    double c;
    StackPop(&stack, &c);
    if (stack.currentItemIndex == -1) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }

 /*   printf("Does StackPop() return an error if the stack is not initialized?\n");
    double d;
    if ((StackPop(&stack2, &d)) == FALSE) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }
  */
    //StackisEmpty testing
    printf("Does StackIsEmpty() work when empty\n");
    if ((StackIsEmpty(&stack)) == TRUE) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }

    printf("Does StackIsEmpty() not work when something is pushed in?\n");
    double e = 0;
    StackPush(&stack,e);
    if ((StackIsEmpty(&stack)) == FALSE) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }

  //StackIsFull Tests

    printf("Does StackIsFull() return false when the stack is not full?\n");
    if ((StackIsFull(&stack)) == FALSE) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }
 /*       printf("Does StackIsFull() return an error when the stack is not initialized?\n");
    if ((StackIsFull(&stack2)) == FALSE) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }
  **/
    //StackGetSize tests
    printf("Does StackGetSize() return the right index size?\n");
    if ((StackGetSize(&stack)) == 1) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }

/*    printf("Does StackGetSize() return an error when the stack is not initialized?\n");
    if ((StackGetSize(&stack2)) == (SIZE_ERROR)) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }
 */

    
   
    BOARD_End();
    //test stackInit:
    while (1);
    return 0;
}


