#include "solver.hpp"
#include "generator.hpp"

#include <cstdlib>
#include <random>
#include <fstream>

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
    // Generate a random sudoku puzzle with unique solution
    Generator generator;
    Sudoku<9> puzzle = generator.generate();
    
    std::cout << "Generated Sudoku Puzzle:\n" << puzzle << std::endl;
    
    // Save the generated puzzle to input.txt
    std::ofstream input_file(directory / "input.txt");
    input_file << puzzle;
    input_file.close();
    std::cout << "\nSudoku saved to input.txt\n";
    
    // Solve the generated puzzle
    Solver solver;
    solver.loadSudoku(puzzle, directory);
    std::cout << "Solving...\n";
    solver.solve();
    std::cout << "Solution saved to results/0.txt\n";
    
    return 0;
}