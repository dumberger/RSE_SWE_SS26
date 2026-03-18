#include "list.h"
#include <stdlib.h>

List listCreate() {
    List list;
    list.first = NULL;
    return list;
}

bool listGet(List list, unsigned int index, int* val) {
    ListNode* node = list.first;
    for (int i = 0; i < index; i++) {
        if (node == NULL) {
            return false;
        }
        node = node->next;
    }
    *val = node->value;
    return true;
}

void listPushBack(List* list, int value) {
    ListNode* node = list->first;
    if (node == NULL) {
        ListNode* newNode = malloc(sizeof(ListNode));
        if (newNode == NULL) {
            exit(1);
        }
        newNode->value = value;
        newNode->next = NULL;
        list->first = newNode;
        return;
    }
    while(node->next != NULL) {
        node = node->next;
    }
    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    node->next = newNode;
    return;
}

void listDelete(List* list) {
    while(listLength(*list) > 0) {
        listRemove(list, 0);
    }
}

void listRemove(List* list, unsigned int index){
    ListNode* node = list->first;
    if (list->first == NULL) {
        return;
    }
    ListNode* tmp;
    if(index == 0) {
        list->first = node->next;
        free(node); node = NULL;
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
        if (node->next == NULL) {
            return;
        }
    }
    tmp = node->next;
    node->next = tmp->next;
    free(tmp); tmp = NULL;
    return;
}

void printList(List list){
    //HOMEWORK
}

unsigned int listLength(List list) {
    unsigned int len = 0;
    for (ListNode* i = list.first; i != NULL; i = i->next) {
        len++;
    }
    return len;
}