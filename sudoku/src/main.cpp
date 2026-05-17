#include "solver.hpp"
#include "sudokuGenerator.hpp"

#include <cstdlib>
#include <random>

using namespace std;

int main() { 
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
     SudokuGenerator generator;
     // load template format 
    if(generator.loadSudoku(directory / "template.txt"))
    {
        // create a sudoku
        generator.generate();
    }
    
    // solve the sudoku
    Solver solver; 

    std::string is_solve = "random_generated.txt";
    if(solver.loadSudoku(directory / is_solve))
    {
        solver.solve();
    }
    return 0;
}
