// Comments here for understanding code and learning

#include "list.h"
#include <stdio.h>

int main(int argc, char** argv) {
    // create a list
    List list = listCreate();

    /// read numbers from user
    int number = 0;
    int num_read = 0;
    do {
        printf("enter a number (anything else to cancel):\n");
        num_read = scanf("%i", &number);
        // put number into list
        if (num_read > 0) {
            listPushBack(&list, number);
        }
        /// until an invalid input
    } while(num_read > 0);


    // HOMEWORK - CHANGE //


    // OPTIONAL
    // Remove at index, first and last
    // Check if remove works
    //listRemove(&list, 1);
    //listRemove(&list, 0);
    //listRemove(&list, listLength(list)-1);

    printf("\n\nyour numbers in chronological order:\n");
    printList(list);
    
    printf("\n\nyour numbers in reverse:\n");
    printReverseList(list);
    printf("\n\n");


    // HOMEWORK - CHANGE //


    // release memory to avoid a memory leak
    listDelete(&list);
    return 0;
}