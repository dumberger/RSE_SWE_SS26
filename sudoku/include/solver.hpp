#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver {
public:
    std::size_t solve();
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);
    Sudoku<9> getSudoku() { return sudoku; }

    void mute_solver(bool mute) { muted = mute; }
    unsigned int target_solutions = 1;

private:
    Sudoku<9> sudoku;
    int solutions = 0;
     // muted for muting
    bool muted = false;
    std::filesystem::path base_directory;
    bool solve_cell();
    void write_solution();
};