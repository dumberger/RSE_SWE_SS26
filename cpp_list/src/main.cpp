#include "list.hpp"
#include <stdio.h>
#include <array> 

int main(int argc, char** argv) {
    // create a list
    List<int> list;
    /// read numbers from userDoople verkette linked list implementieren
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
    
    list.print();
    
    // output list reversely
    printf("\n\n your numbers in reverse:\n");
    list.reverse_print();  
     
}