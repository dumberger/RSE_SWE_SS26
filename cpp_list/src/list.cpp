#include "list.hpp"
#include "ListIterator.hpp"
#include "stdio.h"
#include <cstdio>
#include <stdlib.h>

List::List() {
    first = nullptr; 
    last = nullptr; 
}

bool List::get(unsigned int index, int& val) {

    if(index >= length()|| index < 0 || this->first == nullptr) {
        return false;
    }
    ListNode* node;

    // 🔍 Richtung wählen (wie bei remove
    if(index < length() / 2) {
        node = this->first;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = this->last;
        for (int i = length() - 1; i > index; i--) {
            node = node->prev;
        }
    }
    val = node->value;
    return true;

}

void List::push_back(int value) {
    ListNode* newNode = new ListNode;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = this->last;

    if (this->first == nullptr) {
        this->first = newNode;
        this->last = newNode;
        return;
    }

    this->last->next = newNode;
    this->last = newNode;
}

List::~List() {
    while (first != nullptr) {
        ListNode* tmp = first;
        first = first->next;
        delete tmp;
    }
    last = nullptr;
}


void List::remove(unsigned int index){
    
    if(index >= length()) {
        return;
    }


    ListNode* node; 
    // 🔍 Richtung wählen (wie bei get)

    if(index < length() / 2) {
        node = this->first;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = this->last;
        for (int i = length() - 1; i > index; i--) {
            node = node->prev;
        }
    }

    // Verbindung anpassen
    if(node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        this->first = node->next;
}

    if(node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        this->last = node->prev;
    }

    delete node;
}

void List::print(){
    //HOMEWORK
    for(auto i= begin(); i != end(); ++i) {
        printf(" %i,", *i);
    }
    printf("\n");

}

void List::reverse_print() {
    //HOMEWORK
   
    for(auto i = ListIterator(last); i != end(); --i) {
        printf(" %i,", *i);
    }
    printf("\n");
}   

unsigned int List::length() {
    unsigned int len = 0;
    for (auto i = begin(); i != end(); ++i) {
        len++;
    }
    return len;
}

ListIterator List::begin() {
    return ListIterator(first);
}

ListIterator List::end() {
    return ListIterator(nullptr);
}