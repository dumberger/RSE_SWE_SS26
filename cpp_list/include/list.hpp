#pragma once

#include <ostream>
#include "ListNode.hpp"
#include "ListIterator.hpp"
#include "ListReverse_Iterator.hpp"

class List {
private:
    ListNode *first;
    ListNode *last;
    unsigned int count_;

public:
    List(); //constructor
    ~List(); //destructor

    bool get(unsigned int index, int &value) const;
    bool getNode(unsigned int index, ListNode *&node) const;
    unsigned int count() const;
    void push_front(int value);
    void push_back(int value);
    void insert(unsigned int index, int value);
    void remove(unsigned int index);

    //so print can be tested and remote debug in clion works correctly
    void printToStream(std::ostream &stream) const;
    void printReverseToStream(std::ostream &stream) const;
    void print() const;
    void printReverse() const;
    unsigned int length();

    ListIterator begin();
    ListIterator end();
    ListReverse_Iterator rbegin();
    ListReverse_Iterator rend();
};
