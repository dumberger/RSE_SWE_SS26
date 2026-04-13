// the errors in this file cannot be avoided because the IDE does not recognize the include cpp pattern

#include "list.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
}

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

    if (node == nullptr) { //Verbesserung nach get_false_index
        return false;
    }

    val = node->value;
    return true;
}

template<typename T>
void List<T>::push_back(T value) {
    ListNode<T>* newNode = new ListNode<T>;

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
    */
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
    } else {
    this->last = node;
    }
    delete tmp; tmp = nullptr;
    return;
}
template<typename T>

void List<T>::print(){
    //HOMEWORK
    ListNode<T>* node = this->first;
    while (node != nullptr) {
        std::cout << node->value << "\n";
        node = node->next;
    }
}

template<typename T>
void List<T>::print_reverse() {
    ListNode<T>* node = this->last;
    while (node != nullptr) {
        std::cout << node->value << "\n";
        //printf("%d, ", node->value);
        //printf("%d\n", node->value);
        node = node->prev;
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
    return ListIterator<T>(first);
}

template<typename T>
ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
}