#pragma once //preprozessor sagen, dass Datei nur 1x benötigt wird

#include "ListIterator.hpp"
#include "ListNode.hpp"

template<typename T>
class List{
public:
    List();
    ~List();

    bool get( unsigned int index, T& val);
    void push_back(T value);
    void remove(unsigned int index);
    void print();
    unsigned int length();
    void print_reverse();

    ListIterator<T> begin();
    ListIterator<T> end();
private:
    ListNode<T>* first;
    ListNode<T>* last;
};
