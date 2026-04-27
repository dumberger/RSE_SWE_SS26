#include "generator.hpp"
#include "solver.hpp"

#include <filesystem>
#include <fstream>
#include <random>


bool Generator::generateSudoku(std::filesystem::path file, int prefilled, std::mt19937& random) {

    auto base_directory = file.parent_path();

    //probably not possible, likely multiple solutions maybe higher lower limit?
    if (prefilled < 17) {
        std::cout << "Generator prefill count to low, must have at least 17 prefilled!\n";
        return false;
    }
    if (prefilled > 72) {
        std::cout << "Generator prefill count to high, you baby?\n";
        return false;
    }

    if(!std::filesystem::exists(base_directory)) {
        std::cout << "Generator file path does not exist?\n";
        return false;
    }
    file_path = file;

    //generate random sudoku then solve
    seed_sudoku(random);

    Solver solver;
    solver.loadSudoku(sudoku,base_directory);
    if (solver.solve_one() < 1) {
        std::cout << "Generator seed failed\n";
        return false;
    }

    //std::cout << "Generator Seed \n";
    //std::cout << sudoku << std::endl;

    //load solution into sudoku
    std::stringstream solution_name;
    solution_name << "results/0.txt";
    std::ifstream input(base_directory / solution_name.str());
    input >> sudoku;

    //std::cout << "Generator found Solution\n";
    //std::cout << sudoku << std::endl;

    //remove number as long as one solution or prefill reached

    std::vector<std::pair<size_t, size_t>> entries;
    entries.reserve(81);
    for (size_t r = 0; r < 9; ++r) {
        for (size_t c = 0; c < 9; ++c) {
            entries.push_back({r, c});
        }
    }
    std::shuffle(entries.begin(), entries.end(), random);
    uint to_remove = 82 - prefilled;
    for (int i = 1; i < to_remove; i++) {
        auto [r, c] = entries[i];
        auto value = sudoku.get(r, c);
        sudoku.set(r, c, sudoku.SYMBOLS[0]);

        solver.loadSudoku(sudoku,base_directory);
        if (solver.solve(2) >= 2) {
            sudoku.set(r, c, value);
            std::cout << "Generator desired prefill not reached! prefilled " << (82 -i) << "\n" << std::endl;
            break;
        }
    }

    std::cout << "Generated Sudoku:\n" << sudoku << std::endl;

    //save
    std::ofstream out(file);
    out << sudoku;

    return true;
}

void Generator::seed_sudoku(std::mt19937 &random) {
    for (int b = 0; b < 9; b+=3) {
        std::array<int, 9> symbol_index = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::shuffle(symbol_index.begin(), symbol_index.end(), random);
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sudoku.set(b + i, b + j, sudoku.SYMBOLS[symbol_index[idx]]);
                idx++;
            }
        }
    }
}

