#include "solver.hpp"
#include <filesystem>
#include <fstream>
#include <string>
#include <utility>

using std::string;

bool Solver::solve() {
  solve_cell();
  return solutions > 0;
}
bool Solver::loadSudoku(const std::filesystem::path& file) {
    if (!std::filesystem::exists(file)) {
        return false;
    }
    std::ifstream input(file);
    if (!(input >> sudoku)) {
        return false;
    }
    return true;
}



bool Solver::solve_cell() {
    const std::pair<std::size_t, std::size_t> next = sudoku.next();
    const std::size_t row = next.first;
    const std::size_t col = next.second;
    if (row == 9 && col == 9) {
        write_solution("solution.txt");
        solutions++;
        return false;
    }
    for (std::size_t i = 1; i <= 9; ++i) {
        char symbol = sudoku.SYMBOLS[i];
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


 bool Solver::loadSudoku(const Sudoku<9> reference, const std::filesystem::path& base_path){

    sudoku = reference;
    base_directory = base_Path;
    return true;
 }
void Solver::write_solution(const std::filesystem::path& file) {
    std::ofstream output(file);
    output << sudoku;
    std ::string solution_name = << "result_" / solution_name.str();
    std::ofstream(string("solution.txt")) << sudoku;
    std::cout << "Solution written to " << file << std::endl;
  



}