#pragma once

#include "ListNode.hpp"
#include "ListIterator.hpp"
#include <iostream>

template<typename T = int>
class List 
{
private:
    ListNode<T>* first;
    ListNode<T>* last;
    unsigned int size;
public:
    List();
    ~List();

    bool get(unsigned int index, T& val);
    void push_back(T value);
    void remove(unsigned int index);
    void print();
    unsigned int length();

    ListIterator<T> begin();
    ListIterator<T> end();
};

template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

template<typename T>
bool List<T>::get(unsigned int index, T& val) {
    if (index >= size) {
        return false;
    }

    ListNode<T>* node;
    if (index <= size / 2) {
        node = first;
        for (unsigned int i = 0; i < index; ++i) {
            node = node->next;
        }
    } else {
        node = last;
        for (unsigned int i = size - 1; i > index; --i) {
            node = node->prev;
        }
    }

    val = node->value;
    return true;
}

template<typename T>
void List<T>::push_back(T value) {
    ListNode<T>* newNode = new ListNode<T>;
    newNode->value = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (first == nullptr) {
        first = newNode;
        last = newNode;
    } else {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }

    ++size;
}

template<typename T>
List<T>::~List() {
    ListNode<T>* node = first;
    while (node != nullptr) {
        ListNode<T>* next = node->next;
        delete node;
        node = next;
    }

    first = nullptr;
    last = nullptr;
    size = 0;
}

template<typename T>
void List<T>::remove(unsigned int index){
    if (index >= size) {
        return;
    }

    ListNode<T>* node;
    if (index <= size / 2) {
        node = first;
        for (unsigned int i = 0; i < index; ++i) {
            node = node->next;
        }
    } else {
        node = last;
        for (unsigned int i = size - 1; i > index; --i) {
            node = node->prev;
        }
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        first = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        last = node->prev;
    }

    delete node;
    --size;
}

template<typename T>
void List<T>::print() {
    for (auto&& i : *this) {
        std::cout << i << ", ";
    }
}

template<typename T>
unsigned int List<T>::length() {
    return size;
}

template<typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator<T>(first);
}

template<typename T>
ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
}