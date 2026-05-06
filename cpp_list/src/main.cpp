#include "../include/list.hpp"
#include <stdio.h>

int main(int argc, char** argv) {
    // Eine Liste erstellen
    List<int> list;
    /// Zahlen vom Nutzer einlesen
    int number = 0;
    int num_read = 0;
    do {
        printf("Gib eine Zahl ein (alles andere bricht ab):\n");
        num_read = scanf("%i", &number);
        // Zahl in die Liste einfuegen
        if (num_read > 0) {
            list.push_back(number);
        }
        /// solange die Eingabe gueltig ist
    } while(num_read > 0);
    /// Liste in umgekehrter Reihenfolge ausgeben
    printf("\n\n Deine Zahlen in umgekehrter Reihenfolge:\n");
    for (int i = list.length() - 1; i > -1; i--) {
        // Elemente aus der Liste lesen
        int value;
        if (list.get(i, value)){
            printf("%i, ", value);
        }
    }
    printf("\n\n");

    // Optimierte Schleife mit Iteratoren
    // Vorwaerts; bei vielen Containern waere rueckwaerts mit rbegin() und rend() moeglich
    for (auto i = list.begin(); i != list.end(); ++i) {
        printf("%i, ", *i);
    }
    printf("\n\n");

    // Kurzschreibweise der Schleife oben
    for (int& i : list) {
        printf("%i, ", i);
    }
    printf("\n\n");
    
    // Speicherfreigabe zur Vermeidung von Leaks
    // -> jetzt automatisch
    return 0;
}
