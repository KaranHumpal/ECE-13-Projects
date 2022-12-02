// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//CMPE13 Support Library
#include "BOARD.h"


// User libraries
#include "LinkedList.h"

ListItem *LinkedListNew(char *data){
    ListItem *newNode = (ListItem*)malloc(sizeof(ListItem)); //creates newNode pointer and typecasts as well as allocates memory in the heap for the right size
    newNode ->data = data;  //stores the data in the data portion of the struct
    newNode ->nextItem = NULL; //has the next and prev item as NULL indicating that this is the first node created
    newNode ->previousItem =NULL;
    if(newNode == NULL){      //Checks if the newNode is NULL, if it is it will return NULL, if not returns the data
        return NULL;
    }else{
            return newNode;
        }
    }
ListItem *LinkedListCreateAfter(ListItem *item, char *data){
    ListItem *addNode = (ListItem*)malloc(sizeof(ListItem));
    addNode ->data = data;  
    addNode ->previousItem = item; //points to Node we want to add After
    addNode->nextItem = item->nextItem;//the nextItem of the New node is the nextItem of item
    item -> nextItem = addNode;   
    
    if(addNode->nextItem == NULL){  
          item->nextItem=addNode; 
          return addNode;
    }
    else{
        item ->nextItem->previousItem = addNode;
        item->nextItem=addNode; 
        return addNode;
}
    
}

char *LinkedListRemove(ListItem *item) {
    if (item == NULL) {
        return NULL;
    } else {
        char *remove = item->data;
            if (item->nextItem == NULL) {
            (item->previousItem)->nextItem = NULL;
            free(item);
            return remove;
        }
                if (item->previousItem == NULL) {
            (item->nextItem)->previousItem = NULL;
            free(item);
            return remove;}
        
        if (item->nextItem == NULL && item->previousItem == NULL) {
            free(item);
            return remove;
        }

         else {
            (item->previousItem)->nextItem = item->nextItem;
            (item->nextItem)->previousItem = item->previousItem;
            free(item);
            return remove;
        }
    }
}
int LinkedListSize(ListItem *list){
    if (list == NULL) {
        return 0;
    }
    int count = 0;
    ListItem *size = LinkedListGetFirst(list);
    while (size != NULL) {
        count =count + 1;
        size = size->nextItem;
    }
    return count;
}

ListItem *LinkedListGetFirst(ListItem *list) {
    if (list == NULL) {
        return NULL;
    }
    while (list->previousItem != NULL) {
        list = list->previousItem;
    }
    return list;
}
ListItem *LinkedListGetLast(ListItem *list) {
    if (list == NULL) {
        return NULL;
    }
    while (list->nextItem != NULL) {
        list = list->nextItem;
    }
    return list;
}
int LinkedListSwapData(ListItem *firstItem, ListItem *secondItem){
    char *a;
    a = firstItem->data;
    char *b;
    b = secondItem->data;
    if (firstItem == NULL) {
        return STANDARD_ERROR;
    } else if (secondItem == NULL) {
        return STANDARD_ERROR;
    } else {
        secondItem->data = a;
        firstItem->data = b;
        return SUCCESS;
    }
     
}
int LinkedListPrint(ListItem *list){
    if (list == NULL) {
        return STANDARD_ERROR;
    } else {
        printf("[");
        ListItem *print = LinkedListGetFirst(list);
        while (print != NULL) {
            printf("%s", print->data);
            if (print->nextItem != NULL) {
                printf(" - ");
            }
            print = print->nextItem;
        }
    }
    printf("]");
    return SUCCESS;
    
}