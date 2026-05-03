#pragma once

#include "sudoku.hpp"
#include <filesystem>
#include <random>

class Generator
{
public:
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);
    Sudoku<9> getSudoku() { return sudoku; }

    void generate();

private:
    Sudoku<9> sudoku;
    std::filesystem::path base_directory;

    void fill_random(std::mt19937& rng);
    void erode(std::mt19937& rng);
    void write_creation();
};