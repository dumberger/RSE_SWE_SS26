#include "sudoku.hpp"

#include <gtest/gtest.h>

TEST(Test_Sudoku, get)
{
    Sudoku<9> Sudoku;
    Sudoku.set(0, 0, 3);
    Sudoku.set(2, 5, 6);
    
    EXPECT_EQ(Sudoku.get(0,0), 3);

    EXPECT_EQ(Sudoku.get(2,3), 6);



}

TEST(Test_Sudoku, set)
{
    Sudoku<9> Sudoku;
    ASSERT_TRUE(Sudoku.set(0,0,1));
    ASSERT_TRUE(Sudoku.set(0,3,5));
    ASSERT_FALSE(Sudoku.set(0,0,4));
    ASSERT_FALSE(Sudoku.set(0,5,5));
}