#include "ListIterator.hpp"

template<typename T>
ListIterator<T>::ListIterator(ListNode<T>* node) : _node(node) {};

template<typename T>
T& ListIterator<T>::operator*() {
    return _node->value;
};

template<typename T>
ListIterator<T> ListIterator<T>::operator++() {
    _node = _node->next;
    return *this;
};

template<typename T>
ListIterator<T> ListIterator<T>::operator--() {
    _node = _node->prev;
    return *this;
};

template<typename T>
bool ListIterator<T>::operator!=(ListIterator<T> rhs) {
    // gleiches Element = gleicher Pointer
    return _node != rhs._node;
};