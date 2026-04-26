#pragma once
#include "sudoku.hpp"
#include "random"
#include <cstddef>
#include <random>


class Creator{
    public:
        Creator(); //Konstruktor für den Zufallsgenerator
        Sudoku<9> create(std::size_t num_symbols); //Neues Sudoku mit bestimmter Anzahl an Startwerten erzeugen

    private:
        std::mt19937 gen;
        std::uniform_int_distribution<std::size_t> dist_pos; //0-8 Index
        std::uniform_int_distribution<int> dist_sym; //1-9 Symbole

};