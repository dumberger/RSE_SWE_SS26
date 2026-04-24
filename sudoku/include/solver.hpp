#pragma once

#include "sudoku.hpp"

class Solver {
public:
    bool solve();
    bool loadSudoku(Sudoku<9> & sudoku);
private:
    Sudoku<9> sudoku;
    bool solve_cell();
};