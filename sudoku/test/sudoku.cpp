#include "sudoku.hpp"
#include <gtest/gtest.h>

// Test fixture for Sudoku tests

TEST (SudokuTest, SET)
{
    Sudoku<9> sudoku;
    EXPECT_TRUE(sudoku.set(0, 0, '5'));
    EXPECT_TRUE(sudoku.set(0, 1, '3'));
    EXPECT_FALSE(sudoku.set(0, 0, '4')); // Cell already occupied
    EXPECT_FALSE(sudoku.set(0, 2, '5')); // Duplicate in row
    EXPECT_FALSE(sudoku.set(1, 0, '5')); // Duplicate in column
    EXPECT_FALSE(sudoku.set(1, 1, '5')); // Duplicate in box
}
TEST (SudokuTest, GET)
{
    Sudoku<9> sudoku;
    sudoku.set(0, 0, '5');
    sudoku.set(0, 1, '3');
    EXPECT_EQ(sudoku.get(0, 0), '5');
    EXPECT_EQ(sudoku.get(0, 1), '3');
    EXPECT_EQ(sudoku.get(0, 2), '0'); // Empty cell
}
TEST (SudokuTest, InvalidInput)
{
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(0, 0, '0')); // Invalid symbol
    EXPECT_FALSE(sudoku.set(0, 0, 'A')); // Invalid symbol for 9x9
    EXPECT_FALSE(sudoku.set(9, 0, '5')); // Out of bounds
    EXPECT_FALSE(sudoku.set(0, 9, '5')); // Out of bounds
}
TEST (SudokuTest, EmptyCells)
{
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0, 0), '0'); // Empty cell
    EXPECT_EQ(sudoku.get(8, 8), '0'); // Empty cell
}
// only set and get tests
TEST (SudokuTest, initialization)
{
    Sudoku<9> sudoku;
    for (size_t row = 0; row < 9; ++row) {
        for (size_t col = 0; col < 9; ++col) {
            EXPECT_EQ(sudoku.get(row, col), '0'); // All cells should be empty
        }
    }
}
TEST (SudokuTest, Valid_input)
{
    Sudoku<9> sudoku;
 for(size_t i = 0; i < 9; ++i) {
        EXPECT_TRUE(sudoku.set(0, i, '1' + i)); // Set valid symbols in the first row
    }
}
