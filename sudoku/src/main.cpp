#include <iostream>
#include "sudoku.hpp"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    Sudoku<9> test;

    test.set(0, 0, '1');
    test.set(0, 1, '2');
    test.set(0, 0, '2');
    test.set(0, 3, '4');
    char symbol = test.get(0, 0);
    //printf("%c\n\n", symbol);
    std::ifstream file("test.txt");
    std::stringstream ss;
    ss << test << "\n";
    Sudoku<9> copy;
    file >> copy;
    std::cout << copy;
    if(!file.good())
    {
        std::cout << "error reading file\n";
    }

    return 0;
}