#pragma once

#include <array>
#include <cstddef>
#include <string>

//defines a NxN Sudoku
template<std::size_t N>

class Sudoku {
    
    private:
        std::array<std::array<unsigned int,N>, N> field;
        std::string SYMBOLS="_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public:
        Sudoku(){
            for(auto& row : field){
                for(auto& cell : row){
                    cell = 0;
                }
            }
        }

        //~Sudoku() = default;    
        bool set(std::size_t row, std::size_t col, char value);
        char get(std::size_t row, std::size_t col);
};