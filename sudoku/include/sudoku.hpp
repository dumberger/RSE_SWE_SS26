#pragma once

#include <bitset>
#include <cstddef>
#include <array>
#include <ostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

//HÜ Zellen überschreiben

// Forward declarations
template<std::size_t N> class Sudoku;

template<std::size_t N>
std::ostream& operator<<(std::ostream& stream, Sudoku<N> &sudoku);

// defines a NxN Sudoku
template<std::size_t N>
class Sudoku {
private:
    std::array<std::array<unsigned int, N>, N> field;
    //placeholdr for symbols, 0 is empty cell, 1-9 for 1-9, A-Z for 10-35
    std::string SYMBOLS="_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::array<std::bitset<N>, N> rows;
    std::array<std::bitset<N>, N> cols;
    std::array<std::bitset<N>, N> blks;

    friend std::ostream& operator<< <N>(std::ostream& stream, Sudoku<N> &sudoku);

public:
    Sudoku() {
        for (auto& row : field) {
            for (auto& cell : row) {
                cell = 0;
            }
        }
    }

    //~Sudoku() = default;
    char get(std::size_t row, std::size_t col){return SYMBOLS[field[row][col]];};


        bool set(std::size_t row, std::size_t col, char value){
            
            if(row>=N || col>=N){
                return false; //out of bounds
            }
            /*
            auto i = std::find(SYMBOLS.begin(), SYMBOLS.end(),value);
            if(i == SYMBOLS.end()){
                return false; //invalid symbol
            }
            int index = i - SYMBOLS.begin();
            */
            auto index =SYMBOLS.find(value);
            if(index == std::string::npos){
                return false; //invalid symbol
            }
    
            if(index>N){
                return false; //symbol out of range for this Sudoku size
            }   
    
            if (!check_rules(row, col, index)) {
                return false; // violates Sudoku rules
            }
            //zellen löschen und dann neu einfügen für überschreiben falls nicht gütig altes elemet soll bleiben 
            
            field[row][col] = index;
            rows[row].set(index);
            cols[col].set(index);
            blks[calculate_block(row, col)].set(index-1);
            return true;
        }
    
    private:

        int calculate_block(std::size_t row, std::size_t col) {
            
            std::size_t block_size = sqrt(N);
            
            return (row / block_size) *block_size + (col / block_size);
        }

        bool check_rules(std::size_t row, std::size_t col, int index) {
        // Check row
        
        std::bitset<N> row_= rows[row];
        if (row_[index]) {
            return false; // symbol already exists in the row
        }
        // Check column
        std::bitset<N> col_= cols[row];
        if (col_[index-1]) {
            return false; // symbol already exists in the column
        }
        // Check block
        std::bitset<N> blk= blks[calculate_block(row, col)];
        if (blk[index-1]) {
            return false; // symbol already exists in the block
        }
        return true; // symbol is valid
        
        
    std::bitset<N> result = rows[row] | cols[col] | blks[calculate_block(row, col)];
    std::cout<<result.to_string() << std::endl;
    return !result[index-1]; // symbol is valid if it doesn't exist in row, column, and block
    };

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
            
    };
    
};

template<std::size_t N >
std::ostream& operator<<(std::ostream& stream, Sudoku<N> &sudoku) {
    for (auto& row : sudoku.field) {
            for (auto& cell : row) {
               stream << cell;
            }
                stream << "\n";

        }
        return stream;
        
};

   