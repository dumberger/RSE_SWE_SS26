#include <gtest/gtest.h>
#include "sudoku.hpp"


TEST(SudokuTest, initialize) { //neues sudoku korrekt mit dem symbol für 0 gefüllt ist.
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0, 0), '0');
    EXPECT_EQ(sudoku.get(8, 8), '0');
}


TEST(SudokuTest, set_and_get_value) { //gültige werte setzen und abfragen, set()=true wenn richtig
    Sudoku<9> sudoku;
    EXPECT_TRUE(sudoku.set(0, 0, '5')); 
    EXPECT_EQ(sudoku.get(0, 0), '5');
}


TEST(SudokuTest, reject_invalid) {// set() sollte das erkennen und 'false' zurückgeben.
    Sudoku<9> sudoku;  
    EXPECT_FALSE(sudoku.set(0, 0, 'Z'));
    EXPECT_EQ(sudoku.get(0, 0), '0');
}


TEST(SudokuTest, out_of_grid) {// index 9 ist bei größe 9 ungültig, da 0-8
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(9, 0, '1'));
    EXPECT_FALSE(sudoku.set(0, 9, '1'));
}


TEST(SudokuTest, template_16x16) {//template-flexibilität prüfen
    Sudoku<16> sudoku;
    EXPECT_TRUE(sudoku.set(15, 15, 'F'));
    EXPECT_EQ(sudoku.get(15, 15), 'F');
}