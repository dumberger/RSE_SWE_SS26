#include <filesystem>
#include <iostream>
#include "sudoku.hpp"
#include <fstream>
#include "solver.hpp"

using namespace std;

int main() {
    Sudoku<9> test;
    char symbol = test.get(0, 0);
    //printf("%c\n\n", symbol);

    //get parent dir
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();


    // std::ofstream output(directory.string() + "/template.txt");
    // Sudoku<9> sudoku_template;
    // output << sudoku_template;

    //read from input file
    std::ifstream input(directory.string() + "/input.txt");
    input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    //if no good print
    if(!input.good())
    {
        std::cout << "error reading input.txt file\n";
        return -1;
    }

    //stream from input into copy
    Sudoku<9> copy;

    try {
        input >> copy;
    } catch (const std::ios_base::failure& e) {
        std::cout << "error setting input to sudoku\n";
        return -1;
    }

    //stream copy to cout
    std::cout << copy;

    printf("Solution:\n");
    //if solved print to cout

    Solver solver;
    solver.loadSudoku(copy);

    if (solver.solve())
    {
        std::cout << copy;
        // std::ofstream output(directory.string() + "/solution.txt", std::ios::trunc);
        // if (output.is_open()) {
        //     output << copy;
        //     output.close();
        // }

    }
    else
    {
        std::cout << "Keine Lösung gefunden\n";
    }
    return 0;
}