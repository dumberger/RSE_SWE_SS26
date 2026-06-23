#include "list.h"
#include <stdio.h>

int main(int argc, char** argv) { // Hier beginnt die main Funktion, die der Einstiegspunkt des Programms ist
    // int argc ist die Anzahl der Argumente, die an das Programm übergeben werden, und char** argv ist ein Array von Strings,
    // die die Argumente enthalten
    // Das braucht man, damit man das Programm mit Argumenten starten kann
    // char** argv ist ein Pointer auf ein Array von Strings, da die Argumente als Strings übergeben werden
    
    // hier wird eine leere Liste erstellt.
    List list = listCreate();

    // Hier Konsoleneingabe für Eingabe der Parameter 
    /// read numbers from user
    int number = 0;
    int num_read = 0;
    do {
        printf("enter a number (anything else to cancel):\n"); // Aufforderung ausgeben
        num_read = scanf("%i", &number); // scanf liest die Eingabe von der Konsole und speichert sie als Integer

        // Wenn num_read größer als 0 ist, dann wurde eine gültige Zahl eingelesen, und wir können sie der Liste hinzufügen
        if (num_read > 0) { 
            listPushBack(&list, number);
        }
        /// until an invalid input

    // Bedingung solange num_read größer als 0 ist, wird die Schleife fortgesetzt. 
    } while(num_read > 0);
    // Ausgabe in der Konsole der eingegebenen Zahlen in der Reihenfolge, in der sie eingegeben wurden
    printf("\n\n your numbers in reverse:\n");
    
    for (int i = listLength(list) - 1; i > -1; i--) {
        // read elements from list
        int value;
        if (listGet(list, i, &value)){
            printf("%i, ", value);
        }
    }
    printf("\n\n");
    // release memory to avoid a memory leak
    listDelete(&list);
    return 0;
}