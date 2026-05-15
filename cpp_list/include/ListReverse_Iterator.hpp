#pragma once

#include "ListNode.hpp"
template<typename T>
class ListReverse_Iterator {
public:
    ListReverse_Iterator(ListNode<T>* node) : _node(node) {}
    T& operator*() { return _node->value; }
    ListReverse_Iterator operator++()  { _node = _node->prev; return *this;}
    bool operator!=(ListReverse_Iterator rhs) { return _node != rhs._node; }

private:
    ListNode<T> *_node;
};
