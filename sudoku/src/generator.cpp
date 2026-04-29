#include "generator.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

std::vector<int> SudokuGenerator::getRandomOrder() {
    std::vector<int> order = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(order.begin(), order.end(), g);
    return order;
}

void SudokuGenerator::fillDiagonal(Sudoku<9>& sudoku) {
    // Fülle die drei Diagonalblöcke (keine Konflikte zwischen ihnen)
    for (int block = 0; block < 3; ++block) {
        std::vector<int> order = getRandomOrder();
        int idx = 0;
        for (int row = block * 3; row < (block + 1) * 3; ++row) {
            for (int col = block * 3; col < (block + 1) * 3; ++col) {
                char symbol = '1' + (order[idx++] - 1);
                sudoku.set(row, col, symbol);
            }
        }
    }
}

bool SudokuGenerator::solveSudoku(Sudoku<9>& sudoku) {
    auto [row, col] = sudoku.next();
    
    // Wenn alle Felder gefüllt sind, erfolgreich gelöst
    if (row == 9 && col == 9) {
        return true;
    }
    
    // Versuche alle Ziffern in zufälliger Reihenfolge
    std::vector<int> order = getRandomOrder();
    
    for (int digit : order) {
        char symbol = '1' + (digit - 1);
        if (sudoku.set(row, col, symbol)) {
            if (solveSudoku(sudoku)) {
                return true;
            }
            // Rückgängig machen (setze auf Platzhalter)
            sudoku.set(row, col, '_');
        }
    }
    
    return false;
}

Sudoku<9> SudokuGenerator::generateSolved() {
    Sudoku<9> sudoku;
    
    // Fülle Diagonalblöcke
    fillDiagonal(sudoku);
    
    // Löse den Rest mittels Backtracking
    solveSudoku(sudoku);
    
    return sudoku;
}

Sudoku<9> SudokuGenerator::generatePuzzle(int difficulty) {
    Sudoku<9> solved = generateSolved();
    Sudoku<9> puzzle = solved;
    
    // Entferne `difficulty` Zellen durch Setzen auf Platzhalter
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 8);
    
    int removed = 0;
    int attempts = 0;
    int maxAttempts = 1000;
    
    while (removed < difficulty && attempts < maxAttempts) {
        int row = dis(gen);
        int col = dis(gen);
        
        // Prüfe, ob Zelle nicht leer ist (get() gibt nicht '_' zurück)
        char cell = puzzle.get(row, col);
        if (cell != '_') {
            // Setze auf Platzhalter
            puzzle.set(row, col, '_');
            removed++;
        }
        attempts++;
    }
    
    return puzzle;
}

bool SudokuGenerator::writeToFile(const Sudoku<9>& sudoku, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }
    
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            char cell = sudoku.get(row, col);
            file << cell;
            if (col < 8) file << " ";
        }
        file << "\n";
    }
    
    file.close();
    return true;
}
