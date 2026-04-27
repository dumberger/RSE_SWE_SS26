#pragma once
#include <filesystem>
#include "sudoku.hpp"
class Solver {
public:
    bool solve();
    bool loadSudoku(const std::filesystem::path& file);
    bool loadSudoku(const Sudoku<9> reference, const std::filesystem::path& base_path);


private:
    Sudoku<9> sudoku;
    int solutions = 0;
    bool solve_cell();
    void write_solution(const std::filesystem::path& file);
    std::pair<std::size_t, std::size_t> next() {
        return sudoku.next();
    }


   
};