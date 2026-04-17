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

        bool set(std::size_t row, std::size_t col, char value)
        {
            /*
            auto i = std::find(SYMBOLS.begin(), SYMBOLS.end(), value);
            if (i == SYMBOLS.end())
            {
                 return false;
            }
            
            int index = i - SYMBOLS.begin();
            */

            auto index = SYMBOLS.find(value);

            if(index == std::string::npos)
            {
                return false;
            }
            if(index > N)
            {
                return false;
            }
            if(!check_rules(row, col, index))
            {
                return false;
            }

            field[row][col] = index;
            rows[row].set(index-1);
            cols[col].set(index-1);
            blks[calculate_block(row, col)].set(index-1);
            return true;
        }

        char get(std::size_t row, std::size_t col) { return SYMBOLS[field[row][col]]};

    private:
        std::array<std::array<unsigned int, N>, N> field;
        std::array<std::bitset<N>, N> rows;
        std::array<std::bitset<N>, N> cols;
        std::array<std::bitset<N>, N> blks;
        std::string SYMBOLS = "_123456789ABCDEFGHIJKLMNOQRSTUVWXYZ";

        int calculate_block(std::size_t row, std::size_t col)
        {
            std::size_t block_size = sqrt(N);
            // integer divisions will automatically be rounded down
            return (row / block_size) * block_size+ (col / block_size);
        }

        bool check_rules(std::size_t row, std::size_t col, int index)
        {
            std::bitset<N> result = rows[row] | cols[col] | blks[calculate_block(row, col)];
            std::cout << result.to_string() << std::endl;
            return !result[index];
        }
};