#include "solver.hpp"

#include <filesystem>
#include <fstream>

std::size_t Solver::solve(bool saveSolutions) {
    m_saveSolutions = saveSolutions;
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
        return true;
    }
    return false;
 }

bool Solver::loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path)
{
    sudoku = reference;

    base_directory = base_path.empty() ? std::filesystem::path(__FILE__).parent_path() : base_path;

    return true;
}

const Sudoku<9>& Solver::getFirstSolution() const
{
    return solvedSudoku;
}

bool Solver::solve_cell() {
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9) {
        solutions++;

        if (solutions == 1)
        {
            solvedSudoku = sudoku;
        }

        if (!m_saveSolutions && solutions > 1)
        {
            return true;  
        }

        if (m_saveSolutions)
        {
            write_solution();
        }

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

void Solver::write_solution() {
    std::filesystem::path results_path = base_directory / "results";
    std::filesystem::create_directories(results_path);

    std::stringstream solution_name;
    solution_name << solutions << ".txt";

    std::ofstream file(results_path / solution_name.str());
    file << sudoku;
}