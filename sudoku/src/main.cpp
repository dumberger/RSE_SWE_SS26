#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <ostream>
#include "../include/solver.hpp"
#include "../include/generator.hpp"
#include "../include/sudoku.hpp"

using namespace std;

int main() 
{
    // std::filesystem::path directory(__FILE__);
    // directory = directory.parent_path();
    Solver solver;
    // if(solver.loadSudoku(directory / "input.txt"))
    // {
    //      solver.solve(true);
    //  }

    Sudoku<9> test = Generator::generate();
    std::cout << test << std::endl;
    solver.loadSudoku(test);
    std::cout << "Solutions: " << solver.solve(true) << std::endl;

    return 0;
}
