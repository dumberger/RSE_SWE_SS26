//
// Created by madtic on 06.03.26.
//

#include <cstdio>
#include <cstdlib>
#include "list.hpp"

void testListMethods(List testList) {
    if (testList.count() == 0) {
        printf("\nList is empty");
        return;
    }

    //test insert and remove

    printf("Testing insert and remove at last-1\n");
    int last = testList.count()-1;
    testList.insert(last,9999);
    testList.print();
    printf("\noriginal\n");
    testList.remove(last);
    testList.print();
    printf("\n");

    unsigned int index = testList.count() / 2;
    printf("Testing List index is %u\n", index);
    testList.insert(index,1000);
    testList.print();
    printf("\noriginal\n");
    testList.remove(index);
    testList.print();

    printf("\nreverse print\n");
    testList.printReverse();
    printf("\n");
}

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