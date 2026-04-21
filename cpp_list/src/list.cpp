// the errors in this file cannot be avoided because the IDE does not recognize the include cpp pattern

#include "list.hpp"
#include <stdlib.h>
#include <iostream>

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
    val = node->value;
    return true;
}

template<typename T>
void List<T>::push_back(T value) {
    ListNode<T>* node = this->first;
    if (node == nullptr) {
        //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        ListNode<T>* newNode = new ListNode<T>; // new throws std::bad_alloc, no need to check pointer
        newNode->value = value;
        newNode->next = nullptr;
        this->first = newNode;
        this->last = newNode;
        newNode->prev = nullptr;
        return;
    }
    // while(node->next != nullptr) {
    //     node = node->next;
    // }
    //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode<T>* newNode = new ListNode<T>; // new throws std::bad_alloc, no need to check pointer
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = this->last;
    last->next = newNode;
    this->last = newNode;

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
    if(index == 0) { // das erste Element soll gelöscht werden
        this->first = node->next;
        if(this->first != nullptr){
            this->first->prev = nullptr;
        }
        else{
            this->last = nullptr;
        }
        //free(node); node = NULL;
        delete node; node = nullptr;
        return;
    }
    if(node->next == nullptr){ //die Liste hat nur einen Eintrag aber es wird nicht versucht das erste Elemement zu löschen
        return;
    }
    for (int i = 0; i < index - 1; i++) {//ich gehe die Liste bis zum Knoten vor dem der gelöscht werden soll durch
        node = node->next;
        if (node->next == nullptr){ // ich checke hier schon den Fall ob ich auf der letzten Node bin und muss das dementsprechend später nicht mehr machen.
        return;
    }
    }
    if (node->next->next == nullptr){ // wenn dieser Pointer der nullptr sein sollte, befinden wir uns auf dem vorletzten Knoten und ich möchten den letzten Knoten löschen.
        this->last = node;
        node->next = nullptr;
        return;
    }
    // das ist nur mehr der Fall, wenn die Liste mehr als einen Eintrag hat und weder das erste noch das letzte Element gelöscht werden soll
    tmp = node->next;
    node->next = tmp->next;
    node->next->prev = node; // node->next = node->next->next bevor ich tmp = node->next gesetzt habe, wird also schon in der vorherigen if-Bedinung überprüft
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
void List<T>::print_reverse() {
    for (ListNode<T>* node = this->last; node != nullptr, node = node->prev) {
        std::cout << node->value<< ",";
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