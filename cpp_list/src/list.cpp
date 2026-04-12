// the errors in this file cannot be avoided because the IDE does not recognize the include cpp pattern

#include <stdlib.h>
#include <iostream>
#include "../include/list.hpp"


template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
}

template<typename T>
bool List<T>::get(unsigned int index, T& val) {
    unsigned int lenght = length();
    if (index >= lenght) { // Wenn der Index größer oder gleich der Anzahl der Elemente in der Liste ist, gibt es keinen Wert an diesem Index, daher wird false zurückgegeben
        return false;
    }

    ListNode<T>* node;
    // Prüfen ob der Index in der ersten oder zweiten Hälfte der Liste liegt, um die Suche zu verbessern
    if (index > lenght / 2) { // Wenn der Index in der zweiten Hälfte der Liste liegt:
        node = last;
        for(unsigned int i = lenght - 1; i > index; i--) { // Von hinten durch die Liste gehen, bis der gewünschte Index erreicht ist
            node = node->prev;
        }
    } else { // Wenn der Index in der ersten Hälfte der Liste liegt:
        node = first;
        for(unsigned int i = 0; i < index; i++) { // Von vorne durch die Liste gehen, bis der gewünschte Index erreicht ist
            node = node->next;
        }
    }
    val = node->value;
    return true;

}


template<typename T>
void List<T>::push(T value) {
        // ____________________Neuen Knoten erstellen und speichern______________________ 
    ListNode<T>* newNode = new ListNode<T>;
    if (newNode == nullptr) { //Wenn kein Speicher mehr verfügbar ist, gibt malloc NULL zurück, daher wird die Funktion mit einem Fehlercode verlassen
        exit(1);     
    }

    // ____________________Die Date im neuen Knoten setzen______________________
    newNode -> value = value;
    newNode -> next = nullptr; // Der neue Knoten wird das letzte Element der Liste sein, daher wird sein next-Zeiger auf NULL gesetzt
    newNode -> prev = last; // Der prev-Zeiger, zeigt zum alten leetzten Element der Liste

    // ____________________Den Knoten in die Liste einfügen______________________
    if(first == nullptr) { // Wenn die Liste leer ist, wird der neue Knoten zum ersten Element der Liste
        first = newNode;
        newNode -> prev = nullptr; // Da es das erste Element ist, zeigt der prev-Zeiger auf NULL
    } else { // Ansonsten wird der neue Knoten an das Ende der Liste angehängt
        last -> next = newNode; // Der next-Zeiger des alten letzten Elements zeigt auf den neuen Knoten
    }

    // ____________________Den Zeiger auf das letzte Element der Liste aktualisieren______________________
    last = newNode; // Der neue Knoten wird zum letzten Element der Liste
}

template<typename T>
List<T>::~List() {
    while(length() > 0) {
        remove(0);
    }
}

template<typename T>
void List<T>::remove(unsigned int index){
    if(first == nullptr) { // Wenn die Liste leer ist, gibt es nichts zu entfernen, daher wird die Funktion verlassen
        return;
    }
    ListNode<T>* node = first;

    // ____________________Den Knoten, der entfernt werden soll, finden_____________________
    for (int i = 0; i < index; i++) {
        node = node->next;
        if (node == nullptr) { // Wenn der Index größer als die Anzahl der Elemente in der Liste ist, gibt es nichts zu entfernen, daher wird die Funktion einfach verlassen
            printf("\n\n\ninvalid index, please enter a valid number !!!\n");
            printf("_____________________________________________________\n");
            return;
        }
    }

    // ____________________Nachbarn miteinander verbinden, um den Knoten aus der Liste zu entfernen_____________________

    // Wenn es einen Vorgänger gibt:
    if (node->prev != nullptr) { // Wenn der Knoten nicht das erste Element der Liste ist, wird der next-Zeiger des vorherigen Elements auf das nächste Element gesetzt
        node->prev->next = node->next;
    } else { // Wenn der Knoten das erste Element der Liste ist, wird der Zeiger auf das erste Element der Liste auf das nächste Element gesetzt
        first = node->next;
    }

    // Wenn es einen Nachfolger gibt:
    if (node->next != nullptr) { // Wenn der Knoten nicht das letzte Element der Liste ist, wird der prev-Zeiger des nächsten Elements auf das vorherige Element gesetzt
        node->next->prev = node->prev;
    } else { // Wenn der Knoten das letzte Element der Liste ist, wird der Zeiger auf das letzte Element der Liste auf das vorherige Element gesetzt
        last = node->prev;
    }


    // ____________________Den Speicher des entferneten Knoten wieder freigeben________________________
    delete node;
}

template<typename T>
void List<T>::print() {
    ListNode<T>* currentNode = first; //Am Anfang der Liste anfangen
    while(currentNode != nullptr){
        printf("%i, ", currentNode->value);
        currentNode = currentNode->next; // Knoten weitergehen, bis zum Ende der Liste
    }
    printf("\n");
    
}

template<typename T>
void List<T>::printReverse() {
    ListNode<T>* currentNode = last; // Ganz am Ende der Liste beginnen
    while (currentNode != nullptr) {
        printf("%i, ", currentNode->value);
        currentNode = currentNode->prev; // Knoten zurückgehen, bis zum Anfang der Liste
    }
    printf("\n");
}

template<typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    for (ListNode<T>* i = first; i != NULL; i = i->next) {
        len++;
    }
    return len;

}

template<typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator(first);
}

template<typename T>
ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
}