#include <cstdio>
#include <iostream>
#include "../include/sudoku.hpp"

using namespace std;

int main() {
    Sudoku<9> test;

    test.set(0,0,'5');
    test.set(0,1,'3');
    test.set(0,3,'4');
    char symbol=test.get(0,0);

    printf("Symbol at (0,0): %c\n", symbol);
    cout << "Symbol at (0,0): " << symbol << endl;
    std::cout << "Symbol at (0,0): " << test.get(0,0) << std::endl;
    std::cout << test << "/n";


    return 0;
}
