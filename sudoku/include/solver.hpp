#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver {
public:
    std::size_t solve();
    bool loadSudoku(std::filesystem::path file);
private:
    Sudoku<9> sudoku;
    int solutions = 0;
    bool solve_cell();
    void write_solution();
};