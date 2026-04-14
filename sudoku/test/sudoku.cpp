#include "sudoku.hpp"
#include <gtest/gtest.h>

TEST(SUDOKU, field_empty_at_first) {
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0,0), '_'); //oben
    EXPECT_EQ(sudoku.get(0,1), '_');
    EXPECT_EQ(sudoku.get(1,0), '_');
    EXPECT_EQ(sudoku.get(4,4), '_'); //mitte
    EXPECT_EQ(sudoku.get(3,4), '_');
    EXPECT_EQ(sudoku.get(4,5), '_');
    EXPECT_EQ(sudoku.get(8,8), '_'); //unten
    EXPECT_EQ(sudoku.get(7,8), '_');
    EXPECT_EQ(sudoku.get(8,7), '_');
}

TEST(SUDOKU, set_get_functions) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_TRUE(sudoku.set(1,2,'3'));
    EXPECT_EQ(sudoku.get(1,1), '8');
    EXPECT_EQ(sudoku.get(1,2), '3');
}

TEST(SUDOKU, cell_does_not_affect_others) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    EXPECT_EQ(sudoku.get(1,1), '8');
    EXPECT_EQ(sudoku.get(1,2), '_');
    EXPECT_EQ(sudoku.get(3,2), '_');
}

TEST(SUDOKU, overwrite_cell) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_TRUE(sudoku.set(1,1,'3'));
    EXPECT_EQ(sudoku.get(1,1), '3');
}

TEST(SUDOKU, valid_symbol) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_TRUE(sudoku.set(4,4,'5'));
}

TEST(SUDOKU, invalid_symbol) {
    Sudoku<9> sudoku;
    ASSERT_FALSE(sudoku.set(2,2,'x'));
    ASSERT_FALSE(sudoku.set(1,3,'.'));
    EXPECT_EQ(sudoku.get(2,2), '_');
}

TEST(SUDOKU, invalid_symbol_cannot_overwrite_cell) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_FALSE(sudoku.set(1,1,'x'));
    ASSERT_FALSE(sudoku.set(1,1,'.'));
    EXPECT_EQ(sudoku.get(1,1), '8');
}

TEST(SUDOKU, out_of_cell_index) {
    Sudoku<9> sudoku;
    ASSERT_FALSE(sudoku.set(9, 0, '5'));
    ASSERT_FALSE(sudoku.set(0, 9, '5'));
}

TEST(SUDOKU, alphabetic_for_larger_sudoku) {
    Sudoku<16> sudoku;

    ASSERT_TRUE(sudoku.set(0, 0, 'A'));
    EXPECT_EQ(sudoku.get(0, 0), 'A');
}
