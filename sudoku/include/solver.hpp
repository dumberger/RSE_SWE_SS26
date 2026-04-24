#pragma once

#include "sudoku.hpp"

class Solver {
public:
    bool solve();
    bool loadSudoku(std::filesystem::path sudoku_path);
private:
    Sudoku<9> sudoku;
    bool solve_cell();
    void write_solution();
};