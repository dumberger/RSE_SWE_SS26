#include "../include/ListIterator.hpp"

ListIterator::ListIterator(ListNode* node): _node(node){};

int& ListIterator::operator*(){
    return _node -> value;
}

ListIterator ListIterator::operator++(){
    _node = _node ->next;
    return  *this;
}

// bool ListIterator::operator==(ListIterator rhs){
//     return _node == rhs._node;
// }


bool ListIterator::operator!=(ListIterator rhs){
    return _node != rhs._node;
}


