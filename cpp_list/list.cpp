#include "list.hpp"
#include <stdlib.h>

List::List() {
    first = nullptr;
}

bool List::get(unsigned int index, int& val) {
    ListNode* node = this->first;
    for (int i = 0; i < index; i++) {
        if (node == nullptr) {
            return false;
        }
        node = node->next;
    }
    val = node->value;
    return true;
}
//test

void List::push_back(int value) {
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
    //free(tmp); tmp = NULL;
    delete tmp; tmp = nullptr;
    return;
}

void List::print(){
    //HOMEWORK
}

unsigned int List::length() {
    unsigned int len = 0;
    for (ListNode* i = this->first; i != nullptr; i = i->next) {
        len++;
    }
    return len;
}