#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver {
public:
    std::size_t solve(const Sudoku<9> Sudoku);
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);
    int solutions = 0;
private:
    Sudoku<9> sudoku;
    
    std::filesystem::path base_directory;
    bool solve_cell();
    void write_solution();
};