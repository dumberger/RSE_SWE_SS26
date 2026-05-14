#include "sudoku.hpp"
#include <cmath>
#include <gtest/gtest.h>

TEST(adrianbier, initialize) { //neues sudoku korrekt mit dem symbol für 0 gefüllt ist.
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0, 0), '_');
    EXPECT_EQ(sudoku.get(8, 8), '_');
}


TEST(adrianbier, set_and_get_value) { //gültige werte setzen und abfragen, set()=true wenn richtig
    Sudoku<9> sudoku;
    EXPECT_TRUE(sudoku.set(0, 0, '5')); 
    EXPECT_EQ(sudoku.get(0, 0), '5');
}


TEST(adrianbier, reject_invalid) {// set() sollte das erkennen und 'false' zurückgeben.
    Sudoku<9> sudoku;  
    EXPECT_FALSE(sudoku.set(0, 0, 'Z'));
    EXPECT_EQ(sudoku.get(0, 0), '_');
}


TEST(adrianbier, out_of_grid) {// index 9 ist bei größe 9 ungültig, da 0-8
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(9, 0, '1'));
    EXPECT_FALSE(sudoku.set(0, 9, '1'));
}


TEST(adrianbier, template_16x16) {//template-flexibilität prüfen
    Sudoku<16> sudoku;
    EXPECT_TRUE(sudoku.set(15, 15, 'F'));
    EXPECT_EQ(sudoku.get(15, 15), 'F');
}

