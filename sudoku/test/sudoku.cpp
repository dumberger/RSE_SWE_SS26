//5 Unit Tests for Sudoku
#include "../include/sudoku.hpp"

#include <gtest/gtest.h>

TEST(SUDOKU, empty_field_returns_underscore) {
    // Neues Sudoku ist an allen Positionen leer ('_').
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0, 0), '_');
    EXPECT_EQ(sudoku.get(8, 8), '_');
}

TEST(SUDOKU, set_and_get_valid_value) {
    // Gueltigen Wert setzen und korrekt wieder auslesen.
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(0, 0, '5'));
    EXPECT_EQ(sudoku.get(0, 0), '5');
}

TEST(SUDOKU, set_rejects_out_of_bounds_position) {
    // Ungueltige Koordinaten (>= 9) muessen abgelehnt werden.
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(9, 0, '1'));
    EXPECT_FALSE(sudoku.set(0, 9, '1'));
}

TEST(SUDOKU, set_rejects_invalid_symbol) {
    // Nicht erlaubtes Symbol darf nicht gesetzt werden.
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(0, 0, 'X'));
    EXPECT_EQ(sudoku.get(0, 0), '_');
}

TEST(SUDOKU, set_rejects_row_conflict) {
    // Gleiche Zahl in derselben Zeile muss einen Konflikt ausloesen.
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(0, 0, '7'));
    EXPECT_FALSE(sudoku.set(0, 4, '7'));
}

