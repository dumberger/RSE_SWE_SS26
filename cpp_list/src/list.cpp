// Intentionally included from include/list.hpp for template definitions.
#define LIST_TEMPLATES_SOURCE
#include "../include/list.hpp"
#include <iostream>

template<typename T>
ListIterator<T>::ListIterator(ListNode<T>* node) : current(node) {}

template<typename T>
T& ListIterator<T>::operator*() {
    return current->value;
}

template<typename T>
ListIterator<T>& ListIterator<T>::operator++() {
    if (current != nullptr) {
        current = current->next;
    }
    return *this;
}

template<typename T>
bool ListIterator<T>::operator!=(const ListIterator<T>& other) const {
    return current != other.current;
}

template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
}

template<typename T>
void List<T>::push_back(T value) {
    ListNode<T>* newNode = new ListNode<T>;
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

template<typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    ListNode<T>* current = this->first;
    while (current != nullptr) {
        len++;
        current = current->next;
    }
    return len;
}

template<typename T>
bool List<T>::get(unsigned int index, T& val) {
    ListNode<T>* current = this->first;
    unsigned int currentIndex = 0;

    while (current != nullptr) {
        if (currentIndex == index) {
            val = current->value;
            return true;
        }
        current = current->next;
        currentIndex++;
    }
    return false;
}

template<typename T>
void List<T>::remove(unsigned int index) {
    ListNode<T>* current = this->first;
    unsigned int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    if (current == nullptr) {
        return;
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

    delete current;
}

template<typename T>
void List<T>::print() {
    ListNode<T>* current = this->first;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template<typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator<T>(first);
}

template<typename T>
ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
}

template<typename T>
List<T>::~List() {
    ListNode<T>* current = this->first;
    ListNode<T>* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    this->first = nullptr;
    this->last = nullptr;
}

