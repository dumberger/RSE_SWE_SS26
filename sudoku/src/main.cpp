#include <filesystem>
#include <iostream>
#include "sudoku.hpp"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    Sudoku<9> test;
    char symbol = test.get(0, 0);
    //printf("%c\n\n", symbol);

    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    std::ofstream output(directory.string() + "/template.txt");
    Sudoku<9> sudoku_template;
    output << sudoku_template;
    std::ifstream input(directory.string() + "/input.txt");
    Sudoku<9> copy;
    input >> copy;
    std::cout << copy;
    if(!input.good())
    {
        std::cout << "error reading file\n";
    }
    return 0;
}