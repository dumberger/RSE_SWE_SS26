#pragma once
#include "ListIterator.hpp"
#include "ListNode.hpp"
#include <stdlib.h>
#include <stdio.h>

template<typename T>
class List 
{
private:
    // struct ListNode {
    //     T value;
    //     struct ListNode* next;
    //     struct ListNode* prev;
    // };
    
    ListNode<T>* first;
    ListNode<T>* last;

public:
    List();
    ~List();
    bool get(unsigned int index, T& val);
    void push_back(T value);
    void remove(unsigned int index);
    void print(); // returns how many items are written
    void print(T* array);
    void printReversed();
    void printReversed(T* array);
    unsigned int length();

    ListIterator<T> begin();
    ListIterator<T> end();
};

template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
}

template<typename T>
bool List<T>::get(unsigned int index, T& val) {
    ListNode<T>* node = first;
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

template<typename T>
void List<T>::push_back(T value) {
    ListNode<T>* node = first;
    if (node == nullptr) {
        ListNode<T>* newNode = new ListNode<T>;
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
    ListNode<T>* newNode = new ListNode<T>;
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

template<typename T>
List<T>::~List() {
    while(length() > 0) {
        remove(0);
    }
}

template<typename T>
void List<T>::remove(unsigned int index){
    ListNode<T>* node = first;
    if (first == nullptr) {
        return;
    }
    ListNode<T>* tmp;
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

template<typename T>
void List<T>::print(){
    ListNode<T>* curr = first;
    if(curr == nullptr){
        return;
    }
    if(curr->next == nullptr){
        printf("%i\n", curr->value);
        return;
    }
    while(curr != nullptr){
        printf("%i ", curr->value);
        curr = curr->next;
    }
    return;
}

template<typename T>
void List<T>::print(T* array){
    ListNode<T>* curr = first;
    if(curr == nullptr){
        return;
    }
    if(curr->next == nullptr){
        printf("%i\n", curr->value);
        array[0] = curr->value;
        return;
    }
    int i;
    for(i = 0; i < length(); i++){
        printf("%i ", curr->value);
        array[i] = curr->value;
        curr = curr->next;
    }  
    return;
}

template<typename T>
void List<T>::printReversed(){
        ListNode<T>* curr = last;
    if(curr == nullptr){
        return;
    }
    if(curr->prev == nullptr){
        printf("%i\n", curr->value);
        return;
    }
    while(curr != nullptr){
        printf("%i ", curr->value);
        curr = curr->prev;
    }
    return;
}

template<typename T>
void List<T>::printReversed(T* array){
        ListNode<T>* curr = last;
    if(curr == nullptr){
        return;
    }
    if(curr->prev == nullptr){
        printf("%i\n", curr->value);
        array[0] = curr->value;
        return;
    }
    int i;
    for(i = 0; i < length(); i++){
        printf("%i ", curr->value);
        array[i] = curr->value;
        curr = curr->prev;
    }
    return;
}

template<typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    for (ListNode<T>* i = first; i != nullptr; i = i->next) {
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
