#pragma once

#include <cstddef>
#include <stdlib.h>
#include <array>
#include <string>

template<std::size_t N>
class Sudoku {
    public:
        Sudoku() 
        {
            for (auto& row : field) 
            {
                for (auto& cell : row) 
                {
                    cell = 0;
                }
            }
        }

        //~Sudoku() = default;

        bool set(std::size_t row, std::size_t col, char value);
        char get(std::size_t row, std::size_t col);

    private:
        std::array<std::array<unsigned int, N>, N> field;
        std::string SYMBOLS = "_123456789ABCDEFGHIJKLMNOQRSTUVWXYZ";
};