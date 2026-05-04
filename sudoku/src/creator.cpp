#include "creator.hpp"
#include "sudoku.hpp"

#include <bitset>
#include <filesystem>
#include <fstream>
#include <random>

Creator::Creator(std::filesystem::path base)
    : base_directory(base), gen(rd()) {}

bool Creator::create(){
    fill_cell();
    return true;
}

bool Creator::fill_cell(){
    auto [row, col] = sudoku.next();
    if (row == 9 || col == 9) {
        write_sudoku(); // später hier Sudoku einträge teilweise löschen, je nach schwierigkeitsgrad und dann erst schreiben
        std::cout << sudoku << std::endl;
        return true;
    }
    std::bitset<9> non_available_Symbols;
    for (int i = 0; i < 9; i++) {
        char symbol = sudoku.SYMBOLS[i+1];
        bool valid = sudoku.set(row, col, symbol);
        if(!valid) {
            non_available_Symbols.set(i);
        }
    }
    while(!non_available_Symbols.all()){
        number = generate_random_number(non_available_Symbols.count(), non_available_Symbols);
        non_available_Symbols.set(number);
        sudoku.set(row, col, sudoku.SYMBOLS[number+1]);
        if(fill_cell()){
            return true;
        }
        
    }
    sudoku.set(row, col, sudoku.SYMBOLS[0]);
    return false;
}

int Creator::generate_random_number(int count, std::bitset<9>& bitset){
    int n = 0;
    int k = 0;
    std::uniform_int_distribution<>distrib(0, 8 - count);
    n = distrib(gen);
    for ( int i=0; i<9; i++ ){
        if(!bitset[i]){
            if(k == n){
            return i;
            }
            k++;
        }
        
    }
    return n;
}

void Creator::write_sudoku() {
    std::ofstream file(base_directory / "new_Sudokus/hello.txt");
    file << sudoku;
    std::cout << sudoku << std::endl;
}

bool Creator::trim_Sudoku(int difficulty){
    if(difficulty > 10 || difficulty < 1){
        std::cout << "Schwierigkeit wurde nicht im gegebenen Intervall angegeben!" << std::endl;
        return false;
    }
    int difficulty_score = 0;
    char value = 0;
    int row = 0;
    int col = 0;
    while(difficulty_score < difficulty*5){
        
        std::uniform_int_distribution<>distrib(0, 8);
        row = distrib(gen);
        col = distrib(gen);
        value = sudoku.get(row, col);
        if(value != '_'){
            
            if(sudoku.set(row,col,sudoku.SYMBOLS[0])){
                solver.solve(sudoku);
                if(solver.solutions == 1){
                difficulty_score++;
                
                    }
                else{
                sudoku.set(row,col,value);
                    } 
            };
        }
    }
    write_sudoku();
    return true;
}