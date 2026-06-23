#include "solver.hpp"

#include <filesystem>
#include <fstream>
#include <optional>

std::optional<Sudoku<9>> Solver::loadThenSolve(const Sudoku<9>& reference) {
    this->sudoku = reference;
    solutions.clear();
    //return null wenn keine solution
    return solve_one();
}

std::size_t Solver::solve(int searchLimit, bool writeSolutions) {
    limit = searchLimit;
    solve_cell();
    if (writeSolutions) {
        for (int i = 0; i < solutions.size(); i++) {
            write_solution(i);
        }
    }
    return solutions.size();
}

std::optional<Sudoku<9>> Solver::solve_one() {
    if (solve(1, false) <= 0) {
        return std::nullopt;
    }
    return solutions[0];
}

bool Solver::setSudoku(const Sudoku<9>& reference)
{
    this->sudoku = reference;
    solutions.clear();
    return true;
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
        solutions.clear();
        return true;
    }
    return false;
 }

bool Solver::setSolutionFolder(std::filesystem::path base_path)
{
    base_directory = base_path;
    return std::filesystem::exists(base_directory);
}

bool Solver::solve_cell() {
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9) {
        solutions.push_back(sudoku);
        //write_solution();
        if (solutions.size() >= limit)
            return true;
        return false;
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

void Solver::write_solution(int i) {
    std::stringstream solution_name;
    solution_name << "results/solution_" << (i+1) << ".txt";
    std::ofstream file(base_directory / solution_name.str());
    file << solutions[i];
}
