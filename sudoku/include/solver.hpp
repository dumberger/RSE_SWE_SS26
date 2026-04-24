#pragma once

#include <filesystem>
#include "sudoku.hpp"

class Solver
{
  public:
    std::size_t solve();
    bool loadSudoku(std::filesystem::path file);
  private:
    Sudoku<9> sudoku;
    int solutions = 0;
    std::filesystem::path base_directory;
    bool solve_cell();
    void write_solution();
};