#pragma once

#include "ListNode.hpp"
#include "ListIterator.hpp"


template<typename T>
struct ListNode {
    T value;
    ListNode<T>* next;
    ListNode<T>* prev;
};

template<typename T>
class ListIterator {
private:
    ListNode<T>* current;

public:
    explicit ListIterator(ListNode<T>* node);

    T& operator*();
    ListIterator& operator++();
    bool operator!=(const ListIterator& other) const;
};

template<typename T>
class List 
{
private:
    ListNode<T>* first;
    ListNode<T>* last;
public:
    List();
    ~List();

    bool get(unsigned int index, T& val);
    void push_back(T value);
    bool get(unsigned int index, T& val);
    void push_back(T value);
    void remove(unsigned int index);
    void print();
    unsigned int length();

    ListIterator<T> begin();
    ListIterator<T> end();
};

// not a good design but it works for templating the List afterwards
// do not use this in production code
#ifndef LIST_TEMPLATES_SOURCE
#include "../src/list.cpp"
#endif
