#pragma once //preprozessor sagen, dass Datei nur 1x benötigt wird

#include "ListIterator.hpp"
#include "ListNode.hpp"

template<typename T>
class List 
{
private:
    // struct ListNode {
    //     int value;
    //     struct ListNode* next;
    //     struct ListNode* prev;
    // };

    ListNode<T>* first;
    ListNode<T>* last;

public:
    List();
    ~List();

    ListIterator<T> begin();
    ListIterator<T> end();

    bool get(unsigned int index, T& val);
    void push_back(T value);
    void remove(unsigned int index);
    void print();
    void print_reverse();
    unsigned int length();

};

#include "list.cpp"

