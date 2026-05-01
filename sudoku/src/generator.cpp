#include "generator.hpp"
#include <random>
#include "solver.hpp"
#include <fstream>


bool Generator::LoadSudoku(const Sudoku<9>& reference, std::filesystem::path path){
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

bool Generator::GenerateSudoku(){

    auto [row, col] = sudoku.next();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 9);

    for (int i = 0; i < 9; i++){
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col, symbol);
        if (valid){
            if (GenerateSudoku()){ 
                return true;
            }
            sudoku.set(row, col, sudoku.SYMBOLS[0]);
        }
    }
    return true;
}

