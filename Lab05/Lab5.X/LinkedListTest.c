
#include <stdio.h>
#include <stdlib.h>
#include "BOARD.h"
#include <string.h>
#include "LinkedList.h"



int main() {
    BOARD_Init();
    
    printf("Linked List Testing\n\n");
    printf("First value in brackets is code generated output ");
    printf("Second value in brackets is hard-coded ");
    printf("_________________________________\n");

    //LinkedListNew Tests
    printf("LinkedListNew()\n");
    printf("Test 1\n");

    ListItem *list = LinkedListNew("karan");
    LinkedListPrint(list);
    printf("\n");
    printf("[karan]\n");
    printf("\n");

    printf("Test 2\n");
    ListItem *list2 = LinkedListNew("4545"); 
    LinkedListPrint(list2);
    printf("\n");
    printf("[4545]\n");

    printf("_________________________________\n");
 
    //LinkedListCreateAfter()
    printf("LinkedListCreateAfter() \n\n");
    printf("Test 1\n");
    
    LinkedListCreateAfter(list, "humpal");
    LinkedListPrint(list);
    printf("\n");
    printf("[karan - humpal]\n\n");
 

    printf("Test 2\n");
    ListItem *second =LinkedListCreateAfter(list, "singh");
    LinkedListPrint(list);
    printf("\n");
    printf("[karan - singh - humpal]\n");
    
    
    printf("_________________________________\n");
    
        //LinkedListRemove()
    char* wordList[] = {"D", "A", "C", "E", "B", NULL};


    int i = 0;
    ListItem* head = LinkedListNew(wordList[i]);
    ListItem* tail = head;
    for (i = 1; wordList[i] != NULL; i++) {
        tail = LinkedListCreateAfter(tail, wordList[i]);
        if (tail == NULL) {
            printf("ERROR:  Heap full! Please increase heap size.\n");
            FATAL_ERROR();
        }
    }
    printf("LinkedListRemove() \n\n");
    printf("Test 1\n");
    LinkedListRemove(head->nextItem->nextItem); //removes C
    LinkedListPrint(head);
    printf("\n");
    printf("[D - A - E - B]\n\n");
 

    printf("Test 2\n");
    LinkedListRemove(tail->previousItem);
    LinkedListPrint(tail);
    printf("\n");
    printf("[D - A - B]\n");
    printf("_________________________________\n");
    
    //LinkedListGetFirst ()
    printf("LinkedListGetFirst() \n\n");
    printf("Test 1\n");
    ListItem *first;
    first = LinkedListGetFirst(list);
    printf("%s", first->data);
    printf("\n");
    printf("karan\n\n");
 

    printf("Test 2\n");
    ListItem *first2;
    first2 = LinkedListGetFirst(list2);
    printf("%s", first2->data);
    printf("\n");
    printf("4545\n");
    //    
    //    
    printf("_________________________________\n");
    //LinkedListGetLast ()
    printf("LinkedListGetLast() \n\n");
    printf("Test 1\n");
    ListItem *last;
    last = LinkedListGetLast(list);
    printf("%s", last->data);
    printf("\n");
    printf("humpal\n\n");
 

    printf("Test 2\n");
    ListItem *last2;
    last2 = LinkedListGetLast(list2);
    printf("%s", last2->data);
    printf("\n");
    printf("4545\n");

    printf("_________________________________\n");
    
    //LinkedListSize()
    printf("LinkedListSize() \n\n");
    printf("Test 1\n");
    int size;
    size = LinkedListSize(list);
    printf("%d", size);
    printf("\n");
    printf("3\n\n");
 

    printf("Test 2\n");
    int size2;
    size2 = LinkedListSize(list2);
    printf("%d", size2);
    printf("\n");
    printf("1\n");
    
    printf("_________________________________\n");
    //LinkedListSwapData()
    printf("LinkedListSwapData() \n\n");
    printf("Test 1\n");
    LinkedListSwapData(list,second);
    LinkedListPrint(list);
    printf("\n");
    printf("[singh - karan - humpal]\n\n");
 

    printf("Test 2\n");
    LinkedListSwapData(list,second);
    LinkedListPrint(list);
    printf("\n");
    printf("[karan - singh - humpal]\n");
    printf("_________________________________\n");
    
    

}









