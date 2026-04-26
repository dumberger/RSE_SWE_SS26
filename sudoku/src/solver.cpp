#include "solver.hpp"

#include <fstream>
#include <sstream>

std::size_t Solver::solve() {
    solve_cell();
    return solutions;
}

bool Solver::loadSudoku(std::filesystem::path file) { 
    if(!std::filesystem::exists(file)) {
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    return input.good();
 }

bool Solver::solve_cell() {
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9) {
        write_solution();
        solutions ++;
        return false;
        //return true; // erste Lösung
    }
    for (int i = 0; i < 9; i++) {
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col, symbol);
        if(valid) {
            if (solve_cell()) {
                return true;
            }
            sudoku.set(row, col, sudoku.SYMBOLS[0]);
        }
    }
    return false;
}

void Solver::write_solution() {
    std::stringstream solution_name;
    solution_name << "results/"<<solutions <<".txt";
    std::ofstream file(solution_name.str());
    std::cout << sudoku << "\n\n" << std::endl;
}