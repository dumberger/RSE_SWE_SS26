#include "sudoku.hpp"
#include "../src/main.cpp"
#include <gtest/gtest.h>

// bool set(std::size_t row, std::size_t col, char value);
// char get(std::size_t row, std::size_t col);

// get() Tests
TEST(SUDOKU, get_on_empty) {
  Sudoku<9> sudoku;
  ASSERT_EQ(sudoku.get(0, 0), '_');
}

TEST(SUDOKU, get_on_filled) {
  Sudoku<9> sudoku;
  sudoku.set(0, 0, '5');
  ASSERT_EQ(sudoku.get(0, 0), '5');
}

TEST(SUDOKU, get_out_of_bounds) {
  Sudoku<9> sudoku;
  ASSERT_EQ(sudoku.get(0, 10), '\0');
  ASSERT_EQ(sudoku.get(10, 0), '\0');
}

// set() Tests
TEST(SUDOKU, set_out_of_bounds) {
  Sudoku<9> sudoku;
  char value = '5';
  ASSERT_FALSE(sudoku.set(10, 9, value));
  ASSERT_FALSE(sudoku.set(9, 10, value));
}

TEST(SUDOKU, set_not_a_symbol) {
  Sudoku<9> sudoku;
  char value = '!';
  ASSERT_FALSE(sudoku.set(0, 0, value));
  ASSERT_FALSE(sudoku.set(0, 0, value));
}
