#include "solver.hpp"
#include "generator.hpp"

#include <cstdlib>
#include <random>

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
    Solver solver;
    //if(solver.loadSudoku(directory / "input.txt"))
    //{
    //    solver.solve();
    //}

    Generator generator;
    Sudoku<9> sudoku = generator.generateSudoku(directory);

    //std::cout << sudoku;
    std::cout << sudoku << std::endl;
    solver.loadSudoku(sudoku, directory);
    std::cout << "Solutions: " << solver.solve(true) << std::endl;

    return 0;
}

