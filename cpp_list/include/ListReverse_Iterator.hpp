#pragma once

#include "ListNode.hpp"

class ListReverse_Iterator {
public:
    ListReverse_Iterator(ListNode* node);
    int& operator*();
    ListReverse_Iterator operator++();
    bool operator!=(ListReverse_Iterator rhs);
private:
    ListNode* _node;
};
