#include "sudoku.hpp"

#include <gtest/gtest.h>

///get a value
TEST(Sudoku, get_value) {
    Sudoku<9> sudoku;
    char c = sudoku.get(8,8);
    ASSERT_TRUE(c == 0);
}

///set a value
TEST(Sudoku, set_value) {
    Sudoku<9> sudoku;
    char c = 7;
    ASSERT_TRUE(sudoku.set(8,8,c));
    EXPECT_EQ(sudoku.get(8,8), 7);
}

///print the sudoku
TEST(Sudoku, print_sudoku) {
    Sudoku<9> sudoku;
    std::ostringstream oss;
    sudoku.print(oss);
    EXPECT_EQ(oss.str(), "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n");
}

///test is solved row
TEST(Sudoku, check_solved_row) {
    const int size = 9;
    Sudoku<size> sudoku;
    for (int i = 0; i < size; i++) {
        sudoku.set(0,i,i);
    }
    ASSERT_TRUE(sudoku.isRowValid(0));
}


///test is solved
TEST(Sudoku, check_solved) {
    const int size = 9;
    Sudoku<size> sudoku;
    ASSERT_FALSE(sudoku.isSolved);

    std::array<std::array<unsigned int, size>, size> solution {{
        {{5,3,4,6,7,8,9,1,2}},
        {{6,7,2,1,9,5,3,4,8}},
        {{1,9,8,3,4,2,5,6,7}},
        {{8,5,9,7,6,1,4,2,3}},
        {{4,2,6,8,5,3,7,9,1}},
        {{7,1,3,9,2,4,8,5,6}},
        {{9,6,1,5,3,7,2,8,4}},
        {{2,8,7,4,1,9,6,3,5}},
        {{3,4,5,2,8,6,1,7,9}}
    }};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sudoku.set(i,j,solution[i][j]);
        }
    }
    ASSERT_TRUE(sudoku.isSolved);
}

