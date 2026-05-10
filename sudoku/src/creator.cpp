#include "creator.hpp"
#include "sudoku.hpp"
#include <cstddef>
#include <random>

Creator::Creator():
    gen(std::random_device{}()), //Zufallsgenerator
    dist_pos(0,8), //Bereich in dem "gewürfelt" wird
    dist_sym(1,9){} //Symbole von 1 bis 9

Sudoku<9> Creator::create(std::size_t max_attempts){
    Sudoku<9> board;
    for (std::size_t i = 0; i < max_attempts; ++i) {
        std::size_t row = dist_pos(gen); //zufällige Position in row
        std::size_t col = dist_pos(gen); //zufällige Position in col
        char symbol = Sudoku<9>::SYMBOLS[dist_sym(gen)]; //zufällige Zahl 
        board.set(row, col, symbol); //zufällige Zahl an der zufälligen Stelle setzen
    }
    
    return board;

}