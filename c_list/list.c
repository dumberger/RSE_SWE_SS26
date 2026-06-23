#include "list.h" //Hier wird das Headerfile eingebunden, damit die Typen und Funktionsprototypen bekannt sind
#include <stdlib.h>
#include <stdio.h>

List listCreate() {
    List list; // Eine neue Liste wird erstellt
    list.first = NULL; // Der Pointer auf den ersten Knoten der Liste wird auf NULL gesetzt, da die Liste zu Beginn leer ist
    return list; // Die erstellte Liste wird zurückgegeben, die erzueugte Liste in der Methode wird nach dem verlassen der Methode gelöscht, daher muss die Liste zurückgegeben werden, 
    // damit sie außerhalb der Methode weiterverwendet werden kann
}

bool listGet(List list, unsigned int index, int* val) {
    ListNode* node = list.first;
    for (int i = 0; i < index; i++) { // Wir iterieren durch die Liste, bis wir den Knoten an der gewünschten Position erreicht haben
        if (node == NULL) {
            return false; // Wenn der Index zu groß ist, wird false zurückgegeben, da der Knoten an der gewünschten Position nicht existiert
        }
        node = node->next;
        // wenn Pointer dann Pfeil wenn kein Pointer dann Punkt
    }

    *val = node->value; // Wenn der Stern vor dem Val steht, dann wird der Wert von Val geändert, wenn kein Stern vor Val steht, dann wird die Adresse von Val geändert
    return true;
}

// Sinn der Funktion listPushBack ist es, einen neuen Knoten am Ende der Liste hinzuzufügen, 
// da die Liste immer von vorne durchlaufen wird, um die Länge zu bestimmen oder einen Wert zu finden, ist es sinnvoll, 

void listPushBack(List* list, int value)  // Wir übergeben einen Pointer auf eine Liste, und den neuen Wert
{
    ListNode* node = list->first; // Wir starten bei list.first, da dies der Pointer auf den ersten Knoten der Liste ist

    // malloc reserviert mir Speicherplatz in der Klammer geben ich die Größe des Speicherplatzes an.
    // ListNode* newNode ist gleich der Pointer für den neuen Speicherplatz.

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    // Typecasting ist hier notwendig, da malloc einen void Pointer zurückgibt, der in einen ListNode Pointer umgewandelt werden muss

    if (node == NULL) // IF ABFRAGE!!! wenn Node = Null ist, dann ist die Liste leer und wir müssen den neuen Knoten als ersten Knoten der Liste hinzufügen
    {

        if (newNode == NULL) // Wenn newNode NULL ist, dann ist die Speicherreservierung fehlgeschlagen und wir müssen das Programm mit einem Fehlercode beenden
        {
            exit(1);
        }

        // Hier wird der Wert dann fur die den ersten Node gesetzt, da die Liste leer ist. 

        // Es wird der Wert 
        newNode->value = value; // Der Wert des neuen Knotens wird auf den übergebenen Wert gesetzt
        newNode->next = NULL; // Der Wert des nächsten Knoten wird auf NULL gesetzt
        list->first = newNode; // Der Pointer auf den ersten Knoten der Liste wird auf den neuen Knoten gesetzt
        return;
    }
    while(node->next != NULL)  // hier wird die liste solange durchlaufen bis das nächste Node null ist, dann bin ich am Ende.
    {
        // Wir iterieren durch die Liste, bis wir das Ende erreicht haben (d.h. bis der Pointer auf NULL zeigt)
        node = node->next;
    } 

    // Selbe Scheiße wie oben, nur dass wir hier den neuen Knoten am Ende der Liste hinzufügen, da wir das Ende der Liste erreicht haben
    newNode->value = value;
    newNode->next = NULL;
    node->next = newNode;
    return;
}

