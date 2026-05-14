# pragma once

#include <sudoku.hpp>
#include <filesystem>
#include <random>

class Generator{
    public:
    Generator();
    bool GenerateSudoku();
    Sudoku<9>& getSudoku() { return sudoku; }
    bool LoadSudoku(const Sudoku<9>& reference, std::filesystem::path path);

private:
    Sudoku<9> sudoku;
    std::mt19937 gen;
    std::filesystem::path base_dir;
    bool fillRecursive(); 
};