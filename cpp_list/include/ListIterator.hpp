#pragma once

#include "ListNode.hpp"

template<typename T>
class ListIterator
{
public:
// Konstruktor der Klasse ListIterator, der einen Pointer auf einen ListNode<T> als Parameter erhält.
    ListIterator(ListNode<T>* node) 
    {
        _node = node;
    }
// T& operator*() gibt eine Referenz auf den Wert des Knotens zurück, auf den der Iterator zeigt.
// Den Wert des Knoten per Referenz zurückzugeben, ermöglicht es, den Wert direkt zu ändern, ohne eine Kopie des Werts zu erstellen.
    T& operator*() 
    {
         return _node->value; 
    }
    // & immer per Referenz!
    // ListIterator& operator++() verschiebt den Iterator auf den nächsten Knoten in der Liste und gibt eine Referenz auf den Iterator zurück.
    ListIterator& operator++() 
    // ++ Operator wird überladen, um den Iterator auf den nächsten Knoten in der Liste zu verschieben.
    {
    _node = _node->next; return *this; //*This bedeutet es wird der nächste Knoten zurückgegeben, auf den der Iterator zeigt. 
    //Dereferenzierter ListIterator als Rückgabewert.
    }

    bool operator!=(ListIterator rhs) // ungleich Operator hat ein lhs und ein rhs, also left hand side und right hand side. 

    {
         return _node != rhs._node; 
    }
private:
    ListNode<T>* _node;
};
// Operatoren können somit überladen werden, um benutzerdefinierte Typen zu vergleichen oder zu manipulieren. In diesem Fall wird der ungleich Operator != überladen, um zwei ListIterator-Objekte zu vergleichen.
// Der Operator != gibt true zurück, wenn die beiden Iteratoren auf unterschiedliche Knoten zeigen, und false, wenn sie auf denselben Knoten zeigen.
// Der Operator * wird überladen, um den Wert des Knotens zurückzugeben, auf den der Iterator zeigt. Der Operator ++ wird überladen, um den Iterator auf den nächsten Knoten in der Liste zu verschieben.
// 
// ALS BEISPIEL. ist dann möglich. 

// auto steht für ListIterato
for (auto node = list.begin(); node != list.end(); ++node)
{
    int value = *node;
}