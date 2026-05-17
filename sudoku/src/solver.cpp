#include "solver.hpp"

#include <filesystem>
#include <fstream>

std::size_t Solver::solve() {
    solutions = 0;
    solve_cell();
    return solutions;
}

bool Solver::loadSudoku(std::filesystem::path file) { 
    if(!std::filesystem::exists(file)) {
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    if (input.good()) {
        base_directory = file.parent_path();
        std::filesystem::create_directory(base_directory / "results");
        return true;
    }
    return false;
 }

bool Solver::loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path)
{
    sudoku = reference;
    base_directory = base_path;
    return true;
}

bool Solver::solve_cell() {
    if (solutions >= static_cast<int>(target_solutions)) {
        return true;
    }

    auto [row, col] = sudoku.next();
    if(row == 9 && col == 9) {
        write_solution();
        solutions++;
        return solutions >= static_cast<int>(target_solutions);
    }
    for (int i = 0; i < 9; i++) {
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col, symbol);
        if(valid) {
            if (solve_cell()) {
                return true;
            }
            sudoku.set(row, col, sudoku.SYMBOLS[0]);
            if (solutions >= static_cast<int>(target_solutions)) {
                return true;
            }
        }
    }
    return false;
}
void Solver::write_solution() {
    std::stringstream solution_name;
    solution_name << "results/" << solutions << ".txt";
    std::ofstream file(base_directory / solution_name.str());
    file << sudoku;
}