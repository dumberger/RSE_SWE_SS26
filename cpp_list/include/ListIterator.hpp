#pragma once
#include "ListNode.hpp"

class ListIterator {

public:
    ListIterator(ListNode* node);
    int& operator*();
    ListIterator operator++(); 
    bool operator!=(ListIterator rhs); // if (i == j)

private:
    ListNode* _node;
};

/* das soll ein iterator können: 
ListIterator p_int;
auto test = *p_int;

ListIterator i;
auto test = ++i;

if (i == j)
*/