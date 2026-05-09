#pragma once

#include <filesystem>
#include "sudoku.hpp"

class Solver
{
  public:
    std::size_t solve();
    std::size_t solve_for_ui();
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);
    Sudoku<9> getSudoku() const { return sudoku; };
  private:
    Sudoku<9> sudoku;
    int solutions = 0;
    std::filesystem::path base_directory;
    bool solve_cell();
    bool solve_cell_keep_solution();
    void write_solution();
};