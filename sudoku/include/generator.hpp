#pragma once

#include "sudoku.hpp"
#include <string>
#include <vector>

class SudokuGenerator {
public:
    // Erzeugt ein vollständiges, gültiges Sudoku
    static Sudoku<9> generateSolved();
    
    // Erzeugt ein Rätsel durch Löschen von Feldern (0-81, Schwierigkeit)
    static Sudoku<9> generatePuzzle(int difficulty = 40);
    
    // Schreibt Sudoku in Datei
    static bool writeToFile(const Sudoku<9>& sudoku, const std::string& filename);
    
private:
    // Hilfsfunktionen
    static void fillDiagonal(Sudoku<9>& sudoku);
    static bool solveSudoku(Sudoku<9>& sudoku);
    static bool isValid(const Sudoku<9>& sudoku, int row, int col, char value);
    static std::vector<int> getRandomOrder();
};
