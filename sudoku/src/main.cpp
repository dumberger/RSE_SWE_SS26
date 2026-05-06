#include "solver.hpp"
#include "generator.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
    // Generiere neues Sudoku-Rätsel und speichere in input.txt
    std::cout << "Generating new Sudoku puzzle..." << std::endl;
    Sudoku<9> puzzle = SudokuGenerator::generatePuzzle(40);
    SudokuGenerator::writeToFile(puzzle, (directory / "input.txt").string());
    std::cout << "Puzzle written to input.txt" << std::endl;
    
    // Löse das Rätsel
    Solver solver;
    if(solver.loadSudoku(directory / "input.txt"))
    {
        std::cout << "Solving Sudoku..." << std::endl;
        solver.solve();
    }
    return 0;
}
