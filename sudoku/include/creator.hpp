#pragma once

#include "sudoku.hpp"
#include <filesystem>

class Creator {
public:
  Sudoku<9> create(int holes);

private:
  bool loadFromFile(Sudoku<9> &s, std::filesystem::path p);
};