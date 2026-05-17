#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver {
public:
    std::size_t solve();
    std::size_t solve(bool just_one);
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);
    Sudoku<9> getSudoku();

    private:
    Sudoku<9> sudoku;
    int solutions = 0;
    std::filesystem::path base_directory;
    bool solve_cell(bool just_one);
    void write_solution();
};