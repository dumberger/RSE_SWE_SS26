#pragma once

// clang inlay toggle -> turn off/on hints

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <array>
#include <cstdio>
#include <ostream>
#include <string>
#include <bitset>
#include <iostream>
#include <utility>

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
    std::array<std::bitset<N>, N> rows;
    std::array<std::bitset<N>, N> cols;
    std::array<std::bitset<N>, N> blks;
    template<std::size_t M>
    friend std::ostream& operator<<(std::ostream&, Sudoku<M>&);
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

        // creates a field with all cells initialized to 0 (which is _)
    }

    //~Sudoku() = default;


    bool set(std::size_t row, std::size_t col, char value)
    {
        // check if the value is valid (for example, if it's a digit between 1 and N or a symbol from the SYMBOLS string)
        // check if the value is already present in the same row, column or subgrid
        // if all checks pass, set the value in the field and return true, otherwise return false

        // auto pos = std::find(SYMBOLS.begin(), SYMBOLS.end(), value); is universal -> if symbols were int it would still work
        // {
        //     return false;
        // }
        // int index = pos - SYMBOLS.begin();
        if (row >= N || col >= N) {
            return false;
        }
        value = toupper(value);
        auto index = SYMBOLS.find(value);
        if(index == std::string::npos)
        {
            return false;
        }
        if(index > N)
        {
            return false;
        }
        remove_prev(row, col);
        if(index == 0) 
        {
            field[row][col] = 0;
            return true;
        }
        if(!is_valid(row, col, index))
        {
            std::size_t old_index = field[row][col];
            if(old_index == 0)
            {
                return false;
            }
            rows[row].set(old_index-1);
            cols[col].set(old_index-1);
            blks[calc_block(row, col)].set(old_index-1);
            return false;
        }
        field[row][col] = index;
        rows[row].set(index-1);
        cols[col].set(index-1);
        blks[calc_block(row, col)].set(index-1);
        return true;
    }

    // get the row and col of the next 
    // get [N, N] when the sudoku is fully 
    
    std::pair<std::size_t, std::size_t> next()
    {
        for (std::size_t r = 0; r < N; ++r) {
            for (std::size_t c = 0; c < N; ++c) {
                if (field[r][c] == 0) { 
                    std::cout << r << " "<< c << '\n';
                    return {r, c}; 
                }
            }
        }
        return {N, N};  // if there is no free spaces
    }


    char get(std::size_t row, std::size_t col)
    {
        // return the value at the specified position in the field, for example by converting the integer value to the corresponding symbol using the SYMBOLS string
        char symbol = SYMBOLS[field[row][col]];
        return symbol;
    }
private:
    int calc_block(std::size_t row, std::size_t col)
    {
        std::size_t block_size = sqrt(N);
        return (row / block_size) * block_size + (col / block_size); 
        // rounded by a module with floor -> like %, but integer divisions will automatically be rounded down
        // so no floor
    }

    bool is_valid(std::size_t row, std::size_t col, int index)
    {
        // std::bitset<N> _row = rows[row];
        // if (_row[index]){
        //     return false;
        // }

        // either do this 3 times or just use code below
        
        std::bitset<N> result = rows[row] | cols[col] | blks[calc_block(row, col)];
        //std::cout << result.to_string() << std::endl;
        return !result[index - 1];
    }

    void remove_prev (std::size_t row, std::size_t col)
    {
        std::size_t index = field[row][col];
        if (index == 0)
            return;
        rows[row].reset(index - 1);
        cols[col].reset(index - 1);
        blks[calc_block(row, col)].reset(index - 1);
    }
};

template<std::size_t N>
std::ostream& operator<<(std::ostream& stream, Sudoku<N>& sudoku) {
    for (auto& row : sudoku.field) {
            for (auto& cell : row) {
                stream << sudoku.SYMBOLS[cell] << " ";
            }
            stream << "\n";
        }
    return stream;
}

template<std::size_t N>
std::istream& operator>>(std::istream& stream, Sudoku<N>& sudoku) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
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