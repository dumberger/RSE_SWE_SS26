#include "solver.hpp"
#include "sudoku.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>

//TODO: do dat later
bool Solver::solve() { 
    return solve_cell();
}
bool Solver::loadSudoku(std::filesystem::path file){
    if(!std::filesystem::exists(file))
    {
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    if(input.good())
    {
        
        base_directory = file.parent_path();
        std::filesystem::create_directory(base_directory/"results");
    }

    return input.good();
}

bool Solver::loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path){
    sudoku = reference;
    base_directory = base_path;
    solutions=0;
    return true;
}



bool Solver::solve_cell() {
    if (solutions >= 2) return true; 
    
    auto [row, col] = sudoku.next();

    if (row == 9 || col == 9) {
        write_solution();
        solutions++;
        return false;
    }
    for (int i = 0; i < 9; i++) {
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col,symbol);
        if (valid) {
            if(solve_cell()){
                return true;
            }
            sudoku.set(row, col, sudoku.SYMBOLS[0]);
        }
    }
    return false;

}

void Solver::write_solution(){
    std::stringstream solution_name;
    solution_name << "results/" << solutions << ".txt";
    std::ofstream file(base_directory / solution_name.str());
    file << sudoku <<std::endl;
}