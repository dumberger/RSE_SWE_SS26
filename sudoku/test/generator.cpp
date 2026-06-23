#include "generator.hpp"
#include "solver.hpp"

#include <cmath>
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

std::mt19937 make_rng()
{
    return std::mt19937(42); // fixed seed for deterministic tests
}

TEST(GeneratorTest, RejectsTooFewPrefilled)
{
    Generator g;
    auto rng = make_rng();
    EXPECT_FALSE(g.generateSudoku(10, rng));
}

TEST(GeneratorTest, RejectsTooManyPrefilled)
{
    Generator g;
    auto rng = make_rng();
    EXPECT_FALSE(g.generateSudoku(80, rng));
}

TEST(GeneratorTest, GeneratesValidSudoku)
{
    Generator g;
    auto rng = make_rng();
    EXPECT_TRUE(g.generateSudoku(30, rng));
}


int count_filled(const Sudoku<9>& s)
{
    int count = 0;

    for (size_t r = 0; r < 9; ++r)
        for (size_t c = 0; c < 9; ++c)
            if (s.get(r, c) != s.SYMBOLS[0])
                count++;

    return count;
}
TEST(GeneratorTest, PrefilledCountIsReasonable)
{
    Generator g;
    auto rng = make_rng();
    auto sudoku = g.generate(30);
    int filled = count_filled(sudoku);
    EXPECT_GE(filled, 30);
    EXPECT_LE(filled, 81);
}

TEST(GeneratorTest, GeneratedSudokuIsSolvable)
{
    Generator g;
    auto sudoku = g.generate(30);
    Solver solver;
    auto solved = solver.loadThenSolve(sudoku);
    EXPECT_NE(solved, std::nullopt);
}