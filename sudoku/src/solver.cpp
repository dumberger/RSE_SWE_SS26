#include "solver.hpp"

#include <filesystem>
#include <fstream>

std::size_t Solver::solve() {
    solutions = 0;
    solve_cell();
    return solutions;
}

bool Solver::LoadSudoku(std::filesystem::path file) { 
    if(!std::filesystem::exists(file)) {
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    if (input.good()) {
        base_dir = file.parent_path();
        std::filesystem::create_directory(base_dir / "results");
        return true;
    }
    return false;
 }

bool Solver::LoadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path)
{
    sudoku = reference;
    base_dir = base_path;
    return true;
}

bool Solver::solve_cell() {
    if (solutions > 1) {
        return false; 
    }

    auto [row, col] = sudoku.next();

    if (row == 9 || col == 9) {
        write_solution();
        solutions++;
        return true; // if on true -> first solution
    }
    for (int i = 0; i < 9; i++) {
        char symbol = sudoku.SYMBOLS[i+1];
        if(sudoku.set(row, col, symbol)) {
            solve_cell();

            if (solutions > 1) break;
            // if (solve_cell()) { // jede schelife rekursiv, jede rekursion kann schleife sein
            //     return true;
            // }
            sudoku.set(row, col, sudoku.SYMBOLS[0]);
        }
    }
    return false;
}

void Solver::write_solution() {
    auto output_path = base_dir / ".." / "solutions" / ("solution_" + std::to_string(solutions) + ".txt");
    std::ofstream output(output_path);
    output << sudoku;
}