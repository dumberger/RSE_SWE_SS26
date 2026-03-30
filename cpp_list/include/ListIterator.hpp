#pragma once

#include "ListNode.hpp"

class ListIterator{
public:
ListIterator(ListNode* node);
    int& operator*();
    // According to cpp-reference https://en.cppreference.com/w/cpp/language/operators.html
    // increment and decrement operator must return reference instead of copy
    ListIterator& operator++();
    ListIterator& operator--();
    bool operator!=(ListIterator rhs);

private:
    ListNode* _node;
};

