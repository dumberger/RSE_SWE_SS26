#pragma once

#include "ListNode.hpp"

template<typename T>
class ListIterator
{
public:
    ListIterator(ListNode<T>* node);

    T& operator*();
    ListIterator operator++();
    ListIterator operator--();
    bool operator!=(ListIterator rhs);
private:
    ListNode<T>* _node;
};

