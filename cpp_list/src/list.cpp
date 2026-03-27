#include "list.hpp"
#include <stdlib.h>
#include <stdio.h>

List::List() {
    first = nullptr;
    last = nullptr;
}

bool List::get(unsigned int index, int& val) {
    ListNode* node = first;
    if(node == nullptr){
        return false;
    }
    for (int i = 0; i < index; i++) {
        if (node == nullptr) {
            return false;
        }
        node = node->next;
    }
    val = node->value;
    return true;
}

void List::push_back(int value) {
    ListNode* node = first;
    if (node == nullptr) {
        ListNode* newNode = new ListNode;
        if (newNode == nullptr) {
            exit(1);
        }
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        first = newNode;
        last = newNode;
        return;
    }
    node = last;
    ListNode* newNode = new ListNode;
    if (newNode == nullptr) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = nullptr;
    node->next = newNode;
    newNode->prev = node;
    last = newNode;
    return;
}

List::~List() {
    while(length() > 0) {
        remove(0);
    }
}

void List::remove(unsigned int index){
    ListNode* node = first;
    if (first == nullptr) {
        return;
    }
    ListNode* tmp;
    if(index == 0) {
        first = node->next;
        if(first != nullptr)
            first->prev = nullptr;
        else{
            last = nullptr;
        }
        delete node; node = nullptr;
        return;
    }
    else if (index == length() - 1) {
        node = last;
        last = node->prev;
        node->prev->next = nullptr;
        delete node; node = nullptr;
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
        if (node->next == nullptr) {
            return;
        }
    }
    tmp = node->next;
    node->next = tmp->next;
    tmp->next->prev = node;
    delete tmp; tmp = nullptr;
    return;
}

int List::print(){
    ListNode* curr = first;
    if(curr == nullptr){
        return 0;
    }
    if(curr->next == nullptr){
        printf("%i\n", curr->value);
        return 1;
    }
    int i = 0;
    while(curr != nullptr){
        printf("%i ", curr->value);
        i++;
        curr = curr->next;
    }
    return i;
}

int List::print(int* array){
    ListNode* curr = first;
    if(curr == nullptr){
        return 0;
    }
    if(curr->next == nullptr){
        printf("%i\n", curr->value);
        array[0] = curr->value;
        return 1;
    }
    int i;
    for(i = 0; i < length(); i++){
        printf("%i ", curr->value);
        array[i] = curr->value;
        curr = curr->next;
    }  
    return i;
}

int List::printReversed(){
        ListNode* curr = last;
    if(curr == nullptr){
        return 0;
    }
    if(curr->prev == nullptr){
        printf("%i\n", curr->value);
        return 1;
    }
    int i = 0;
    while(curr != nullptr){
        printf("%i ", curr->value);
        i++;
        curr = curr->prev;
    }
    return i;
}

int List::printReversed(int* array){
        ListNode* curr = last;
    if(curr == nullptr){
        return 0;
    }
    if(curr->prev == nullptr){
        printf("%i\n", curr->value);
        array[0] = curr->value;
        return 1;
    }
    int i;
    for(i = 0; i < length(); i++){
        printf("%i ", curr->value);
        array[i] = curr->value;
        curr = curr->prev;
    }
    return i;
}

unsigned int List::length() {
    unsigned int len = 0;
    for (ListNode* i = first; i != nullptr; i = i->next) {
        len++;
    }
    return len;
}