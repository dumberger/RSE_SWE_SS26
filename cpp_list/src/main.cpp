#include "list.hpp"
#include <array>
#include <stdio.h>

int main(int argc, char **argv) {
  // create a list
  List<int> list;
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
  } while (num_read > 0);
  /// output list in reverse
  printf("\n\n your numbers in reverse:\n");
  // Option 1 einfach verkettete Liste
  /*
    for (int i = listLength(list) - 1; i > -1; i--) {
      // read elements from list

      int value;
      if (listGet(
              list, i,
              &value)) { // man verändert in listGet am pointer zu val den Wert
        printf("%i, ", value);
      }
    } */

  // Option 2 doppelt verkettete Liste
  list.printReverse();
  printf("\n\n");

  // optimized for loops using iterators
  // forward for now but reverse is possible in most containers using rbegin()
  // and rend()
  for (auto i = list.begin(); i != list.end(); ++i) {
    printf("%i, ", *i);
  }
  printf("\n\n");

  // shorthand version of the loop above
  for (int &i : list) {
    printf("%i, ", i);
  }
  printf("\n\n");

  // release memory to avoid a memory leak
  // listDelete(&list); // am Ende Liste nicht löschen weil cpp sich selbst drum
  // kümmert
  return 0;
}
