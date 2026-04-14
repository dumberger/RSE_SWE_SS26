#include "../include/sudoku.hpp"
#include <gtest/gtest.h>


// define the size of the Sudoku for testing
constexpr std::size_t N = 9;

    /* ***** */
    /* TESTS */
    /* ***** */

// a newly initialized Sudoku should have all cells set to 0
TEST(SUDOKU, init_empty)
{
    Sudoku<N> sudoku;

    for (std::size_t row = 0; row < N; row++) 
    {
        for (std::size_t col = 0; col < N; col++) 
        {
            EXPECT_EQ(sudoku.get(row, col), 0);
        }
    }    
}

// setting a cell to a valid character should return true and getting it should return the same character
TEST(SUDOKU, set_get_char)
{
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(2, 2, '5'));
    EXPECT_EQ(sudoku.get(2, 2), '5'); 
}

// setting multiple cells with valid characters and getting it should return the last character set
TEST(SUDOKU, multiple_set_get)
{
    Sudoku<N> sudoku;

    for (std::size_t i = 1; i < 6; i++)
    {
        ASSERT_TRUE(sudoku.set(i, i, '0' + i));   
    }

    for (std::size_t i = 1; i < 6; i++)
    {
        EXPECT_EQ(sudoku.get(i, i), '0' + i);
    }
    EXPECT_EQ(sudoku.get(0, 0), 0);
}

// setting a cell to a valid character at the edge of the Sudoku should work correctly
TEST(SUDOKU, set_get_edge_index)
{
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(0, 0, '1'));
    ASSERT_TRUE(sudoku.set(N - 1, N - 1, '9'));

    EXPECT_EQ(sudoku.get(0, 0), '1');
    EXPECT_EQ(sudoku.get(N - 1, N - 1), '9');
}

// setting a cell to a valid character and then overwriting it with another valid character should update the value correctly
TEST(SUDOKU, overwrite_value)
{
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(1, 1, '3'));
    ASSERT_TRUE(sudoku.set(1, 1, '7'));

    EXPECT_EQ(sudoku.get(1, 1), '7');
}

// setting a cell to a valid character should not affect other cells
TEST(SUDOKU, set_independent)
{
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(4, 4, '8'));

    EXPECT_EQ(sudoku.get(4, 4), '8');
    EXPECT_EQ(sudoku.get(4, 5), 0);
    EXPECT_EQ(sudoku.get(5, 4), 0);
}

// setting a cell to an invalid character should return false and not change the value of the cell
TEST(SUDOKU, set_invalid_char)
{
    Sudoku<N> sudoku;

    EXPECT_FALSE(sudoku.set(0, 0, '!'));
    EXPECT_FALSE(sudoku.set(0, 0, ';'));   
    EXPECT_FALSE(sudoku.set(0, 0, 'c'));

    EXPECT_EQ(sudoku.get(0, 0), 0);
}

// setting a cell to a character that is valid for a smaller Sudoku but not for the current size should return false and not change the value of the cell
TEST(SUDOKU, set_char_out_of_range)
{
    Sudoku<N> sudoku;

    EXPECT_FALSE(sudoku.set(0, 0, 'A'));
    EXPECT_FALSE(sudoku.set(0, 0, 'B'));
    EXPECT_EQ(sudoku.get(0, 0), 0);
}

// setting a cell out of bounds should return false
TEST(SUDOKU, set_index_out_of_bounds)
{
    Sudoku<N> sudoku;
    
    EXPECT_FALSE(sudoku.set(N, 0, '5'));
    EXPECT_FALSE(sudoku.set(0, N, '5'));
    EXPECT_FALSE(sudoku.set(N, N, '5'));
}

// getting a cell out of bounds should throw an exception
TEST(SUDOKU, get_index_out_of_bounds)
{
    Sudoku<N> sudoku;
    
    EXPECT_THROW(sudoku.get(N, 0), std::out_of_range);
    EXPECT_THROW(sudoku.get(0, N), std::out_of_range);
    EXPECT_THROW(sudoku.get(N, N), std::out_of_range);
}

// setting and getting values in a larger Sudoku should work correctly
TEST(SUDOKU, set_get_16x16)
{
    Sudoku<16> sudoku;

    ASSERT_TRUE(sudoku.set(0, 0, 'A'));
    EXPECT_EQ(sudoku.get(0, 0), 'A');

    ASSERT_TRUE(sudoku.set(15, 15, 'G'));
    EXPECT_EQ(sudoku.get(15, 15), 'G');
}

