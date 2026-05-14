#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>

class Solver 
{
public:
    std::size_t solve(bool saveSolutions = false);
    bool loadSudoku(std::filesystem::path file);
    bool loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path = {});
    const Sudoku<9>& getFirstSolution() const;
private:
    Sudoku<9> sudoku;
    Sudoku<9> solvedSudoku;
    int solutions = 0;
    std::filesystem::path base_directory;
    bool solve_cell();
    void write_solution();
    bool m_saveSolutions;
};