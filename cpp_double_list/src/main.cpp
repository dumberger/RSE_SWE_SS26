/*

Compile:
gcc main.c -o main
./main

*/

#include "cpp_double_list.hpp"
#include <stdio.h>

int main(int argc, char **argv) {

  // create a list
  List list;

  // read number from user
  int number = 0;
  int num_read = 0;

  do {

    printf("enter a number (anything else to cancel): ");
    num_read = scanf("%i", &number);

    // put number into list until an invalid input
    if (num_read > 0) {
      list.push_back(number);
    }

  } while (num_read > 0);

  list.print();
  list.print_reverse();

  list.remove(0);

  list.print();

  return 0;
}