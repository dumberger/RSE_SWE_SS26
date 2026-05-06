#include "generator.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>
#include <utility>

namespace {

std::vector<int> getRandomOrder() {
    std::vector<int> order = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::shuffle(order.begin(), order.end(), generator);
    return order;
}

std::vector<std::pair<int, int>> getShuffledCells() {
    std::vector<std::pair<int, int>> cells;
    cells.reserve(81);

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells.emplace_back(row, col);
        }
    }

    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::shuffle(cells.begin(), cells.end(), generator);
    return cells;
}

std::size_t countSolutions(Sudoku<9> sudoku, std::size_t limit = 2) {
    auto [row, col] = sudoku.next();

    if (row == 9 && col == 9) {
        return 1;
    }

    std::size_t solutions = 0;
    for (int digit : getRandomOrder()) {
        char symbol = '1' + (digit - 1);
        if (!sudoku.set(row, col, symbol)) {
            continue;
        }

        solutions += countSolutions(sudoku, limit - solutions);
        if (solutions >= limit) {
            return solutions;
        }

        sudoku.set(row, col, '_');
    }

    return solutions;
}

bool hasUniqueSolution(const Sudoku<9>& sudoku) {
    return countSolutions(sudoku, 2) == 1;
}

} // namespace

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

    while (true) {
        sudoku = Sudoku<9>();

        // Fülle Diagonalblöcke
        fillDiagonal(sudoku);

        // Löse den Rest mittels Backtracking
        if (solveSudoku(sudoku)) {
            return sudoku;
        }
    }
}

Sudoku<9> SudokuGenerator::generatePuzzle(int difficulty) {
    Sudoku<9> solved = generateSolved();
    Sudoku<9> puzzle = solved;

    // Entferne Zufallsfelder nur dann, wenn die Eindeutigkeit erhalten bleibt.
    int removed = 0;
    for (const auto& [row, col] : getShuffledCells()) {
        if (removed >= difficulty) {
            break;
        }

        char previous = puzzle.get(row, col);
        if (previous == '_') {
            continue;
        }

        puzzle.set(row, col, '_');
        if (hasUniqueSolution(puzzle)) {
            ++removed;
        } else {
            puzzle.set(row, col, previous);
        }
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
