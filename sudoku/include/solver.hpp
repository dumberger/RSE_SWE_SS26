# pragma once

#include <sudoku.hpp>
#include <filesystem>

class Solver{
    public:
        std::size_t solve(bool mode);
        bool LoadSudoku(std::filesystem::path);
        bool LoadSudoku(const Sudoku<9>& reference, std::filesystem::path);

        Sudoku<9>& getSudoku() { return sudoku; }
        Sudoku<9>& setSudoku(const Sudoku<9>& sudoku_to_solve) { sudoku = sudoku_to_solve; return sudoku;}

    private:
        Sudoku<9> sudoku;
        int solutions = 0;
        std::filesystem::path base_dir;
        bool solve_cell(bool mode);
        void write_solution();
};