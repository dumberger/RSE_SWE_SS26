#pragma once

#include <ostream>
#include "ListNode.hpp"
#include "ListIterator.hpp"
#include "ListReverse_Iterator.hpp"

template<typename T>
class List
{
private:
    ListNode<T>* first;
    ListNode<T> *last;
    unsigned int count_;
public:
    List();//constructor
    ~List(); //destructor

    bool get(unsigned int index, T& val) const;
    bool getNode(unsigned int index, ListNode<T> *&node) const;
    unsigned int count() const;
    void push_front(T value);
    void push_back(T value);
    void insert(unsigned int index, T& value);
    void remove(unsigned int index);
    //so print can be tested and remote debug in clion works correctly
    void printToStream(std::ostream &stream) const;
    void printReverseToStream(std::ostream &stream) const;
    void print() const;
    void printReverse() const;
    unsigned int length();

    ListIterator<T> begin();
    ListIterator<T> end();
    ListReverse_Iterator<T> rbegin();
    ListReverse_Iterator<T> rend();
};

// not a good design but it woks fo templating the List afterwards
// do not use this in production code
#include "../src/list.cpp"