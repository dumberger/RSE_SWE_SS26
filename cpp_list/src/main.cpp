#include "../include/list.hpp"
#include <stdio.h>

int main(int argc, char** argv) {
    // create a list
    List<int> list;
    /// read numbers from user
    int number = 0;
    int num_read = 0;
    int choice = 0;
    int choice_read = 0;

    do {
        printf("enter a number (anything else to cancel):\n");
        num_read = scanf("%i", &number);
        // put number into list
        if (num_read > 0) {
            list.push(number);
        }
        /// until an invalid input
    } while(num_read > 0);

    while(getchar() != '\n'); // clear input buffer !!!
    // output list in normal order
    printf("\nyour numbers in the given order:\n");
    list.print();

    /// output list in reverse
    printf("\nyour numbers in reverse:\n");
    list.printReverse();

    do{
        printf("\n--- MENU ---\n");
        printf("1: Show a specific number (listGet)\n");
        printf("2: Remove a number (listRemove)\n");
        printf("Anything else: Exit\n");
        printf("Your choice: ");

        choice_read = scanf("%i", &choice);

        if(choice_read <= 0) {
            while(getchar() != '\n'); // clear input buffer
            break; // Exit if the input is not a valid integer
        }

        int index = 0;
        int value_found = 0;

        switch (choice) {
            case 1:
                printf("Enter the index of the number you want to see: ");
                if(scanf("%i", &index) > 0) {
                    if(list.get(index, value_found)) {
                        printf("Number at index %i: %i\n", index, value_found);
                    } else {
                        printf("Invalid index %i. No number found.\n", index);
                    }
                }
                break;
            case 2:
                printf("Enter the index of the number you want to remove: ");
                if(scanf("%i", &index) > 0) {
                    list.remove(index);
                    if(list.length() > 0) {
                        printf("\nyour numbers in the given order:\n");
                        list.print();
                        printf("\nyour numbers in reverse:\n");
                        list.printReverse();
                        
                    } else {
                        printf("The list is now empty after removal.\n");
                    }
                }
                break;
            default:
                printf("Exiting the menu.\n");
                choice = 0; // Exit
                break;
        }
        while (getchar() != '\n'); // clear input buffer after each choice

    } while(choice == 1 || choice == 2);


    // release memory to avoid a memory leak
    return 0;
}
