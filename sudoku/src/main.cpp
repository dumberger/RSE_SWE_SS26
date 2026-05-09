#include "solver.hpp"
#include "generator.hpp"

using namespace std;

int main() {

    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    // Generate a 9x9 Sudoku
    Generator generator;
    generator.generate();
    generator.saveSudoku(directory / "input.txt");
    
    // Solve the generated 9x9 Sudoku
    Solver solver;
    if(solver.loadSudoku(directory / "input.txt"))
    {
        solver.solve();
    }

    return 0;
}