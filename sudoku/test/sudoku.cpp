#include "sudoku.hpp"
#include <gtest/gtest.h>

TEST(sudoku, initial_state){
    Sudoku<9> sudoku;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 0; j++){
            ASSERT_EQ(sudoku.get(i, j), 0);
        }
    }
}

TEST(sudoku, set){
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(0, 0, '1'));
}

TEST(sudoku, get){
    Sudoku<9> sudoku;
    sudoku.set(0, 0, '1');
    ASSERT_EQ(sudoku.get(0,0), '1');
}

TEST(sudoku, overwrite_number){
    Sudoku<9> sudoku;
    EXPECT_TRUE(sudoku.set(0, 0, '1'));
    EXPECT_TRUE(sudoku.set(0, 0, '7'));
    ASSERT_EQ(sudoku.get(0, 0), '7');
}

TEST(sudoku, check_bounds){
    Sudoku<9> sudoku;
    ASSERT_FALSE(sudoku.set(0,10,'1'));
    ASSERT_FALSE(sudoku.set(10,0,'1'));
}