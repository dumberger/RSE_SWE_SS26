#include <filesystem>
#include <iostream>
#include "sudoku.hpp"
#include <fstream>

using namespace std;

int main() 
{
    // Get directory of the current source file
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
    // Open template.txt and write an empty sudoku field into it
    std::ofstream output(directory.string() + "/template.txt");
    Sudoku<9> sudoku_template;
    output << sudoku_template;

    // Open input.txt and read an existing sudoku field from it
    std::ifstream input(directory.string() + "/input.txt");
    Sudoku<9> copy;
    input >> copy;
    std::cout << copy;

    // Check if reading the file was not successful
    if(!input.good())
    {
        std::cout << "error reading file\n";
    }
    return 0;
}