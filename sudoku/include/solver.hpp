#pragma once

#include <filesystem>
#include "sudoku.hpp"


class Solver{
    public:
        bool solve();
        bool loadSudoku(std::filesystem::path file);
        bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path);
        int solutions = 0;
    private:
        Sudoku<9> sudoku;
        
        std::filesystem::path base_directory;
        bool solve_cell();
        void write_solution();
};