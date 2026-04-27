# pragma once

#include "sudoku.hpp"
#include <filesystem>
#include <random>

class Creator
{
public:
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);

    void create();

private:
    Sudoku<9> sudoku;
    std::filesystem::path base_directory;

    void fill_randomly();
    bool fill_cell_valid(std::mt19937& rng, std::array<int,9>& order);
    void erode_sudoku();

    void write_creation();
};