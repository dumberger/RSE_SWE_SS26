#include "../include/list.hpp"
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
    /// output list in reverse
    printf("\n\n your numbers in reverse:\n");
    for (int i = list.length() - 1; i > -1; i--) {
        // read elements from list
        int value;
        if (list.get(i, value)){
            printf("%i, ", value);
        }
    }
    printf("\n\n");
    for(auto i =list.begin(); i != list.end();++i){ //Besser, weil wir die Liste nicht durchlaufen müssen
        printf("%i, ", *i);
    }
    printf("\n\n");

    //Kurzform der obigen Schleife
    for(auto i: list){
        printf("%i, ", i);
    }
    printf("\n\n");

    // release memory to avoid a memory leak
    // -> now automatic
    return 0;
}
