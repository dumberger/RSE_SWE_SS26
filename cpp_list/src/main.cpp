#include "list.hpp"
#include <stdio.h>

int main(int argc, char** argv) {
    // create a list
    List list;
    /// read numbers from user
    int value;
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

    /// output list in reverse
    printf("\n");
    list.print(),
    printf("\n");
    list.printReversed();
    printf("\n");

    return 0;
}