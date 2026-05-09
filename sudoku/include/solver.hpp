#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver {
public:
  std::size_t solve();
  bool loadSudoku(std::filesystem::path file);
  bool loadSudoku(const Sudoku<9> &reference, std::filesystem::path base_path);
  Sudoku<9> &getSudoku() { return sudoku; }
  const Sudoku<9> &getSolution() const { return solution_grid; }

private:
  Sudoku<9> sudoku;
  Sudoku<9> solution_grid;
  int solutions = 0;
  std::filesystem::path base_directory;
  bool solve_cell();
  void write_solution();
};