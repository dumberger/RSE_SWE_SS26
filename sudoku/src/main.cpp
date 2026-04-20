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

    //get parent dir
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();


    std::ofstream output(directory.string() + "/template.txt");
    Sudoku<9> sudoku_template;
    output << sudoku_template;

    //read from input file
    std::ifstream input(directory.string() + "/input.txt");

    //stream from input into copy
    Sudoku<9> copy;
    input >> copy;

    //stream copy to cout
    std::cout << copy;

    //if no good print
    if(!input.good())
    {
        std::cout << "error reading file\n";
    }

    if (copy.solve(copy))
    {
        std::cout << copy;
    }
    else
    {
        std::cout << "Keine Lösung gefunden\n";
    }
    return 0;
}
