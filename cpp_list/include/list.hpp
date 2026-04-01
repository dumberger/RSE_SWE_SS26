#pragma once
#include "ListNode.hpp"
#include "ListIterator.hpp"

class List 
{
private:

    ListNode* first;
    ListNode* last; 

public:
    List();
    ~List();

    bool get(unsigned int index, int& val);
    void push_back(int value);
    void remove(unsigned int index);
    void print();
    unsigned int length();
    void reverse_print();

     ListIterator begin();
     ListIterator end();    

};