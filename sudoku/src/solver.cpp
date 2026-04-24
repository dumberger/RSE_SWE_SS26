#include <fstream>
#include <filesystem>
#include "solver.hpp"
#include "sudoku.hpp"

bool Solver::solve() {
    return solve_cell();
}
bool Solver::loadSudoku(std::filesystem::path sudoku_path) {
    if (!std::filesystem::exists(sudoku_path)) {
        return false;
    }
    //read from input file
    std::ifstream input(sudoku_path);
    input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    //if no good print
    if(!input.good())
    {
        std::cout << "error reading input.txt file\n";
        return false;
    }
    input >> sudoku;
    return true;
 }

bool Solver::solve_cell() {
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9) {
        write_solution();
        return true;
    }
    for (int i = 0 ; i < 9 ; i++) {
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col, symbol);
        if (valid) {
            if (solve_cell()) {
                return true;
            }
            sudoku.set(row, col, sudoku.SYMBOLS[0]);
        }
    }
    return false;
}

void Solver::write_solution() {
    std::cout << sudoku << std::endl;
}