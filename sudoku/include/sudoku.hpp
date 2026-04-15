#pragma once

#include <cstddef>
#include <array>
#include <string>

// defines a NxN Sudoku
template<std::size_t N> 
// std::size_t is always a positive integer
// std::size_t always takes note which bit width the operating system uses (for example 32 bit -> uint32_t or 64 bit -> uint62_t)
// this is useful, because if I don't know the length/size of the for my sudoku (can be 4x4, 9x9, 16x16, etc.) I can use std::size_t
class Sudoku {
private:
    std::array<std::array<unsigned int, N>, N> field;
    // is like int field[N][N] but with the advantage that we can use the functions of the array class
    // for example to get the size of the array with field.size() and field[0].size() 
    std::string SYMBOLS="_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Dictionary for the symbols used in the sudoku, where the index of the symbol corresponds to its value (for example SYMBOLS[1] = '1', SYMBOLS[10] = 'A', etc.)
    // is also limit for the playable size. Everything till z. So N can be maximum 37
public:
    Sudoku() {
        // old style ->
        // for (int i = 0; i < field.size(); i++) {
        //     auto& row = field[i]; 
        //     // ... working with row
        // }      
        // new style ->
        for (auto& row : field) {
            for (auto& cell : row) {
                cell = 0;
            }
        }

        // creates a field with all cells initialized to 0
    }

    //~Sudoku() = default;


    bool set(std::size_t row, std::size_t col, char value);
    // {
    //     // check if the value is valid (for example, if it's a digit between 1 and N or a symbol from the SYMBOLS string)
    //     // check if the value is already present in the same row, column or subgrid
    //     // if all checks pass, set the value in the field and return true, otherwise return false

    //     auto pos = SYMBOLS.find(value);

    //     if (pos == std::string::npos)
    //         return false;
    //     if (((row >= N) and (row < 0)) or ((col >= N) and (col < 0)))
    //         return false;
    //     return true;
    // }
    
    char get(std::size_t row, std::size_t col);
    // {
    //     // return the value at the specified position in the field, for example by converting the integer value to the corresponding symbol using the SYMBOLS string
    //     char symbol = SYMBOLS[field[row][col]];
    //     printf("%c ", symbol);
    //     return symbol;
    // }
};