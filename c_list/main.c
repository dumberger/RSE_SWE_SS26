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
    /// output list in reverse
    printf("\n\n your numbers in reverse:\n");
    for (int i = listLength(list) - 1; i > -1; i--) {
        // read elements from list
        int value;
        if (listGet(list, i, &value)){
            printf("%i, ", value);
        }
    }
    printf("\n\n");
    // release memory to avoid a memory leak
    listDelete(&list);
    return 0;
}