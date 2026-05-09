#pragma once

#include "ListIterator.hpp"
#include "ListNode.hpp"

template <typename T> class List {
private:
  ListNode<T> *first;
  ListNode<T> *last;

public:
  List();
  ~List();

  bool get(unsigned int index, T &val);
  void push_back(T value);
  void remove(unsigned int index);
  void print();
  unsigned int length();
  void printReverse();

  ListIterator<T> begin();
  ListIterator<T> end();
};

// not a good design but it woks fo templating the List afterwards
// do not use this in production code
#include "../src/list.cpp"