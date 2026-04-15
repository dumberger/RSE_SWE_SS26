#include "sudoku.hpp"
#include <gtest/gtest.h>

TEST(Sudoku, set_value)
{
    Sudoku<9> sudoku;

    EXPECT_TRUE(sudoku.set(2, 3, '7'));
}

TEST(Sudoku, get_value)
{
    Sudoku<9> sudoku;
    sudoku.set(2, 3, '7');

    EXPECT_EQ(sudoku.get(2, 3), '7');
}

TEST(Sudoku, initialize)
{
    Sudoku<9> sudoku;

	for (std::size_t row = 0; row < 9; ++row)
	{
		for (std::size_t col = 0; col < 9; ++col)
		{
			EXPECT_EQ(sudoku.get(row, col), '_');
		}
	}
}

TEST(Sudoku, out_of_bounds)
{
	Sudoku<9> sudoku;

	EXPECT_FALSE(sudoku.set(9, 0, '1'));
}

TEST(Sudoku, invalid_symbol)
{
	Sudoku<9> sudoku;

	EXPECT_FALSE(sudoku.set(1, 1, '0'));
	EXPECT_EQ(sudoku.get(1, 1), '_');
}
