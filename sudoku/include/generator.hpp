#pragma once
#include "sudoku.hpp"
#include <filesystem>

class Generator{
public:
    bool generate();
    Sudoku<9> getSudoku();
private:
    std::filesystem::path base_directory;
    Sudoku<9> sudoku;
    void writeGeneratedSudoku();
    std::pair<std::size_t, std::size_t> next();
    void prefillSudoku();
};
