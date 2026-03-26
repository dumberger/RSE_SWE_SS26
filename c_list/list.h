#pragma once

#include <stdbool.h>

typedef struct ListNode_t {
    int value;
    struct ListNode_t* next;
} ListNode;

typedef struct {
    ListNode* first;
} List;

List listCreate();
bool listGet(List list, unsigned int index, int* val);
void listPushBack(List* list, int value);
void listDelete(List* list);
void listRemove(List* list, unsigned int index);
void printList(List list);
unsigned int listLength(List list);