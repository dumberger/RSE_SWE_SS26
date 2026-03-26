#include <stdio.h>
#include <stdlib.h>
#include "../include/list.hpp"

List::List() {
    first = nullptr;
    last = nullptr;

}

void List::push_back(int value) {
    //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newNode = new ListNode; // C++ style memory allocation 
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = this->last;

    if (this->last != nullptr) {
        this->last->next = newNode;
    }
    this->last = newNode;

    if (this->first == nullptr) {
        this->first = newNode;
    }
}

unsigned int List::length() {
    unsigned int length = 0;
    ListNode* current = this->first;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

bool List::get(unsigned int index, int& val) {
    ListNode* current = this->first;
    unsigned int currentIndex = 0;

    while (current != nullptr) {
        if (currentIndex == index) {
            val = current->value;
            return true;
        }
        current = current->next;
        currentIndex++;
    }
    return false; /* Index out of bounds */
}

void List::remove(unsigned int index) {
    ListNode* current = this->first;
    unsigned int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    if (current == nullptr) {
        return; /* Index out of bounds */
    }
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        this->first = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        this->last = current->prev;
    }
        //free(current);
        delete current; current = nullptr; // C++ style memory deallocation
}

void List::print() {
    ListNode* current = this->first;
    while (current != nullptr) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void List::print_reverse() {
    ListNode* current = this->last;
    while (current != nullptr) {
        printf("%d ", current->value);
        current = current->prev;
    }
    printf("\n");
}

List::~List() {
    ListNode* current = this->first;
    ListNode* next;
    while (current != nullptr) {
        next = current->next;
        //free(current);
        delete current; current = nullptr; // C++ style memory deallocation
        current = next;
    }
    this->first = nullptr;
    this->last = nullptr;
}

