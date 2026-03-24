//
// Created by madtic on 06.03.26.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "list.hpp"

int main(int argc, char** argv) {

    //entry to nodes
    List myList;

    myList.append(111);
    myList.append(222);
    myList.append(333);
    myList.remove(0);

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