#pragma once

#include "sudoku.hpp"
#include <filesystem>

class Solver {
public:
    bool solve();
    bool loadSudoku(std::filesystem::path file);
private:
    Sudoku<9> sudoku;
    bool solve_cell();
    void write_solution();
};