#include "generator.hpp"
#include "solver.hpp"

#include <filesystem>
#include <fstream>
#include <random>


bool Generator::generateSudoku(std::filesystem::path file, int prefilled, std::mt19937& random) {

    auto base = file.parent_path();

    //probably not possible, likely multiple solutions maybe higher lower limit?
    if (prefilled < 17) {
        return false;
    }

    if(!std::filesystem::exists(base)) {
        return false;
    }
    file_path = file;

    //generate random sudoku then solve
    seed_sudoku(random);

    Solver solver;
    solver.loadSudoku(sudoku,base);
    solver.solve();

    //remove number as long as one solution or prefill reached

    //save
    std::ofstream out(file);
    out << sudoku;

    return true;
}

void Generator::seed_sudoku(std::mt19937 &random) {
    for (int b = 0; b < 9; b+=3) {
        std::array<int, 9> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::shuffle(nums.begin(), nums.end(), random);
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sudoku.set(i, j, nums[idx++]);
            }
        }
    }
}

bool Generator::remove_cell() {
    return false;
}
