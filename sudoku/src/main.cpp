#include <filesystem>
#include <iostream>
#include <ostream>
#include <fstream>
#include <utility>
#include "../include/sudoku.hpp"

using namespace std;

int main() 
{
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
    //std::ofstream output(directory.string() + "/template.txt");
    //Sudoku<9> sudoku_template;
    //output << sudoku_template;

    //std::ifstream input(directory.string() + "/input.txt");
    std::ifstream input(directory.string() + "/template.txt");
    Sudoku<9> copy;
    input >> copy;
    std::cout << copy;
    if(!input.good())
    {
        std::cout << "error reading file\n";
    }

    auto [row, col] = copy.next();
    std::cout << "row: "  << row << " || col: " << col << std::endl;

    return 0;
}
