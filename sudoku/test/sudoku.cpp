#include "../include/sudoku.hpp"
#include <gtest/gtest.h>

// Test 1: Prüfen, ob ein neues Sudoku-Feld erstellt und mit 0 ("_") befüllt wird
TEST(SudokuTest, InitialFieldIsEmpty) {
    Sudoku<9> s;
    for (size_t r = 0; r < 9; r++) {
        for (size_t c = 0; c < 9; c++) {
            EXPECT_EQ(s.get(r, c), '_'); //Erwartung "_" = 0 an jedem Platz
        }
    }
}

// Test 2: Setzen und Lesen eines gültigen Wertes   ----> muss noch in der sudoku.hpp implementiert werden
TEST(SudokuTest, SetAndGetValidValue) {
    Sudoku<9> s;
    EXPECT_TRUE(s.set(0, 0, '5'));
    EXPECT_EQ(s.get(0, 0), '5');
}

// Test 3: Ungültige Symbole
TEST(SudokuTest, RejectInvalidSymbol) {
    Sudoku<9> s;
    EXPECT_FALSE(s.set(1, 1, '!')); // Bspw. ein ! soll nicht eingegeben werden
}

// Test 4: Out-of-Bounds Zugriff (Reihe/Spalte außerhalb von N)
TEST(SudokuTest, OutOfBoundsAccess) {
    Sudoku<9> s;
    // Reihe 10 existiert bei einem 9x9 Sudoku nicht
    EXPECT_FALSE(s.set(10, 0, '1'));
    EXPECT_FALSE(s.set( 0, 10, '1'));
}

// Test 5: Überschreiben eines Wertes
TEST(SudokuTest, OverwriteValue) {
    Sudoku<9> s;
    // Wert schreiben
    s.set(4, 4, '1');
    EXPECT_EQ(s.get(4, 4), '1');
    // Wert wieder überschreiben
    s.set(4, 4, '9');
    EXPECT_EQ(s.get(4, 4), '9');
}