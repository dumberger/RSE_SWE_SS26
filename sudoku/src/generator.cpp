#include "generator.hpp"

#include <filesystem>
#include <fstream>


Generator::Generator(): rng(std::random_device{}()) {}

bool Generator::generateSudoku(std::filesystem::path file, int prefilled) {

    //generate random sudoku then solve

    //remove number as long as one solution or prefill reached


    return false;
}

bool Generator::remove_cell() {

}

void Generator::write_suduko() {
    std::ofstream file(base_directory / "input.txt");
    file << sudoku;
}