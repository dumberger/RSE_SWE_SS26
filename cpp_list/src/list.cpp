// the errors in this file cannot be avoided because the IDE does not recognize the include cpp pattern

#include "list.hpp"
#include <stdlib.h>
#include <iostream>


template<typename T>
List<T>::List() {
    first = nullptr;
}

//For Saef


template<typename T>
bool List<T>::get(unsigned int index, T& val) {
    ListNode<T>* node = this->first;
    if (node == nullptr) {
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

template<typename T>
void List<T>::push_back(T value) {
    ListNode<T>* node = this->first;
    if (node == nullptr) {
        //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        ListNode<T>* newNode = new ListNode<T>;
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
    ListNode<T>* newNode = new ListNode<T>;
    if (newNode == nullptr) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = nullptr;
    node->next = newNode;
    return;
}

template<typename T>
List<T>::~List() {
    while(length() > 0) {
        remove(0);
    }
}

template<typename T>
void List<T>::remove(unsigned int index){
    ListNode<T>* node = this->first;
    if (this->first == nullptr) {
        return;
    }
    ListNode<T>* tmp;
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

template<typename T>
void List<T>::print() {
    for (auto &&i : *this) {
        std::cout << i << ", ";
    }
    
}

template<typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    for (ListNode<T>* i = this->first; i != nullptr; i = i->next) {
        len++;
    }
    return len;
}

template<typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator(first);
}

template<typename T>
ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
}