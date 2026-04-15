#include "list.hpp" // with "" are used for user defined header files, with <> are used for system header files
#include <cstdio>

int main (int args, char** argv)
{
    // create a list
    List list;

    // get the size of the list
    int size;
    printf("Enter the size of the list: ");
    scanf("%i", &size);

    // read value from user
    int number = 0;
    int num_read = 0;
    for (int i = 0; i < size; i++) {
        printf("Enter a number: ");
        num_read = scanf("%i", &number); // & is used to get the address of the variable, so that scanf can store the input value in that variabl (works like input in python)

        // put the values in the list
        if (num_read > 0) {
            list.pushBack(number);
        }
        // until an invalid input
    } 

    list.print();
    
    // output list in reverse
    printf("List in reverse: ");
    list.printReverse();

    // remove an element from the list

    printf("Remove element number: ");
    int numbertoRemove = 0;
    scanf("%i", &numbertoRemove);
    if (numbertoRemove > 0) {
        numbertoRemove = numbertoRemove - 1;
    }
    list.remove(numbertoRemove); // remove the element at the specified index

    list.print();

    // release memory to avoid memory leaks - is done with destructor.
    return 0;
}   // destructor will be called automatically when the list goes out of scope, so we don't need to call it explicitly.
