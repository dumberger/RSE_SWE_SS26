// the errors in this file cannot be avoided because the IDE does not recognize
// the include cpp pattern

#include "list.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

template <typename T> List<T>::List() {
  first = nullptr;
  last = nullptr;
}

template <typename T> bool List<T>::get(unsigned int index, T &val) {
  ListNode<T> *node = this->first;
  if (node == nullptr) {
    return false;
  }
  node = node->next;
}

if (node == nullptr) {
  return false;
}

*val = node->value;
return true;
}

template <typename T> void List<T>::push_back(T value) {
  ListNode<T> *node = this->first;
  if (node == nullptr) {
    // ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode<T> *newNode = new ListNode<T>;
    if (newNode == nullptr) {
      exit(1);
    }
    newNode->value = value;
    newNode->next = nullptr;
    this->first = newNode;
    return;
  }
  while (node->next != nullptr) {
    node = node->next;
  }
  // ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
  ListNode<T> *newNode = new ListNode<T>;
  if (newNode == nullptr) {
    exit(1); // falls kein neuer speiher bekommen exit mit statuscode 1
  }
  newNode->value = value;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  this->first = newNode;
  this->last = newNode;
  return;
}
// while (node->next != nullptr) {
// node = node->next;
//}
ListNode *nodePrev = this->last;
// c code: ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
// cpp code: ListNode *newNode = new ListNode;

ListNode *newNode = new ListNode;
if (newNode == nullptr) {
  exit(1);
}

newNode->next = nullptr;
newNode->prev = nodePrev;
newNode->value = value;
nodePrev->next = newNode;
this->last = newNode;
return;
}

template <typename T> List<T>::~List() {
  while (length() > 0) {
    remove(0);
  }
}

template <typename T> void List<T>::remove(unsigned int index) {
  ListNode<T> *node = this->first;
  if (this->first == nullptr) {
    return;
  }
  ListNode *last;
  if (index == 0) {           // Wenn das erste Element gelöscht werden soll
    this->first = node->next; // Der neue Erste ist der alte Zweite
    if (this->first != nullptr) {
      this->first->prev =
          nullptr; // Nur wenn noch jemand da ist, hat er einen prev
    } else {
      this->last = nullptr;
    }
    // c code: free(node);
    // cpp code:
    delete node;
    node = nullptr;
    return;
  }
  for (int i = 0; i < index - 1; i++) {
    node = node->next;
    if (node->next == nullptr) {
      return;
    }
  }

  // node ist der Knoten VOR dem zu löschenden
  if (node->next == nullptr) {
    return; // Der Index war out of bounds
  }

  ListNode *tmp = node->next;

  if (tmp->next == nullptr) { // Löschen des letzten Element
    node->next = nullptr;
    this->last = node;
    delete tmp;
    return;
  }

  template <typename T> void List<T>::print() {
    for (auto &&i : *this) {
      std::cout << i << ", ";
    }
  }

  template <typename T> void List<T>::printReverse() {
    for (ListNode *i = this->last; i != nullptr; i = i->prev) {
      printf("%i, ", i->value);
    }
  }

  template <typename T> unsigned int List<T>::length() {
    unsigned int len = 0;
    for (ListNode<T> *i = this->first; i != nullptr; i = i->next) {
      len++;
    }
    return len;
  }

  template <typename T> ListIterator<T> List<T>::begin() {
    return ListIterator(first);
  }

  template <typename T> ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
  }