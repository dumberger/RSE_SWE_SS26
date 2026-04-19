#pragma once

#include <bitset>
#include <cstddef>
#include <array>
#include <ostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

// defines a NxN Sudoku
template<std::size_t N>
class Sudoku {
private:
    // placeholder symbol is always the first symbol
    std::string SYMBOLS = "_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::array<std::array<unsigned int, N>, N> field;
    std::array<std::bitset<N>, N> rows;
    std::array<std::bitset<N>, N> cols;
    std::array<std::bitset<N>, N> blks;

    template<std::size_t M>
    friend std::ostream& operator<<(std::ostream&, Sudoku<M>&);

public:
    Sudoku() {
        for (auto& row : field) {
            for (auto& cell : row) {
                cell = 0;
            }
        }
    }

    //~Sudoku() = default;

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

    //get the rowand col of the next placeholder
    // get(N,N) when  the sudoku is fullsoved
    std::pair<std::size_t, std::size_t> next()
    {
        //select the best the next cell to fill, the one with the least options
        std::size_t best_row = N;
        std::size_t best_col = N;
        std::size_t best_options = N+1;
        for (std::size_t row = 0; row < N; ++row) {
            for (std::size_t col = 0; col < N; ++col) {
                if (field[row][col] != 0) {
                    continue;
                }
                // count the number of valid options for this cell
                std::size_t options = 0;
                for (std::size_t i = 1; i <= N; ++i) {
                    if (check_rules(row, col, i)) {
                        ++options;
                    }
                }
                 //Optimalfall sofort zurück
                if (options == 0) {
                    return {row, col};
                }


                if (options < best_options) {
                    best_options = options;
                    best_row = row;
                    best_col = col;
                }
            }
        }
        return {best_row, best_col};

    }

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

    void remove_previous_element(std::size_t row, std::size_t col) {
        std::size_t index = field[row][col];
        if (index == 0) {
            return;
        }
        rows[row].reset(index - 1);
        cols[col].reset(index - 1);
        blks[calculate_block(row, col)].reset(index -1);
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
   