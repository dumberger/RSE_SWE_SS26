#include "solver.hpp"
#include "creator.hpp"

#include <cstdlib>

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    Creator creator;
    // load template format
    if(creator.loadSudoku(directory / "template.txt"))
    {
        // Create sudoku with parameters
        creator.create();
    }
    
    Solver solver;
    // solve created sudoku
    // input.txt                for predefined soduko-grid
    // random_generated.txt     for randomly generated soduko-grid
    std::string is_to_solve = "random_generated.txt";
    if(solver.loadSudoku(directory / is_to_solve))
    {
        // Since Solver is used in Creator this would only produce a second file 1.txt with the same solution
        // solver.solve();
    }
    return 0;
}