#include "ListIterator.hpp"

ListIterator::ListIterator(ListNode* node) : _node(node) {}

int& ListIterator::operator*(){
    return _node->value;
}

ListIterator& ListIterator::operator++(){
    _node = _node->next;
    return *this;
}

ListIterator& ListIterator::operator--(){
    _node = _node->prev;
    return *this;
}

bool ListIterator::operator!=(ListIterator rhs){
    return _node != rhs._node;
}
