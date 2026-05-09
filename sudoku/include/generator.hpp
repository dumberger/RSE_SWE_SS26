#pragma once

#include <filesystem>
#include "sudoku.hpp"
#include <random>

class Generator
{
  public:
    std::size_t generate();
    bool saveSudoku(std::filesystem::path file);
    Sudoku<9>& getSudoku() { return sudoku; };
  private:
    Sudoku<9> sudoku;
    int solutions = 0;
    bool fill_random(Sudoku<9>& board, std::mt19937& rng);
    std::size_t count_filled(Sudoku<9>& board);
};

/*

Diese Klasse soll nach und nach ein Sudoku mit zufälligen Zahlen befüllen und den Solver nutzen um die Lösbarkeit zu überprüfen. 
Es werden solange neue Zufallszahlen eingefügt, bis es nur noch eine einzige eindeutige Lösung übrig bleibt.
Zum generieren der Zufallszahlen sol das random Modul der STL verwendet werden.

*/