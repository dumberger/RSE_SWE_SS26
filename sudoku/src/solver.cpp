# include "solver.hpp"
# include <filesystem>
# include <fstream>

// ToDo:
bool Solver::solve() {
    solve_cell();
    return solutions > 0;
}


bool Solver::LoadSudoku(std::filesystem::path path) {
    if (!std::filesystem::exists(path)) {
        return false;
    }
    std::ifstream input(path);
    input >> sudoku;
    if(input.good()){
        base_dir = path.parent_path();
        return true;
    }
    return false;
}

bool Solver::LoadSudoku(const Sudoku<9>& reference, std::filesystem::path path){
    sudoku = reference;
    base_dir = path.parent_path();
    return true;
}


bool Solver::solve_cell() {
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9){
        write_solution();
        solutions++;
        return false; // if on true -> first solution
    }

    for (int i = 0; i < 9; i++){
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col, symbol);
        if (valid){
            if (solve_cell()){ // jede schelife rekursiv, jede rekursion kann schleife sein
                return true;
            }
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