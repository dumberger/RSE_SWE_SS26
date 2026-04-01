#pragma once

#include "ListNode.hpp"

class ListIterator {
public:
  ListIterator(ListNode* node);
  int& operator*();
  ListIterator operator++();
  ListIterator& operator--();
  bool operator!=(ListIterator rhs);
  
private:
  ListNode* _node;
};