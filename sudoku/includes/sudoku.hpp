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

};