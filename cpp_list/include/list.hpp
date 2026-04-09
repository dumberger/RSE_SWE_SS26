#pragma once
#include "ListIterator.hpp"

class List 
{
private:
    ListNode* first;
public:
    List();
    ~List();

    bool get(unsigned int index, int& val);
    void push_back(int value);
    void remove(unsigned int index);
    void print();
    unsigned int length();

    ListIterator begin();
    ListIterator end();
};