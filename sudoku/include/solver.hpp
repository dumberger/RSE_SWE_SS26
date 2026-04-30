#pragma once

#include "sudoku.hpp"
#include <filesystem>
#include <fstream>

class Solver {

public:
    bool solve();
    bool loadSudoku();

private:
    Sudoku<9> sudoku;
    bool solve_cell();
};