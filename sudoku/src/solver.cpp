#include "solver.hpp"
#include "sudoku.hpp"

#include <fstream>


//todo 
bool Solver::solve() { return true; };

bool Solver::loadSudoku(std::filesystem::path file) {
    if (!std::filesystem::exists(file)) {
        return false;
    }
    std::ifstream input(file);
    input>>sudoku;
    return input.good();
};

bool Solver::solve_cell() { 
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9 ) {
        return true;
    }
    for (int i = 0; i < 9; i++) {
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
};