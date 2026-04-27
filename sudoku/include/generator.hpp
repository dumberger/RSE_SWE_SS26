#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>
#include <random>

class Generator {
public:
    Generator ();
    bool generateSudoku(std::filesystem::path file, int prefilled = 30);
private:
    Sudoku<9> sudoku;
    std::mt19937 rng;
    std::filesystem::path base_directory;

    bool remove_cell();
    void write_suduko();
};
