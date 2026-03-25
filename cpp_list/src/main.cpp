#include "list.hpp"
#include <stdio.h>

int main(int argc, char** argv) {
    // create a list
    List list;
    /// read numbers from user
    int number = 0;
    int num_read = 0;
    do {
        printf("enter a number (anything else to cancel):\n");
        num_read = scanf("%i", &number);
        // put number into list
        if (num_read > 0) {
            list.push_back(number);
        }
        else { 
            printf("Ungueltige Eingabe! Einlesen wird abgebrochen.\n");
        }
        list.print();/// until an invalid input
    } while(num_read > 0);
    /// output list in reverse
    printf("\n\n your numbers in reverse:\n");
    for (int i = list.length() - 1; i > -1; i--) {
        // read elements from list
        int value;
        if (list.get(i, value)){
            printf("%i", value);
            if (i > 0) {
                printf(", ");
            }
        }
    }
    printf("\n\n");
    // release memory to avoid a memory leak
    // -> now automatic
    return 0;
}