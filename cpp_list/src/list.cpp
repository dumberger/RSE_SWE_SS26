#include "../include/list.hpp"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h> 
#include <stdbool.h>


List::List() {
    first = nullptr;
    last = nullptr;
}

bool List::get(unsigned int index, int& out_value) { 
    ListNode* node = first;
    if (node == nullptr) return false; // handle empty list case

    for (unsigned int i = 0; i < index; i++) {
        if (node == nullptr) {
            // handle out of bounds access, for example by returning a default value or printing an error message
            return false; // or some other error code
        }
        node = node->next;
    }
    out_value = node->value;
    return true;
}

// all the parameters are just copies and not references 
// so we need to use pointers to modify the original value

void List::pushBack(int value){ 
    // before in c we had to pass the list as a pointer, but now we can just use the class and its members directly
    // is like metod of this exact class, so we can access the members directly without needing to pass the list as a parameter

    ListNode* new_node = new ListNode; 
    if(new_node == nullptr) exit(1); 

    new_node->value = value; // new node is freshly created is not part of the list, so it need a pointer to the value
    new_node->next = nullptr; // the end of the list is always nullptr
    new_node->prev = last; // last node belongs to the list which we know, so no need to adress it with a pointer

    if (last != nullptr){ // if the list is not empty, we need to update the next pointer of the last node to point to the new node
        last->next = new_node;
    }
    else {
        first = new_node;
    }

    last = new_node; // updating
}


void List::_delete(){
    while (length() > 0) {
        remove(0);
    }
}

void List::remove(unsigned int index){
    if (first == nullptr) return; 

    ListNode* target = first; // list->first is actually just a var (or value), not the address of the first node

    // target is just a pointer used to navigate the existing nodes and safely re-link them
    // is used only for navigation and is not a specific value/node like the list itself.

    for (unsigned int i = 0; i < index; i++) { 
        if (target == nullptr) return;
        target = target->next; // *target.next is the same as target->next
    }

    if (target == nullptr) return;

    if (target->prev != nullptr) {
        target->prev->next = target->next;
    }
    else {
        first = target->next; // no need to list->first because we are already inside the class via List:: and can access the members directly
    }

    if (target->next != nullptr) {
        target->next->prev = target->prev;
    }
    else {
        last = target->prev;
    }

    delete(target); target = nullptr;
    return;
}

void List::print() {
    printf("\n\n");
    for (unsigned int i = 0; i < length(); i++) {
        int value;
        // read elements from list

        if (i == length() - 1 && get(i, value)) {
            printf("%i", value);
            break;
        }
        else if (get(i, value)) {
            printf("%i, ", value);
        } else {
        printf("Error reading value at index %i\n", i);
        }
    }
    printf("\n\n");
    return;

}

void List::printReverse() {
    printf("\n\n");
    unsigned int len = length();
    if (len == 0) return;
    for (unsigned int i = len - 1; ; i--) {
        int value;
        // read elements from list
        
        if (i == 0 && get(i, value)) {
            printf("%i ", value);
            break;
        }
        else if (get(i, value)) {
            printf("%i, ", value);
        } else {
            printf("Error reading value at index %u\n", i);
        }
    }
    printf("\n\n");
    return;
}

unsigned int List::length(){
    unsigned int length = 0;
    for (ListNode* i = first; i != nullptr; i = i->next) {
        length++;
    }
    return length;
}

List::~List(){
// is for now empty, but can be used later

}