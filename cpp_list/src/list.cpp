#include "list.hpp"
#include "ListNode.hpp"
#include <stdlib.h>
#include <cstdio>

template <typename T>
List<T>::List() {
    first = nullptr; 
    last = nullptr; 
}

template <typename T>
bool List<T>::get(unsigned int index, T& val) {

    if(index >= length() || this->first == nullptr) {
        return false;
    }

    ListNode<T>* node;

    // Richtung wählen (wie bei remove
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

template <typename T>
void List<T>::push_back(T value) { 

    ListNode<T>* newNode = new ListNode<T>;

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

template <typename T>
List<T>::~List() {

    ListNode<T>* node = this->first;
    ListNode<T>* tmp;

    while(node != nullptr){
        tmp = node->next;
        delete node;
        node = tmp;
    }
    first = nullptr;
    last = nullptr;

}


template <typename T>
void List<T>::remove(unsigned int index){
    
    if(index >= length()) {
        return;
    }

    ListNode<T>* node; 

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

template <typename T>
void List<T>::print(){
    //HOMEWORK
    for(auto i= begin(); i != end(); ++i) {
        printf(" %i,", *i);
    }
    printf("\n");

}

template <typename T>
void List<T>::reverse_print() {
    //HOMEWORK
    for(auto i = ListIterator<T>(last); i != end(); --i) {
        printf(" %i,", *i);
    }
    printf("\n");
}   

template <typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    for (auto i = begin(); i != end(); ++i) {
        len++;
    }
    return len;
}

template <typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator<T>(first);
}

template <typename T>
ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
}