void listDelete(List* list) { // Hier wird die ganze Liste gelöscht, indem wir alle Knoten der Liste entfernen, bis die Liste leer ist

    while(listLength(*list) > 0) { // Wir löschen von vorne nach hinten, immer mit dem Index 0
    
        listRemove(list, 0);
    }
} // solange wird die Liste gelöscht, bis die Länge der Liste 0 ist, dann ist die Liste leer und wir können die Methode beenden

void listRemove(List* list, unsigned int index){ // Wir übergeben einen Pointer auf eine Liste, und den Index des Knotens, der entfernt werden soll
    ListNode* node = list->first; // Wir starten bei dem ersten Knoten der Liste.
    if (list->first == NULL) { // ist der Pointer null
        return; // Wenn Ja dann fertig
    }
    ListNode* tmp; // Wir brauchen einen temporären Pointer, um den Knoten zu speichern, der entfernt werden soll, damit wir ihn später freigeben können
    if(index == 0) { // Wenn der Index 0 ist, dann soll der erste Knoten der Liste entfernt werden, da die Liste immer von vorne durchlaufen wird,
                    
        list->first = node->next; // Der Pointer vom ersten Knoten wird der Pointer von unserem Node gesetzt, damit der erste Knoten der Liste entfernt werden kann
        free(node); node = NULL; // Mit Free geben wir den Speicherplatz des Knotens wieder frei.
        return;
    }
    // Falls der Index größer als 0 ist: dann gilt diese For LOOP
    for (int i = 0; i < index - 1; i++) { // Hier iterieren wir duch die Liste mit next bis wir zu dem Knoten vor dem eigentlichen Knoten kommen.
        node = node->next;
        // Wenn der Pointer auf NULL zeigt, dann haben wir das Ende der Liste erreicht, bevor wir den gewünschten Index erreicht haben,
        if (node->next == NULL) {
            return;
        }
    }
    // Hier wird der Knoten entfernt,
    tmp = node->next; // Wir schreiben die Adresse des Knotens der entfernt werden soll in tmp, damit wir ihn später freigeben können

    node->next = tmp->next; // Hier schreiben wir die Adresse des Knotens der NACH dem entfernten Knoten kommt in den Pointer vom Knoten der VOR dem entfernten Knoten kommt, 
    // damit die Liste wieder zusammenhängt
    free(tmp); tmp = NULL; // Hier löschen wir den Knoten, der entfernt werden soll. MIT FREE
    return;
}

void printList(List list){
   for (ListNode* i = list.first; i != NULL; i = i->next) {
        // Wir iterieren durch die Liste, bis wir das Ende erreicht haben (d.h. bis der Pointer auf NULL zeigt)
        // Wir starten bei list.first, da dies der Pointer auf den ersten Knoten der Liste ist
        // Wir setzen i auf i->next, da wir zum nächsten Knoten der Liste gehen wollen
        // Solange i nicht NULL ist, haben wir noch nicht das Ende der Liste erreicht und können den Wert des Knotens ausgeben
        printf("%i, ", i->value);

    }
}

unsigned int listLength(List list) { //Rückgabewert ist eine unsigned int, da die Länge einer Liste nicht negativ sein kann
    // übergabewert ist eine Liste, die wir durchlaufen wollen, um die Länge zu bestimmen

    unsigned int len = 0;

    for (ListNode* i = list.first; i != NULL; i = i->next) {
        // Wir iterieren durch die Liste, bis wir das Ende erreicht haben (d.h. bis der Pointer auf NULL zeigt)
        // Wir starten bei list.first, da dies der Pointer auf den ersten Knoten der Liste ist
        // Wir setzen i auf i->next, da wir zum nächsten Knoten der Liste gehen wollen
        // Solange i nicht NULL ist, haben wir noch nicht das Ende der Liste erreicht und können die Länge erhöhen
        len++;
    }
    return len;
}

// List.first zeigt auf den ersten Knoten der Liste,,
//  da wir die Liste immer von vorne durchlaufen, um die Länge zu bestimmen oder einen Wert zu finden