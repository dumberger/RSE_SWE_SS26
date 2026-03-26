#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "list.hpp"

int main(int argc, char** argv) {

    //entry to nodes
    List myList;

    //ask user for number
    int numberFromUser = -1;
    int inputRead = 0;
    do {
        printf("Please enter a number (anything else to cancel): ");
        inputRead = scanf("%i", &numberFromUser);

        if (inputRead > 0) {
            //do the list things
            myList.append(numberFromUser);
        }
    }
    while (inputRead > 0);

    //output stored values
    printf("\n\nyour numbers in reverse:\n");
    myList.printReverse();
    printf("\n\n");

    return 0;
}