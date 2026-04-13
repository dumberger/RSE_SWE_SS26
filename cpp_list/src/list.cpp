#include "list.hpp"
#include <stdlib.h>
#include <stdio.h>

List::List() {
    first = nullptr;
    last = nullptr;
}

bool List::get(unsigned int index, int& val) {
    ListNode* node = this->first;
    if (node == nullptr) {
        return false;
    }
    for (int i = 0; i < index; i++) {
        if (node == nullptr) {
            return false;
        }
        node = node->next;
    }

    if (node == nullptr) { //Verbesserung nach get_false_index
        return false;
    }

    val = node->value;
    return true;
}

void List::push_back(int value) {
    ListNode* newNode = new ListNode;

    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = last;

    if (first == nullptr) {
        first = newNode;
        last = newNode;
        return;
    }

    last->next = newNode;
    last = newNode;

    /*
    ListNode* node = this->first;
    if (node == nullptr) {
        //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        ListNode* newNode = new ListNode;
        if (newNode == nullptr) {
            exit(1);
        }
        newNode->value = value;
        newNode->next = nullptr;
        this->first = newNode;
        return;
    }
    while(node->next != nullptr) {
        node = node->next;
    }
    //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newNode = new ListNode;
    if (newNode == nullptr) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = nullptr;
    node->next = newNode;
    return;
    */
}

List::~List() {
    while(length() > 0) {
        remove(0);
    }
}

void List::remove(unsigned int index){
    ListNode* node = this->first;
    if (this->first == nullptr) {
        return;
    }
    ListNode* tmp;
    if(index == 0) {
        this->first = node->next;
        //free(node); node = NULL;
        if (this->first != nullptr) {
            this->first->prev = nullptr;
        } else {
            this->last = nullptr;
        }
        delete node; node = nullptr;
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        if (node->next == nullptr) {
            return;
        }
        node = node->next;
    }
    tmp = node->next;
    if (tmp == nullptr) {
        return;
    }
    node->next = tmp->next;
    //free(tmp); tmp = NULL;
    if(tmp->next != nullptr) {
        tmp->next->prev = node;
    }
    delete tmp; tmp = nullptr;
    return;
}

void List::print(){
    //HOMEWORK
    ListNode* node = this->first;
    while (node != nullptr) {
        printf("%d\n", node->value);
        node = node->next;
    }
}

void List::print_reverse() {
    ListNode* node = this->last;
    while(node != nullptr) {
        printf("%d, ", node->value);
        //printf("%d\n", node->value);
        node = node->prev;
    }
}

unsigned int List::length() {
    unsigned int len = 0;
    for (ListNode* i = this->first; i != nullptr; i = i->next) {
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