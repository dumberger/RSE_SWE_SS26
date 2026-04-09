#pragma once

#include "ListNode.hpp"
#include "ListIterator.hpp"

template<typename T>
class List 
{
private:
    ListNode<T>* first;
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
