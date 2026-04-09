#pragma once

#include "ListIterator.hpp"
#include "ListNode.hpp"

// #include <stdbool.h>    bool ist in cpp standardmäßig definiert, also nicht
// nötig

class List { // classe statt struct, weil wir in cpp sind, und in cpp haben wir
             // klassen
private:     // private, weil man nicht von außen auf die knoten zugreifen soll,
             // sondern nur über die methoden der klasse
  struct ListNode {
    int value;
    struct ListNode *next;
    struct ListNode *prev;
  };
  ListNode *first;

public:
  ListNode *last;

  List();  // statt List create() in c, hier in cpp Konstruktor wenn gleicher
           // name wie Klasse
  ~List(); // Destruktor, wird automatisch aufgerufen wenn Objekt gelöscht wird,
           // statt deleteList in c
  bool get(unsigned int index, int *val);
  void push_back(int value);
  void remove(unsigned int index);
  void print();
  unsigned int length();
  void printReverse();

  ListIterator begin();
  ListIterator end();
};
