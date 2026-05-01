# pragma once

#include <sudoku.hpp>
#include <filesystem>

class Generator{
    Sudoku<9> sudoku;
    std::filesystem::path base_dir;
    bool LoadSudoku(const Sudoku<9>& reference, std::filesystem::path);
    bool GenerateSudoku();
};