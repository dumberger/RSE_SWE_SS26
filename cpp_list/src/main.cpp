#include "list.hpp"
#include <stdio.h> // mit spitze Klammern systemlib und mit "" eigene header Dateien

int main(int argc, char **argv) {
  // create a list
  List list;

  /// read numbers from user
  int number = 0;
  int num_read = 0;

  do {
    printf("enter a number (anything else to cancel):\n");
    num_read = scanf(
        "%i",
        &number); // scanf ist wie input in python, und &number ist die adresse
                  // von number, damit scanf den wert in number speichern kann

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

  // release memory to avoid a memory leak
  // listDelete(&list); // am Ende Liste nicht löschen weil cpp sich selbst drum
  // kümmert
  return 0;
}
