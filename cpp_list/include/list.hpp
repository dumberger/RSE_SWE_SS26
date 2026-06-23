#pragma once

#include <iostream>
#include "ListNode.hpp"
#include "ListIterator.hpp"

template<typename T> //Template Definition mit dem Typ T, der später beim Erstellen der Liste angegeben wird
class List
{
private:
    ListNode<T>* first; //Pointer auf den ersten Knoten der Liste
    ListNode<T>* last; //Pointer auf den letzten Knoten der Liste

public:
    
    List(); // Konstruktor macht eine leere Liste
    ~List(); // Destruktor gibt den Speicher der Liste frei

    bool get(unsigned int index, T& value) const; // const steht dafür, dass die Membervariablen der Klasse nicht verändert werden dürfen also FIRST and LAST
    // T steht für den Typ und das & steht dafür, dass die Variable value als Referenz übergeben wird, sodass der Wert direkt in der Funktion geändert werden kann

    // Unterschied Kopie und Referenz: Bei einer Kopie wird der Wert in der Funktion geändert, aber die Variable außerhalb der Funktion bleibt unverändert. 
    // Bei einer Referenz wird der Wert direkt in der Funktion geändert und die Variable außerhalb der Funktion wird ebenfalls geändert.


    void push_back(T value);

    bool remove(unsigned int index);


    void print() const; // std::ostream& os = std::cout bedeutet, dass der Standardausgabestrom std::cout verwendet wird, 
    // wenn kein anderer Ausgabestrom angegeben wird.


    void printReverse() const; // std::ostream& os = std::cout bedeutet, dass der Standardausgabestrom std::cout verwendet wird,
    unsigned int length() const; // const steht dafür, dass die Membervariablen der Klasse nicht verändert werden dürfen also FIRST and LAST

    ListIterator<T> begin();
    // Wir geben einen Iterator zurück, der auf den ersten Knoten der Liste zeigt. Der Iterator wird verwendet, um die Elemente der Liste zu durchlaufen.

    ListIterator<T> end();
    // Wir geben einen ListIterator zurück bei Aufruf der end() Methode. 
};

// not a good design but it woks fo templating the List afterwards
// do not use this in production code
#include "../src/list.cpp"