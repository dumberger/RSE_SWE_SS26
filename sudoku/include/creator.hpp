#pragma once

#include "sudoku.hpp"
#include <array>
#include <filesystem>
#include <random>

class Creator {
public:
  bool setupFromTemplate(std::filesystem::path path);
  bool setupFromReference(const Sudoku<9> &ref,
                          std::filesystem::path output_path);
  Sudoku<9> &getGrid() { return grid; }

  void build();

private:
  Sudoku<9> grid;
  std::filesystem::path work_dir;
  std::mt19937 prng{std::random_device{}()};

  // Interne Logik
  void generateBasics();
  bool tryFill(std::array<int, 9> &nums);
  void removeNumbers();
  void saveResult();
};