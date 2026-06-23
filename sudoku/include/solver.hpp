#pragma once

#include "sudoku.hpp"
#include <cstddef>
#include <filesystem>
#include <optional>
#include <vector>

class Solver {
public:
    std::optional<Sudoku<9>> loadThenSolve(const Sudoku<9>& reference);
    std::size_t solve(int searchLimit, bool writeSolutions = false);
    std::optional<Sudoku<9>> solve_one();
    bool setSudoku(const Sudoku<9>& reference);
    bool loadSudoku(std::filesystem::path file);
    bool setSolutionFolder(std::filesystem::path base_path);
private:
    Sudoku<9> sudoku;
    std::vector<Sudoku<9>> solutions;
    int limit = -1;
    std::filesystem::path base_directory;
    bool solve_cell();
    void write_solution(int i);
};
