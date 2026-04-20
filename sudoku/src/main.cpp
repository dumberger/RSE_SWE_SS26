#include <iostream>
#include "sudoku.hpp"

using namespace std;

int main() {
    Sudoku<9> test;

    test.set(0, 0, '1');
    char symbol = test.get(0, 0);
    printf("%c\n", symbol);

    return 0;
}