#pragma once

#include "ListNode.hpp"

template<typename T>
class ListIterator
{
public:
    ListIterator(ListNode<T>* node) : _node(node) {}
    T& operator*() { return _node->value; }
    ListIterator operator++()  { _node = _node->next; return *this;}
    ListIterator operator--()  { _node = _node->prev; return *this;}
    bool operator!=(ListIterator rhs) { return _node != rhs._node; }

private:
    ListNode<T>* _node;
};