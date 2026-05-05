#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver {
public:
    std::size_t solve(bool write_files = true); //gegen viele Dateien
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);
private:
    Sudoku<9> sudoku;
    int solutions = 0;
    bool write_files_enabled = true; //gegen viele Dateien
    std::filesystem::path base_directory;
    bool solve_cell();
    void write_solution();
};