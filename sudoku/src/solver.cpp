#include "solver.hpp"

#include <fstream>

bool Solver::solve() {
    solve_cell();
    return solutions > 0;
}
bool Solver::loadSudoku(std::filesystem::path sudoku_path) {
    if (!std::filesystem::exists(sudoku_path)) {
        return false;
    }
    printf(sudoku_path.string().c_str());
    //read from input file
    std::ifstream input(sudoku_path);
    input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    input >> sudoku;
    //if no good print
    if(!input.good())
    {
        std::cout << "error reading input.txt file\n";
        return false;
    }
    base_directory = sudoku_path.parent_path();
    return true;
 }

bool Solver::solve_cell() {
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9) {
        write_solution();
        solutions++;
        return false;
    }
    for (int i = 0 ; i < 9 ; i++) {
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col, symbol);
        if (valid) {
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
    solution_name << "results/" << solutions << ".txt";
    std::ofstream file(base_directory / solution_name.str());
    printf((base_directory.string() + "/" + solution_name.str()).c_str());
    file << sudoku << "\n\n" << std::endl;
    std::cout << sudoku << "\n\n" << std::endl;
}
