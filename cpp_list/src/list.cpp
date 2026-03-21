#include "list.hpp"
#include <stdio.h>
#include <stdlib.h>

List::List() { // Klasse::Konstruktor
  first = nullptr;
  last = nullptr;
}

bool List::get(unsigned int index, int *val) { // Klasse::Methode
  ListNode *node = this->first;
  for (int i = 0; i < index; i++) {
    if (node == nullptr) {
      return false;
    }
    node = node->next;
  }
  *val = node->value;
  return true;
}

void List::push_back(int value) {
  ListNode *node = this->first;
  if (node == nullptr) { // wenn erster knoten einen nullpointer hat, dann ist
                         // liste leer und man erstellt neues node

    // ListNode *newNode =
    //(ListNode *)malloc(sizeof(ListNode)); // malloc reserviert speicher

    // c code: ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    // cpp code:
    ListNode *newNode = new ListNode;

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

List::~List() {
  while (length() > 0) {
    remove(0);
  }
}

void List::remove(unsigned int index) {
  ListNode *node = this->first;
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
  // Fehler behoben: tmp wird initialisiert, bevor es verwendet wird
  ListNode *tmp = node->next;

  if (tmp->next == nullptr) { // Wenn das letzte Element gelöscht werden soll
    node->next = nullptr;
    this->last = node;
    // c code: free(tmp);
    // cpp code:
    delete tmp;
    tmp = nullptr;
    return;
  }
  tmp = node->next;
  last = tmp->next;
  node->next = last;
  last->prev = node;
  // c code: free(tmp);
  // cpp code:
  delete tmp;
  tmp = nullptr;
  return;
}

unsigned int List::length() {
  unsigned int len = 0;
  for (ListNode *i = this->first; i != nullptr; i = i->next) {
    len++;
  }
  return len;
}

void List::print() {
  for (ListNode *i = this->first; i != nullptr; i = i->next) {
    printf("%i, ", i->value);
  }
}

void List::printReverse() {
  for (ListNode *i = this->last; i != nullptr; i = i->prev) {
    printf("%i, ", i->value);
  }
}
