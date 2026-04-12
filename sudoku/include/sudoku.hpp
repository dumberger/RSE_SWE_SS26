#pragma once

#include <cstddef>
#include <array>
#include <string>

// defines a NxN Sudoku
template<std::size_t N>
class Sudoku {
private:
    std::array<std::array<unsigned int, N>, N> field;
    std::string SYMBOLS="_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    Sudoku() {
        for (auto& row : field) {
            for (auto& cell : row) {
                cell = 0;
            }
        }
    }

    //~Sudoku() = default;

    bool set(std::size_t row, std::size_t col, char value);
    char get(std::size_t row, std::size_t col);
};



// Für die Tests (muss noch fertig implementiert werden)
template<std::size_t N>
bool Sudoku<N>::set(std::size_t row, std::size_t col, char value) {
    return false; // Noch leer gelassen
}

template<std::size_t N>
char Sudoku<N>::get(std::size_t row, std::size_t col) {
    return '_'; // Einfach einen Standardwert zurückgeben für das Kompilieren
}