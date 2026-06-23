/* list.cpp */

// the errors in this file cannot be avoided because the IDE does not recognize the include cpp pattern
#include <stdlib.h>

template<typename T>
List<T>::List() // Konstruktor macht eine leere Liste
//:: ist der Scope Resolution Operator, der angibt, dass die Methode List<T>::List() zur Klasse List<T> gehört.
{
    first = nullptr; // Pointer auf den ersten Knoten der Liste wird auf nullptr gesetzt, da die Liste leer ist
    last = nullptr; // Pointer auf den letzten Knoten der Liste wird auf nullptr gesetzt, da die Liste leer ist
} // NULL in C in C++ nullptr

template<typename T> // Wir vor jeder Methode definiert das es ein Template ist

// Destruktor gibt den Speicher der Liste frei
List<T>::~List()
{
    // get the first node
    ListNode<T>* node = this->first; // Hier wird der Pointer auf den ersten Knoten der Liste gesetzt, um die Liste zu durchlaufen und den Speicher freizugeben.
    // Es werden alle Knoten der Liste von Anfang bis Ende durchlaufend gelöscht.
    while (node != nullptr)
    {
        ListNode<T>* next = node->next;
        delete node; // Delete gibt den Speicher frei
        node = next; // next ist die nächste Node die ich löschen will 
    }

    // Es werden die Pointer der Liste auf nullptr gesetzt, um sicherzustellen, dass die Liste leer ist und keine Dangling Pointer mehr existieren.
    this->first = nullptr;
    this->last = nullptr;

    return;
}

// Holen den Wert eines bestimmten Indexes in der Liste. Wenn der Index nicht existiert, wird false zurückgegeben.
template<typename T>
bool List<T>::get(unsigned int index, T& val) const // wir schreiben const weil wir keine Membervariablen der Klasse verändern wollen, also FIRST and LAST
//  oder eine Funktion die eine Referenz auf eine Variable übergibt, sodass der Wert direkt in der Funktion geändert werden kann

// Es können nur const methoden in dieser funktion aufgerufen werden, da diese nichts verändern würden.
{    
    ListNode<T>* node = this->first; 
    // get the node at the given index
    for (unsigned int i = 0; i < index; i++) // Wir duchlaufen die Liste bis zu dem Index - 1 
    {
        if (node == nullptr) // prüfen bei jeder Iteration ob der Knoten ein nullptr ist, wenn ja dann ist der Index nicht vorhanden und wir geben false zurück
        {
            return false;
        }

        node = node->next; // wir gehen zum nächsten Knoten der Liste
    }

    // Wenn der Index die gleiche Länge der Liste hat, dann ist der Knoten ein nullptr und wir geben false zurück
    if (node == nullptr)
    {
        return false;
    }

    // Hier schreiben wir den Wert des Knotens in die Referenzvariable val, sodass der Wert direkt in der Funktion geändert werden kann.
    val = node->value;
    return true; // und geben True zurück, da der Wert erfolgreich geholt wurde.
}


template<typename T>
// Kein Rückgabewert Übergabewert ein Value 
void List<T>::push_back(T value) {
    // Erzeugen eine neuen Node

    //Static Type              Dynamic Type
    ListNode<T>* newNode = new ListNode<T>;  // Hier wird mit new ein neuer Knoten erzeugt, also Speicherplatz dafür reserviert. 
    // new gibt einen Pointer auf den Speicherplatz zurück, der dem neuen Knoten zugewiesen wird. DYNAMIC MEMORY ALLOCATION

    // check if malloc succeeded  Hier wird kontrolliert ob Speicherplatz für den neuen Knoten reserviert werden konnte. Wenn nicht, wird das Programm beendet.
    if (newNode == nullptr)
    {
        exit(1);
    }

    // Es wird die letzte node der Liste in einer Variable gespeichert, um später den neuen Knoten an die Liste anzuhängen.
    ListNode<T>* nodeLastAct = this->last;
    // Setze den Wert des letzten Knotens auf den Wert des neuen Knotens
    newNode->value = value;
    // Setze den nächsten Knoten des neuen Knotens auf nullptr, da es der letzte Knoten der Liste ist.
    newNode->next = nullptr;

    // Wenn der letzte Knoten der Liste ein nullptr ist, dann ist die Liste leer und der neue Knoten wird als erster Knoten der Liste gesetzt.
    if (nodeLastAct == nullptr) 
    {                    
        this->first = newNode; // der erste Knoten der Liste wird auf den neuen Knoten gesetzt
        newNode->prev = nullptr; // der Previous Pointer des neuen Knotens zeigt auf den Nullpointer 
    }
    else // Wenn die Liste nicht leer ist, dann wird der neue Knoten an das Ende der Liste angehängt.
    {
        nodeLastAct->next = newNode; // der Next Pointer des letzten Knotens zeigt auf den neuen Knoten
        newNode->prev = nodeLastAct; // der Previous Pointer des neuen Knotens zeigt auf den letzten Knoten der Liste
    }

    this->last = newNode; // der letzte Knoten der Liste wird auf den neuen Knoten gesetzt

    return; 
}

