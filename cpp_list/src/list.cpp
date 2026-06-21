// the errors in this file cannot be avoided because the IDE does not recognize
// the include cpp pattern

#include <iostream>
#include <stdlib.h>
#pragma once

#include "../include/list.hpp"

template <typename T> List<T>::List() {
  first = nullptr;
  last = nullptr;
}

template <typename T> bool List<T>::get(unsigned int index, T &val) {
  ListNode<T> *node = this->first;
  if (node == nullptr) {
    return false;
  }

  for (unsigned int i = 0; i < index && node != nullptr; i++) {
    node = node->next;
  }

  if (node == nullptr) {
    return false;
  }

  val = node->value;
  return true;
}

template <typename T> void List<T>::push_back(T value) {
  ListNode<T> *newNode = new ListNode<T>;
  if (newNode == nullptr)
    exit(1);

  newNode->value = value;
  newNode->next = nullptr;
  newNode->prev = nullptr;

  if (this->first == nullptr) {
    // Liste ist leer
    this->first = newNode;
    this->last = newNode;
  } else {
    // Am Ende anfügen
    ListNode<T> *oldLast = this->last;
    oldLast->next = newNode;
    newNode->prev = oldLast;
    this->last = newNode;
  }
}

template <typename T> List<T>::~List() {
  while (length() > 0) {
    remove(0);
  }
}

template <typename T> void List<T>::remove(unsigned int index) {
  if (this->first == nullptr)
    return;

  ListNode<T> *node = this->first;

  // Fall 1: Erstes Element löschen
  if (index == 0) {
    this->first = node->next;
    if (this->first != nullptr) {
      this->first->prev = nullptr;
    } else {
      this->last = nullptr;
    }
    delete node;
    return;
  }

  // Fall 2: Navigiere zum Element am Index
  for (unsigned int i = 0; i < index && node != nullptr; i++) {
    node = node->next;
  }

  if (node == nullptr)
    return; // Out of bounds

  // Zeiger der Nachbarn umbiegen
  if (node->prev)
    node->prev->next = node->next;
  if (node->next)
    node->next->prev = node->prev;

  // Falls es das letzte war, 'last' aktualisieren
  if (node == this->last) {
    this->last = node->prev;
  }

  delete node;
}

template <typename T> void List<T>::print() {
  for (auto &&i : *this) {
    std::cout << i << ", ";
  }
}

template <typename T> void List<T>::printReverse() {
  for (ListNode<T> *i = this->last; i != nullptr; i = i->prev) {
    std::cout << i->value << ", ";
  }
  std::cout << std::endl;
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