#pragma once

#include"sudoku.hpp"
#include "solver.hpp"
#include<filesystem>
#include <random>

class Creator{
    public:

        Creator(std::filesystem::path base);
        bool create();
        bool trim_Sudoku(int difficulty);
        Sudoku<9> getSudoku() const;
        Solver solver;

    private:
        Sudoku<9> sudoku;
        void write_sudoku();
        bool fill_cell();
        int generate_random_number(int count, std::bitset<9>& bitset);
        std::filesystem::path base_directory;
        std::pair<std::size_t, std::size_t> pick_random_cell();

        std::random_device rd;
        std::mt19937 gen;
        int number = 0;



};