#pragma once
#include <array>
#include <cstddef>
#include <string>

// _123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ

// defines a NxN Sudoku
template <std::size_t N>
class Sudoku{
private:
    
    std::array<std::array<unsigned int,N>,N> field;
    std::string SYMBOLS = "_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    Sudoku() {
        for(auto& row:field){
            for(auto& cell: row){
                cell = 0;

            }
        }
    }

    ///~Sudoku() = default;

    bool set(std::size_t row, std::size_t col, unsigned int cell, char value);
    char get(std::size_t row, std::size_t col);

};