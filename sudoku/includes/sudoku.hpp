#pragma once
#include <array>
#include <cstddef>
#include <string>

//_ 123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ

//defines a NxN Sudoku puzzle
template <std::size_t N>
class Sudoku {
private:
    std::array<std::array<char, N>, N> field;
    std::string SYMBOLS = "_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    Sudoku() {
        for (auto& row : field) {
            for (auto& cell : row) {
                cell = '_';
            }
        }
    }

    //~Sudoku() = default;

    bool set(std::size_t row, std::size_t col, char value) {
        if (row >= N || col >= N || SYMBOLS.find(value) == std::string::npos) {
            return false;
        }
        field[row][col] = value;
        return true;
    }

    bool remove_previous_element(std::size_t row, std::size_t col) {
        std::size_t index =field[row][col];
        if(index==0) {
            field[row][col] = 0;
            return true;
        }
        if(!check_rules(row, col, index)) {
            std::size_t old_index = field[row][col];
            rows[row].reset(old_index-1);
            cols[col].reset(old_index-1);
            blks[calculate_block(row, col)].reset(old_index-1);
            return false;
        }
        field[row][col] = index;
        rows[row].set(index-1);
        cols[col].set(index-1);
        blks[calculate_block(row, col)].set(index-1);
            
    }

};