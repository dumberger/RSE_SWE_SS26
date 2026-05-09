#include "solver.hpp"
#include "generator.hpp"

#include <cstdlib>

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    Generator generator;
    // load template format
    if(generator.loadSudoku(directory / "template.txt"))
    {
        // Create sudoku with parameters
        generator.generate();
    }
    
    Solver solver;
    // solve created sudoku
    // input.txt                for predefined soduko-grid
    // random_generated.txt     for randomly generated soduko-grid
    std::string is_to_solve = "random_generated.txt";
    if(solver.loadSudoku(directory / is_to_solve))
    {
        solver.solve();
    }
    return 0;
}