
#include <filesystem>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include "../include/sudoku.hpp"

using namespace std;

int main()
{
    Sudoku<9> sudoku;

    // sudoku.set(1, 1, '1');
    // std::cout << sudoku.get(1, 1) << std::endl;
    // sudoku.set(1, 1, '3');
    // std::cout << sudoku.get(1, 1) << std::endl;

    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    std::ofstream output(directory.string() + "/output.txt");
    output << sudoku;
    std::ifstream input(directory.string() + "/input.txt");
    Sudoku<9> copy;
    input >> copy;
    std::cout << copy;
    if (!input.good())
    {
        std::cerr << "error reading file" << std::endl;
    }

    return 0;
}