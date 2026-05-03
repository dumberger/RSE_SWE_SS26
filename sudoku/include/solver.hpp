#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver {
public:
    std::size_t solve();
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);

    // Added a method that mutes the .txt-generation of solutions
    void mute_solver(bool is_muted) { silent = is_muted; }
    // Added a number of targeted solutions (Default 1000, Crashes possible with high solution-numbers!)
    unsigned int target_solutions = 1000;

private:
    Sudoku<9> sudoku;
    int solutions = 0;
    // Added silent for muting
    bool silent = false;

    std::filesystem::path base_directory;
    
    bool solve_cell();
    void write_solution();
};