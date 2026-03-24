/* main.cpp */
#include "list.hpp"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    //create a list
    List list;
    
    int number = 0;
    int num_read = 0;
    do 
    {
        /// read numbers from user
        printf("enter a number (anything else to cancel):\n");
        num_read = scanf("%i", &number);
        // put numbers into list
        if (num_read > 0)
        {
            list.push_back(number); 
        }               
        /// until an invalid input
    } while(num_read > 0);
        
    /// output list

    list.print();
    printf("\n");
    /// output list in reverse
    list.printReverse();
    printf("\n\n");
    // the destructor will be called automatically        
    return 0;
}