// Löschen eines Knotens an einem bestimmten Index in der Liste. Wenn der Index nicht existiert, wird false zurückgegeben.
template<typename T>
bool List<T>::remove(unsigned int index)
{
    ListNode<T>* node = this->first; // Wir holen den ersten Knoten der Liste, um die Liste zu durchlaufen und den Knoten an dem gegebenen Index zu löschen.
    // if the first node is nullptr the list is empty
    if (node == nullptr) // Wenn der erste Knoten ein nullptr ist, dann ist die Liste leer und wir geben false zurück.
    {        
        return false;
    }
    
    // Wenn der Index 0 ist, dann wird der erste Knoten der Liste gelöscht und der Pointer auf den ersten Knoten wird auf den nächsten Knoten gesetzt.
    if (index == 0)
    {
        this->first = node->next; // der Pointer auf den ersten Knoten wird auf den nächsten Knoten gesetzt
        if (this->first == nullptr) // Wenn der nächste Knoten ein nullptr ist, dann ist die Liste leer und der Pointer auf den letzten Knoten wird auf nullptr gesetzt.
        {
            this->last = nullptr;  // der Pointer auf den letzten Knoten wird auf nullptr gesetzt
            ;
        }
        else // wenn der nächste Knoten nicht ein nullptr ist, dann wird der Previous Pointer des neuen ersten Knotens auf nullptr gesetzt.
        {
            this->first->prev = nullptr; // this->fist->prev = nullptr; // der Previous Pointer des neuen ersten Knotens wird auf nullptr gesetzt
        }

        delete node; node = nullptr; // der Speicher des gelöschten Knotens wird freigegeben und der Pointer auf den gelöschten Knoten wird auf nullptr gesetzt
        return true; // wir geben true zurück, da der Knoten erfolgreich gelöscht wurde
    }

    // Wenn der index größer als 0 ist, dann wird die Liste bis zu dem Knoten an dem gegebenen Index - 1 durchlaufen, um den Knoten an dem gegebenen Index zu löschen.
    for (unsigned int i = 0; i < index - 1; i++) // wir bleiben in der Schleife bis kleiner index -1 stehen.
    {
        if (node->next == nullptr) 
        {           
            return false; // Wenn der nächste Knoten ein nullptr ist, dann ist der Index nicht vorhanden und wir geben false zurück.
        }
        node = node->next;
    }

    // get the next node which one is the one to remove
    ListNode<T>* tmp = node->next;
    //if temp is a nullptr -> out of index and return
    if (tmp == nullptr) // Hier wird nochmals geprüft, ob der nächste Knoten ein nullptr ist, um sicherzustellen, dass der Index vorhanden ist. Wenn nicht, wird false zurückgegeben.
    {
        return false;
    }
    node->next = tmp->next; // pointer auf 11 
    if (tmp->next == nullptr)
    {
        this->last = node;
        
    }
    else 
    {
        tmp->next->prev = node; //tmp->next->prev = node; // pointer auf 9
    }
    delete tmp; tmp = nullptr;

    return true;
}

// print the list from first to last
template<typename T>
void List<T>::print() const //
{
    for (ListNode<T>* i = this->first; i != nullptr; i = i->next)
    {
        if (i->next == nullptr)
        {
            std::cout << i->value;
        }
        else
        {
            std::cout << i->value << ", ";
        }        
    }
    return;
}

// print the list from last to first
template<typename T>
void List<T>::printReverse() const
{
    for (ListNode<T>* i = this->last; i != nullptr; i = i->prev)
    {
        if (i->prev == nullptr)
        {
            std::cout << i->value;
        }
        else
        {
            std::cout << i->value << ", ";
        }        
    }
    return;
}

// return the number of elements in the list
template<typename T>
unsigned int List<T>::length() const
{
    unsigned int len = 0;
    for (ListNode<T>* i = this->first; i != nullptr; i = i->next)
    {
        len++;
    }
    return len;
}

// return an iterator to the first element
template<typename T>
//Rückgabewert ListIterator||| Klasse List ||| Methode begin
ListIterator<T> List<T>::begin()  // 
{
    return ListIterator(this->first);
}

// return an iterator to the position after the last element
template<typename T>
ListIterator<T> List<T>::end() 
{
    return ListIterator<T>(nullptr);
}