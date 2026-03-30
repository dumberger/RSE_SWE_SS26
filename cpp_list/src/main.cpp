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
        /// until an invalid input
    } while(num_read > 0);

    printf("\n\nyour numbers in chronological order:\n");
    list.print();
    
    printf("\n\nyour numbers in reverse:\n");
    list.printReverse();

    return 0;
}