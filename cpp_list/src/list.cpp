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

  if (node == nullptr) {
    return false;
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

  // Löschen eines Element mittendrin
  ListNode *next_node = tmp->next;
  node->next = next_node;
  next_node->prev = node;

  delete tmp;
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
