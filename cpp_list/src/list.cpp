/*

Erzeugte Kommentare von Github Copilot zum besseren, eigenen Verständnis
der Funktionen

*/

#include "list.hpp"
#include <stdio.h>
#include <stdlib.h>

// Erstellt eine neue Liste und initialisiert die Zeiger auf NULL.
template<typename T>
List<T>::List() {
  first = nullptr; // Anfang der Liste ist leer
  last = nullptr;  // Ende der Liste ist leer
};

// Gibt den Wert eines Elements an einer bestimmten Position in der Liste
// zurück. Gibt `false` zurück, wenn der Index außerhalb der Liste liegt.
template<typename T>
bool List<T>::get(unsigned int index, int &val) {
    ListNode<T>* node = this->first;
        if (node == nullptr) {
            return false;
        }
    for (int i = 0; i < index; i++) {
        if (node == nullptr) { // Wenn das Ende der Liste erreicht ist
        return false;
        }
        node = node->next; // Zum nächsten Element gehen
    }

    if (node == nullptr) {
        return false;
    }

    val = node->value; // Wert des gefundenen Elements speichern
    return true;
};

// Fügt ein neues Element am Ende der Liste hinzu.
template<typename T>
void List<T>::push_back(int value) {
    ListNode<T> *node = first;

    if (node == NULL) { // Wenn die Liste leer ist
        ListNode<T> *newNode = new ListNode();

        if (newNode == NULL) { // Fehlerbehandlung bei Speicherallokation
        exit(1);
        }
        newNode->value = value;  // Wert setzen
        newNode->next = nullptr; // Kein nächstes Element
        newNode->prev = nullptr; // Kein vorheriges Element
        first = newNode;         // Neues Element ist jetzt das erste
        last = newNode;
        return;
  }

  // Neues Element erstellen und anhängen
    ListNode<T> *newNode = new ListNode();
    if (newNode == nullptr) { // Fehlerbehandlung bei Speicherallokation
        exit(1);
    }
    newNode->value = value;  // Wert setzen
    newNode->next = nullptr; // Kein nächstes Element
    newNode->prev = last;    // Vorheriges Element ist das aktuelle letzte Element
    last->next = newNode;    // Neues Element anhängen
    last = newNode;          // Letztes Element aktualisieren
    return;
};

// Löscht alle Elemente der Liste und gibt den Speicher frei.
template<typename T>
List<T>::~List() {
    ListNode<T> *curr = first;
    while (curr != nullptr) {
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }
    first = nullptr; // Liste ist jetzt leer
    last = nullptr;
};

// Entfernt ein Element an einer bestimmten Position in der Liste.
template<typename T>
void List<T>::remove(unsigned int index) {
    ListNode<T> *node = first;
    if (first == nullptr) {
        // Erste Element der Liste NULL = Liste leer
        return;
    }

    if (index == 0) {
        first = node->next;
        if (first != nullptr) {
        first->prev = nullptr;
        } else {
        last = nullptr; // Liste ist jetzt komplett leer
        }
        delete node;
        return;
    }

    for (unsigned int i = 0; i < index; i++) {
        if (node == nullptr) {
        // Index außerhalb der Liste
        return;
        }
        node = node->next;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next; // Das vorherige Element überspringt das zu
                                    // löschende Element
    }
    if (node->next != nullptr) {
        node->next->prev =
            node->prev; // Das nächste Element überspringt das zu löschende Element
    } else {
        last = node->prev; // Wenn das letzte Element gelöscht wird,
                        // aktualisiere den Zeiger auf das letzte Element
    }

    delete node;

    if (first == nullptr) {
        last = nullptr;
    }

    return;
};

// Gibt die Liste aus
template<typename T>
void List<T>::print() {
    ListNode<T> *node = first;
    printf("List in Forward Oder: ");
    while (node != NULL) {
        printf("%i, ", node->value);
        node = node->next;
    }
    printf("\n\n");

    /*
    for (auto i : list) {
        printf("%i", i);
    }

    
    Obiges ist eine Kurzform für:

    for(auto i = list.begin(); i !=list.end(); ++i)
        printf("%i, ", *i);

    */

};


template<typename T>
void List<T>::print_reverse() {
    ListNode<T> *node = last;
    printf("List in Reverse Oder: ");
    while (node != nullptr) {
        printf("%i, ", node->value);
        node = node->prev;
    }
    printf("\n\n");
};

// Gibt die Länge der Liste zurück.
template<typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    for (ListNode *i = first; i != nullptr; i = i->next) { // Durchlaufe die Liste
        len++;                                               // Zähle jedes Element
    }
    return len;
};

template<typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator(first);
}

template<typename T>
ListIterator<T> List<T>::end() {
    // Das Ende der Liste ist nicht beim letzten Element sondern bei dem Element NACH DEM LETZTEN!
    return ListIterator<T>(nullptr);
}