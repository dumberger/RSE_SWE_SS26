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

    //test insert at 0
    printf("Testing insert and remove at zero\n");
    testList.insert(0,-9999);
    testList.print();
    printf("\noriginal\n");
    testList.remove(0);
    testList.print();
    printf("\n");

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

    //test lenght and size
    if (testList.count() == testList.length()) {
        printf("Size equals length\n");
    }
    else {
        printf("Size does not equal length\n");
    }
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

    //tests also insert, remove and both print methods
    //testListMethods(myList);

    return 0;
}