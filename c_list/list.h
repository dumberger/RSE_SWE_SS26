// Comments here for understanding code and learning
#pragma once

#include <stdbool.h>

// Structure to define a node 
    // <-   [prev]
    //      [VALUE]
    //      [next]  ->
typedef struct ListNode_t {
    int value;
    struct ListNode_t* next;
    struct ListNode_t* prev;
} ListNode;

// Structure tp define a list
    // [first] - [x] - [x] - [x] - [last]
typedef struct {
    ListNode* first;
    ListNode* last;
} List;

// Functions to use the list
List listCreate();

bool listGet(List list, unsigned int index, int* val);
void listPushBack(List* list, int value);
void listDelete(List* list);
void listRemove(List* list, unsigned int index);

void printList(List list);
void printReverseList(List list);

unsigned int listLength(List list);