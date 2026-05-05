#pragma once

#include "sudoku.hpp"

#include <filesystem>
#include <random>
#include <utility>

class Generator {
private:
    Sudoku<9> sudoku;
    std::mt19937 rng;

    char symbol_random();
    bool has_empty_cell();
    std::pair<std::size_t, std::size_t> empty_cell_random();
    bool one_solution_only(std::filesystem::path path_directory);

public:
    Generator();
    Sudoku<9> generateSudoku(std::filesystem::path path_directory);
};