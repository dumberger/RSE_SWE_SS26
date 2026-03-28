#pragma once

#include "ListNode.hpp"
#include "ListIterator.hpp"
#include "ListReverse_Iterator.hpp"

class List 
{
private:
    ListNode* first;
    ListNode* last;
    unsigned int count_;
public:
    List();     //constructor
    ~List();    //destructor

    bool get(unsigned int index, int& value) const;
    bool getNode(unsigned int index, ListNode*& node) const;

    unsigned int count() const;
    void append(int value);
    void prepend(int value);
    void insert(unsigned int index, int value);

    //so print can be tested and remote debug in clion works correctly
    void print(std::ostream& stream) const;
    void printReverse(std::ostream& stream) const;

    void push_back(int value);
    void remove(unsigned int index);
    void print() const;
    void printReverse() const;
    unsigned int length();

    ListIterator begin();
    ListIterator end();

    ListReverse_Iterator rbegin();
    ListReverse_Iterator rend();
};
