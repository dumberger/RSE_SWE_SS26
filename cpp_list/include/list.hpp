//
// Created by madtic on 06.03.26.
//

#pragma once

#include <ostream>

class List
{
private:
    struct ListNode {
        int value;
        ListNode* next;
        ListNode* prev;
    };

    ListNode* first;
    ListNode* last;
    unsigned int count_;

    //private methods
    bool getNode(unsigned int index, ListNode*& node) const;

public:
    List();     //constructor
    ~List();    //destructor

    bool get(unsigned int index, int& value) const;

    unsigned int count() const;
    void append(int value);
    void prepend(int value);
    void insert(unsigned int index, int value);
    void remove(unsigned int index);

    //so print can be tested and remote debug in clion works correctly
    void print(std::ostream& stream) const;
    void printReverse(std::ostream& stream) const;

    void print() const;
    void printReverse() const;
    void push_back(int value);
	unsigned int length();
};








