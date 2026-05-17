// the errors in this file cannot be avoided because the IDE does not recognize the include cpp pattern

#include <stdlib.h>
#include <iostream>

template<typename T>
List<T>::List() {
    first = nullptr;
}

template<typename T>
bool List<T>::get(unsigned int index, T& val) {
    ListNode<T>* node = this->first;
    if (node == nullptr) {
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
        return;
    }
    while(node->next != nullptr) {
        node = node->next;
    }
    //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode<T>* newNode = new ListNode<T>; // new throws std::bad_alloc, no need to check pointer
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
    first = nullptr;
    last = nullptr;

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
