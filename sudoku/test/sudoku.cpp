#include "sudoku.hpp"
#include "gtest/gtest.h"


// checking if sudoku has correctly initialized. All field should be equal to "_"
TEST(SUDOKU, CheckInitialEmptyField){
    Sudoku<3> s;
    EXPECT_EQ(s.get(0, 0), '_');
    EXPECT_EQ(s.get(0, 1), '_');
    EXPECT_EQ(s.get(0, 2), '_');
    
    EXPECT_EQ(s.get(1, 0), '_');
    EXPECT_EQ(s.get(1, 1), '_');
    EXPECT_EQ(s.get(1, 2), '_');
    
    EXPECT_EQ(s.get(2, 0), '_');
    EXPECT_EQ(s.get(2, 1), '_');
    EXPECT_EQ(s.get(2, 2), '_');
    
}

// checkin if a value is set if the get method gets the right value back
TEST(SUDOKU, SetAndGetValidValue) {
    Sudoku<9> s;
    EXPECT_TRUE(s.set(0, 0, '5')); 
    EXPECT_EQ(s.get(0, 0), '5');
}

// checking if the symbols are working correctly 
TEST(SUDOKU, LargeSudokuWithLetters){
    Sudoku<16> s;

    EXPECT_TRUE(s.set(15, 15, 'a'));
    EXPECT_EQ(s.get(15, 15), 'A');
}

// checking out of boundary szenario
TEST(SUDOKU, OutOfBoundsHandling){
    Sudoku<9> s;

    EXPECT_FALSE(s.set(9, 0, '1'));
    EXPECT_FALSE(s.set(0, 9, '1'));
}

// checking if sudoku allows to enter symols which are meant for bigger fields or doesn't even exist
TEST(SUDOKU, InvalidSymbolProtection) {
    Sudoku<9> s;
    EXPECT_FALSE(s.set(0, 0, 'Z')); // field too small for this letter
    EXPECT_FALSE(s.set(0, 0, '#')); // not existing
    EXPECT_EQ(s.get(0, 0), '_'); // value in this row and col should stay the same
}

// ToDo: Zählen überschreiben können