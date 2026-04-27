#pragma once

#include "sudoku.hpp"
#include <filesystem>
#include <random>

class Generator {
public:
    bool generateSudoku(std::filesystem::path file, int prefilled, std::mt19937& random);
private:
    Sudoku<9> sudoku;
    std::filesystem::path file_path;

    void seed_sudoku(std::mt19937& random);
};
