// Comments here for understanding code and learning

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

// Functiom listCreate()
    // Creates a list and returns list of type List defined in .h
    // A list has a first and last position; at init first and last are NULL
    // When single list-node fist == last
List listCreate() {
    List list;
    list.first = NULL;
    list.last = NULL;
    return list;
}

// Function listGet(List list, unsigned int index, int* val)
    // Gets the value of list pointed to at index position
    // Get length of list and check if index is not equal or greater
    // If the index is in the lower half 
        // From First element go through all nodes and check if they exist, until index is reached
        // Point to the value of the node at index position
    // If the index is in the upper half
        // Do the same, but starting from last node and go through all previous nodes until index is reached
bool listGet(List list, unsigned int index, int* val) {
    unsigned int len = listLength(list);

    if(index >= len)
    {
        return false;
    }

    if(index <= (len / 2)){
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

    else if(index > (len / 2)) {
        ListNode* node = list.last;
        for (int i = len - 1; i > index; i--) {
            if (node == NULL) {
                return false;
            }
            node = node->prev;
        }
        *val = node->value;
        return true;
    }

    else{
        return false;
    }
}

// Function listPushBack(List* list, int value)
    // Pushes (appends) a node with value to the end (last)
    // If no node exists ...
        // Ask for memory for a new node 
        // Store the value, Since first node prev and next point to Null
        // The newNode is also the first and last list element
    // Since appending at last element no while is needed (unlike simple linked list)
        // Ask for memory and create new listNode, Store the value, next points to Null, prev points to previous node
        // Older node gets newNode as next, the list->last ist updated to newNode
void listPushBack(List* list, int value) {
    ListNode* node = list->last;

    if (node == NULL) {
        ListNode* newNode = malloc(sizeof(ListNode));
        if (newNode == NULL) {
            exit(1);
        }
        newNode->value = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        list->first = newNode;
        list->last = newNode;
        return;
    }

    // while(node->next != NULL) {node = node->next;} not necessary because already starting with last; last is known as doubly linked list posseses first & last

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = node;
    node->next = newNode;
    list->last = newNode;
    return;
}

// Function listDelete(List* list)
    // Deletes a list starting with the first element
        // Use a node and tmp Pointer to point to ListNodes
        // As long as node does point to somewhere not NULL ...
        // Look for the next node and store this to tmp
        // Clear the current node and store tmp to node
        // This "bounces" from one node to the next, starting with the first
    // Finish by declaring that first and last point to NULL (no list elements stored)
void listDelete(List* list) {
    ListNode* node = list->first;
    ListNode* tmp;

    while(node != NULL){
        tmp = node->next;
        free(node); node = tmp;  
    }
    list->first = NULL;
    list->last = NULL;
    
    // Inefficient, as listLength and listRemove have to go through list as well with every cycle
    // while(listLength(*list) > 0) {listRemove(list, 0);}
}

// Function listRemove()
    // First check if there even exists a node to remoe (first and last cannot point to NULL)
    // Also check if something within the list index cannot be greater listLength-1
    // Now create two ListNode pointer
        // If the first node at index 0 should be removed
            // position node ptr at list-first and tell the list that the preious index=1 node is no first
            // If the list first is not NULL the prev of list first is now NULL
            // Now free the old node
            // if the first node happens to be NULL, no node left in list, last is also NULL
        // If the last element should be removed
            // node at last element, the new last is now at node->prev
            // If the last Node is not NULL the new next of last is NULL (end)
            // Now free the old node
            // If the new last is NULL -> first is also NULL -> List empty
        // If a "middle"-node should be removed
            // Go to first index at 0, count up till index-1 is reached
            // tmp is the node to be removed, node is the previous one
            // node->next = tmp->next; -> skip tmp as next node
            // node->next->prev = tmp->prev; -> the predecesor of at tmp + 1 is the prev of tmp
            // Now free tmp
void listRemove(List* list, unsigned int index){

    if (list->first == NULL || list->last == NULL ||index >= listLength(*list)) {
        return;
    }

    ListNode* node;
    ListNode* tmp;

    if(index == 0) {
        node = list->first;
        list->first = node->next;
        if (list->first != NULL) {
            list->first->prev = NULL;
        }
        free(node); node = NULL;

        if(list->first == NULL){
            list->last = NULL;
        }

        return;
    }

    if(index == listLength(*list)-1) {
        node = list->last;
        list->last = node->prev;
        if (list->last != NULL) {
            list->last->next = NULL;
        }
        free(node); node = NULL;

        if(list->last == NULL){
            list->first = NULL;
        }

        return;
    }

    node = list->first;
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
        if (node->next == NULL) {
            return;
        }
    }
    tmp = node->next;
    node->next = tmp->next;
    node->next->prev = tmp->prev;
    free(tmp); tmp = NULL;
    return;
}

// Function printList(List list)
    // Print out the list from first to last
            // Start with index 0 until last index (listLength-1 is reached)
            // In every index-iteration read the value with listGet and print it
void printList(List list){
    for (int i = 0; i < listLength(list); i++) {
        int value;
        if (listGet(list, i, &value)){
            printf("%i, ", value);
        }
    }

    printf("\n");
}

// Function printReverseList(List list)
    // Prints list in reverse order
        // Start with the last index of the list (length -1) and iterate until the loop reaches index -1
        // Like printList(List list) read in and print out the value at the iteration index
void printReverseList(List list){
    for (int i = listLength(list) - 1; i > -1; i--) {
        // read elements from list
        int value;
        if (listGet(list, i, &value)){
            printf("%i, ", value);
        }
    }
    
    printf("\n");
}

// Function listLength(List list)
    // Gets the current length of a list
        // Point to the first list node and go through every next node until the pointer points to NULL (last element)
        // With every successful iteration count up len
unsigned int listLength(List list) {
    unsigned int len = 0;
    for (ListNode* i = list.first; i != NULL; i = i->next) {
        len++;
    }
    return len;
}