//
// Created by madtic on 06.03.26.
//

#pragma once


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

public:
    List();     //constructor
    ~List();    //destructor

    bool get(unsigned int index, int& value) const;
    bool getNode(unsigned int index, ListNode*& node) const;
    unsigned int count() const;
    void append(int value);
    void prepend(int value);
    void insert(unsigned int index, int value);
    void remove(unsigned int index);
    void print() const;
    void printReverse() const;

    void push_back(int value);
	unsigned int length();
};








