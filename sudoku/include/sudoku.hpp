#pragma once

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <array>
#include <ios>
#include <ostream>
#include <string>
#include <iostream>
#include <utility>

// Defines a NxN Sudoku
template<std::size_t N>
class Sudoku 
{
private:
<<<<<<< KissEmil-RSE
    // Placeholder symbol is always the first symbol
    std::string SYMBOLS = "_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Sudoku-Arrays
=======
    // placeholder symbol is always the first symbol
    std::string SYMBOLS = "_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

>>>>>>> master
    std::array<std::array<unsigned int, N>, N> field;
    std::array<std::bitset<N>, N> rows;
    std::array<std::bitset<N>, N> cols;
    std::array<std::bitset<N>, N> blks;

<<<<<<< KissEmil-RSE
    // Printing out sudoku whole
=======
>>>>>>> master
    template<std::size_t M>
    friend std::ostream& operator<<(std::ostream&, Sudoku<M>&);

public:
    // Constructor
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

    // No Destructor 
    //~Sudoku() = default;

<<<<<<< KissEmil-RSE
// Returns the display char at given row and col
char get(std::size_t row, std::size_t col) { return SYMBOLS[field[row][col]]; }

// Places symbol at row and col
bool set(std::size_t row, std::size_t col, char value) 
{
    // Check bounds
    if (row >= N || col >= N) 
    {
        return false;
    }

    // Find symbol index in SYMBOLS string
    auto index = SYMBOLS.find(value);
    if(index == std::string::npos)
    {
        return false;
    }

    if(index > N)
    {
        return false;
    }

    // Clear previous value at this position from tracking bitsets
    remove_previous_element(row, col);

    // Index 0 is the placeholder '_', just clear the cell
    if(index == 0) 
    {
        field[row][col] = 0;
        return true;
    }

    // Reject if value already exists in same row, col, or block
    if(!check_rules(row, col, index))
    {
        // Restore the old value in the bitsets if cell was not empty
        std::size_t old_index = field[row][col];
        if(old_index == 0)
        {
            return false;
        }
        rows[row].set(old_index-1);
        cols[col].set(old_index-1);
        blks[calculate_block(row, col)].set(old_index-1);
        return false;
    }

    // Place the value and mark it as used in row, col, and block
    field[row][col] = index;
    rows[row].set(index-1);
    cols[col].set(index-1);
    blks[calculate_block(row, col)].set(index-1);
    return true;
}

private:
    // Returns the block index for row and col position
    int calculate_block(std::size_t row, std::size_t col)
    {
        std::size_t block_size = sqrt(N);
        return (row / block_size) * block_size + (col / block_size);
    }

    // Returns true when placing index at (row, col) violates no Sudoku rules
    bool check_rules(std::size_t row, std::size_t col, int index)
    {
        std::bitset<N> result = rows[row] | cols[col] | blks[calculate_block(row, col)];
        return !result[index-1];
    }

    // Removes the current value at row, col from the bitsets
=======
    char get(std::size_t row, std::size_t col) { return SYMBOLS[field[row][col]]; }

    bool set(std::size_t row, std::size_t col, char value) 
    {
        if (row >= N || col >= N) {
            return false;
        }
        /*auto i = std::find(SYMBOLS.begin(), SYMBOLS.end(), value);
        {
            return false;
        }
        int index = i - SYMBOLS.begin();*/
        auto index = SYMBOLS.find(value);
        if(index == std::string::npos)
        {
            return false;
        }
        if(index > N)
        {
            return false;
        }
        remove_previous_element(row, col);
        if(index == 0) 
        {
            field[row][col] = 0;
            return true;
        }
        if(!check_rules(row, col, index))
        {
            std::size_t old_index = field[row][col];
            if(old_index == 0)
            {
                return false;
            }
            rows[row].set(old_index-1);
            cols[col].set(old_index-1);
            blks[calculate_block(row, col)].set(old_index-1);
            return false;
        }
        field[row][col] = index;
        rows[row].set(index-1);
        cols[col].set(index-1);
        blks[calculate_block(row, col)].set(index-1);
        return true;
    }

    // get the row and col of the next placeholder in the sodoku
    // get (N,N) when the sudoku is fully solved
    std::pair<std::size_t, std::size_t> next();

private:
    int calculate_block(std::size_t row, std::size_t col)
    {
        std::size_t block_size = sqrt(N);
        // integer divisions will automatically be rounded down
        return (row / block_size) * block_size + (col / block_size);
    }

    bool check_rules(std::size_t row, std::size_t col, int index)
    {
        /*// is index in this line
        std::bitset<N> row_ = rows[row];
        if(row_[index]){
            return false;
        }
        // is index in this colomn
        std::bitset<N> col_ = cols[row];
        if(col_[index-1]){
            return false;
        }
        // is index in this block
        std::bitset<N> blk = blks[calculate_block(row, col)];
        if(blk[index-1]){
            return false;
        }
        return true;*/

        std::bitset<N> result = rows[row] | cols[col] | blks[calculate_block(row, col)];
        //std::cout << result.to_string() << std::endl;
        return !result[index-1];
    }

>>>>>>> master
    void remove_previous_element(std::size_t row, std::size_t col) {
        std::size_t index = field[row][col];
        if (index == 0) {
            return;
        }
        rows[row].reset(index - 1);
        cols[col].reset(index - 1);
<<<<<<< KissEmil-RSE
        blks[calculate_block(row, col)].reset(index - 1);
    }
};

// Printing out sudoku automatically
=======
        blks[calculate_block(row, col)].reset(index -1);
    }
};

>>>>>>> master
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

<<<<<<< KissEmil-RSE
// Reading in sudoku automatically
=======
>>>>>>> master
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
<<<<<<< KissEmil-RSE
}
=======
}
>>>>>>> master
