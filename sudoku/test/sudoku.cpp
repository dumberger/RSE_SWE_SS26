#include "sudoku.hpp"
#include <gtest/gtest.h>

// Check cell after creation
TEST(SUDOKU, empty_at_init)
{
    Sudoku<9> test;
    for(std::size_t row = 0; row < 9; row++) {
        for(std::size_t col = 0; col < 9; col++) {
            EXPECT_EQ(test.get(row, col), '_');
        }
    }
}

// Set a cell and get the cell
TEST(SUDOKU, set_and_get)
{
    Sudoku<9> test;
    EXPECT_TRUE(test.set(4, 4, '9'));
    EXPECT_EQ(test.get(4, 4), '9');
}

// Set something that is valid/invalid for Sudoku
TEST(SUDOKU, set_for_sudoku)
{
    Sudoku<9> test;
    EXPECT_FALSE(test.set(0, 0, 'x'));
    EXPECT_FALSE(test.set(1, 1, '!'));

    EXPECT_TRUE(test.set(1, 1, '1'));
    EXPECT_TRUE(test.set(1, 1, '9'));
}

// Set cells that are out of set bounds
TEST(SUDOKU, set_out_of_bounds)
{
    Sudoku<16> test;
    EXPECT_FALSE(test.set(16, 0, '5'));
    EXPECT_FALSE(test.set(0, 16, '5'));
    EXPECT_FALSE(test.set(16, 16, '5'));
}

// Change the same cell multiple times, also check directly after creation
TEST(SUDOKU, change_entry_multiple)
{
    Sudoku<9> test;
    EXPECT_EQ(test.get(4, 4), '_');

    test.set(4, 4, '5');
    EXPECT_EQ(test.get(4, 4), '5');

    test.set(4, 4, '1');
    EXPECT_EQ(test.get(4, 4), '1');

    test.set(4, 4, '9');
    EXPECT_EQ(test.get(4, 4), '9');
}