#include <iostream>
#include "sudoku.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

int main() {
    Sudoku<9> test;

    test.set(0, 0, '1');
    test.set(0, 1, '2');
    test.set(0, 0, '2');
    test.set(0, 3, '4');
    char symbol = test.get(0, 0);
    //printf("%c\n\n", symbol);
    
    //std::filesystem::path directory(__FILE__);
    //std::cout<<directory.parent_path();
    
    std::ofstream output("output.txt");
    output << test;
    std::ifstream input("input.txt");
    Sudoku<9> copy;
    input >> copy;
    std::cout << copy;
    if(!input.good())
    {
        std::cout << "error reading file\n";
    }
    return 0;
}