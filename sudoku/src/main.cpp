#include <filesystem>
#include <iostream>
#include "sudoku.hpp"
#include <fstream>

using namespace std;

int main() {
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