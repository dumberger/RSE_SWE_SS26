# pragma once

#include <sudoku.hpp>
#include <filesystem>

class Solver{
    public:
        bool solve();
        bool LoadSudoku(std::filesystem::path);
        bool LoadSudoku(const Sudoku<9>& reference, std::filesystem::path);
    private:
        Sudoku<9> sudoku;
        int solutions = 0;
        std::filesystem::path base_dir;
        bool solve_cell();
        void write_solution();
};