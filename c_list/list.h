#pragma once

#include <stdbool.h>

typedef struct ListNode_t { 

    int value;
    struct ListNode_t* next; // der Pointer braucht den Typnamen damit der Compiler weiß, dass es sich um einen Pointer auf den Typ handelt, der gerade definiert wird
                            // Wir müssen den Typnamen hier noch einmal angeben, weil wir den Typnamen erst nach der Definition des Structs definieren.
} ListNode; // ListNode ist der Alias für struct ListNode_t 

typedef struct {
    ListNode* first; // Hier wird kein Struct mehr benötigt, da wir bereits einen Alias für struct ListNode_t definiert haben
    // First ist immer der Pointer auf den ersten Knoten der Liste, da wir die Liste immer von vorne durchlaufen, um die Länge zu bestimmen oder einen Wert zu finden
} List; 


// Funktionen 

List listCreate(); //Rückgabewert ist eine Liste, die erstellt wurde
bool listGet(List list, unsigned int index, int* val);
void listPushBack(List* list, int value);
void listDelete(List* list);
void listRemove(List* list, unsigned int index);
void printList(List list);
unsigned int listLength(List list); // unsigned int, da die Länge einer Liste nicht negativ sein kann