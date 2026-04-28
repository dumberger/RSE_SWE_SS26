#include "solver.hpp"
#include <fstream>

bool Solver::solve(){ 
    solve_cell();
    return solutions > 0;
}

bool Solver::loadSudoku(std::filesystem::path file){
    if(!std::filesystem::exists(file)){
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    if(input.good()){
        base_directory = file.parent_path();

    }
    return input.good();
}
bool Solver::loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path){
    sudoku = reference;
    base_directory = base_path;
    return true;
}

bool Solver::solve_cell(){
    auto [row, col] = sudoku.next();
    if(row == 9 ||col == 9){
        write_solution();
        solutions++;
        return false;
    }
    for(int i = 0; i < 9; i++){
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row,col,symbol);
        if(valid){
            if (solve_cell()){
                return true;
            }
            sudoku.set(row, col, sudoku.SYMBOLS[0]);
        }
    }
    return false;
}
void Solver::write_solution(){
    std::stringstream solutions_name;
    solutions_name << "results/" << solutions << ".txt";
    std::ofstream file(base_directory/solutions_name.str());
    std::cout << sudoku << std::endl;
}
