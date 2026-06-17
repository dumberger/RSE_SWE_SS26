/* main.cpp */
#include "list.hpp"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    //create a list
    List<int> list;
    
    int number = 0;
    int num_read = 0;
    do 
    {
        /// read numbers from user
        std::cout << "enter a number (anything else to cancel):\n";
        num_read = scanf("%i", &number);
        // put numbers into list
        if (num_read > 0)
        {
            list.push_back(number); 
        }               
        /// until an invalid input
    } while(num_read > 0);
        
    /// output list
    std::cout << "\nyour list:\n";
    list.print();
    std::cout << "\nyour list reverse:\n";
    /// output list in reverse
    list.printReverse();
    std::cout << "\n\n";

    // optimized for loops using iterators
    // forward for now but reverse is possible in most containers using rbegin() and rend()
    for (auto i = list.begin(); i != list.end(); ++i) {
        printf("%i, ", *i);
    }
    printf("\n\n");

    // shorthand version of the loop above
    for (int& i : list) {
        printf("%i, ", i);
    }
    printf("\n\n");
    
    // release memory to avoid a memory leak
    // -> now automatic
    return 0;
}
