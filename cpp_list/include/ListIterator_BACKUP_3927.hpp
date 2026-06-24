#pragma once

#include "ListNode.hpp"

template<typename T>
class ListIterator
{
public:
    ListIterator(ListNode<T>* node) : _node(node) {}
    T& operator*() { return _node->value; }
<<<<<<< HEAD
    ListIterator& operator++() {
        _node = _node->next;
        return *this;
    }
    bool operator!=(const ListIterator& rhs) const { return _node != rhs._node; }
=======
    ListIterator& operator++()  { _node = _node->next; return *this;}
    bool operator!=(ListIterator rhs) { return _node != rhs._node; }
>>>>>>> lecture
private:
    ListNode<T>* _node;
};
