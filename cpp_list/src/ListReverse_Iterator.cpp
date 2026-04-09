#include "../include/ListReverse_Iterator.hpp"

ListReverse_Iterator::ListReverse_Iterator(ListNode *node) : _node(node) {
}

int &ListReverse_Iterator::operator*() {
    return _node->value;
}

ListReverse_Iterator ListReverse_Iterator::operator++() {
    _node = _node->prev;
    return *this;
}

bool ListReverse_Iterator::operator!=(ListReverse_Iterator rhs) {
    return _node != rhs._node;
}
