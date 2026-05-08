#pragma once

#include "sudoku.hpp"
#include <random>

class Generator
{
public:
    // Gehört eigentlich in sudoku.hpp
    using CellPos = std::pair<std::size_t, std::size_t>;
    
    static Sudoku<9> generate();

private:
    Sudoku<9> run();
    int getRandomSymbol();
    CellPos getRandomEmptyCell();
    int countSolutions();

private:
    Generator() = default;
    Sudoku<9> m_sudoku;
    std::mt19937 rng{std::random_device{}()};
};