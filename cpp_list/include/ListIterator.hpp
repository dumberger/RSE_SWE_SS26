#pragma once
#include "ListNode.hpp"

class ListIterator{
public:
    ListIterator(ListNode* node);
    int& operator*(); //glaub ein bestimmtes Element rausziehen -> mit & können wir die Liste verändern 
    ListIterator operator++(); //zeigt auf das nächste Element
    bool operator!=(ListIterator rhs); // linker Teil kommt aus der Instanz von ListIterator (deshalb nur ein Wert)

private:
    ListNode* _node; //Pointer weil wir ja nur auf einen ListNode verweisen
};










