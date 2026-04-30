#pragma once
#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver{
public:
    std::size_t solve();
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path file);

private:
    Sudoku<9> sudoku;
    int solutions = 0;
    std::filesystem::path base_directory;
    bool solve_cell();
    void write_solution();
};