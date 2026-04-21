#pragma once

#include <bitset>
#include <cstddef>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

template<std::size_t N> class Sudoku;


// defines a NxN Sudoku
template<std::size_t N>
class Sudoku 
{

private:
    std::string SYMBOLS="_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::array<std::array<unsigned int, N>, N> field;
    std::array<std::bitset<N>, N> rows;
    std::array<std::bitset<N>, N> cols;
    std::array<std::bitset<N>, N> blks;

    template<std::size_t M>
    friend std::ostream& operator<<(std::ostream& stream, const Sudoku<M>&);

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

    char get(std::size_t row, std::size_t col)
    {
        return SYMBOLS[field[row][col]];
    }

    bool set(std::size_t row, std::size_t col, char value)
    {
        // auto i = std::find(SYMBOLS.begin(), SYMBOLS.end(), value);
        // if (i == SYMBOLS.end()) 
        // {
        //     return false;
        // }
        // int index = i - SYMBOLS.begin();

        if (row >= N || col >= N) 
        {
            return false;
        }

        std::size_t index =  SYMBOLS.find(value);
        if (index == std::string::npos || index >= N) 

        {
            return false;
        }

        remove_previous_element(row, col);

        if (index == 0)
        {
            field[row][col] = 0;
            return true;
        }

        if (!check_rules(row, col, index)) 
        {
            std::size_t old = field[row][col];
            if(old != 0){
                rows[row].reset(old - 1);
                cols[col].reset(old - 1);
                blks[calculate_block(row, col)].reset(old - 1);
            }
         

            return false;
        }

        field[row][col] = index;
        rows[row].set(index - 1);
        cols[col].set(index - 1);
        blks[calculate_block(row, col)].set(index - 1);
        return true;
    }
    // get the row and col of the next placeholder in the soduku
    // get (N,N) when the sudoku is fully solved 
    // HOMEWORK till 24.06.26

    std::pair<std::size_t, std::size_t> next()
    {
        std::pair<int,int> pair;
        
    };

private:
    int calculate_block(std::size_t row, std::size_t col) 
    {
        std::size_t block_size = sqrt(N);
        return (row / block_size) * block_size + (col / block_size);
    }

    bool check_rules(std::size_t row, std::size_t col, int index) 
    {
        // is index in this row
        /*std::bitset<N> row = rows[row];
        if (row[index])
        {
            return false;
        }/
        // is index in this column
        /std::bitset<N> col = cols[col];
        if (col[index])
        {
            return false;
        }/
        // is index in this block
        /std::bitset<N> blk = blks[calculateblock(row, col)];
        if (blk[index])
        {
            return false;
        }*/

        // is better to combine the three bitsets and check if the index is set in any of them
        // this way we only need to check one bitset instead of three
        std::bitset<N> result = rows[row] | cols[col] | blks[calculate_block(row, col)];
        return !result[index - 1];
    }

    void remove_previous_element(std::size_t row, std::size_t col)
    {
        std::size_t index = field[row][col];

        if (index == 0)
        {
            return;
        }

        rows[row].reset(index - 1);
        cols[col].reset(index - 1);
        blks[calculate_block(row, col)].reset(index - 1);

    }

};
template<std::size_t N>
std::ostream& operator<<(std::ostream& stream, const Sudoku<N>& sudoku)
{
     for (auto& row : sudoku.field) 
        {
            for (auto& cell : row) 
            {
                stream << sudoku.SYMBOLS[cell] << " ";
            }
            stream << "\n";
        }
    return stream;
}
template<std::size_t N>
std::istream& operator>>(std::istream& stream, Sudoku<N>& sudoku)
{
for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N; col++)
        {
            char value;
            stream >> value;
            if(!sudoku.set(row, col, value))
            {
                stream.setstate(std::ios::failbit);
                return stream;
            } 
        }
    }
    return stream;
}
