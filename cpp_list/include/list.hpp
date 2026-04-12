#pragma once
#include "ListIterator.hpp"
#include "ListNode.hpp"

template<typename T>
class List
{
public:
    List();
    ~List();
    bool get(unsigned int index, int &val);
    void push_back(int value);
    void remove(unsigned int index);
    unsigned int length();
    void print();
    void print_reverse();

    ListIterator<T> begin();
    ListIterator<T> end();
private:
    ListNode* first;
    ListNode* last;
};
