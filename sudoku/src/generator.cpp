#include "generator.hpp"
#include "solver.hpp"

#include <cstddef>

Generator::Generator()
    : rng(std::random_device{}())
{
}

char Generator::symbol_random() {
    std::uniform_int_distribution<std::size_t> dist(1, 9);
    return Sudoku<9>::SYMBOLS[dist(rng)];
}

bool Generator::has_empty_cell() {
    return sudoku.next() != std::pair<std::size_t, std::size_t>{9, 9};
}

std::pair<std::size_t, std::size_t> Generator::empty_cell_random() {
    if (!has_empty_cell()) {
        return {9, 9};
    }

    std::size_t row;
    std::size_t col;

    do {
        std::uniform_int_distribution<std::size_t> cell_distribution(0, 8);

        row = cell_distribution(rng);
        col = cell_distribution(rng);

    } while (sudoku.get(row, col) != '_');

    return {row, col};
}

std::size_t Generator::solution_count(std::filesystem::path path_directory) {
    Solver solver;

    if (!solver.loadSudoku(sudoku, path_directory)) {
        return 0;
    }

    return solver.solve(false);
}

Sudoku<9> Generator::generateSudoku(std::filesystem::path path_directory) {
    std::size_t solutions = 0;

    while (solutions != 1 && has_empty_cell()) {
        auto [row, col] = empty_cell_random();
        char value = symbol_random();

        if (!sudoku.set(row, col, value)) {
            continue;
        }

        solutions = solution_count(path_directory);

        if (solutions == 0) {
            sudoku.set(row, col, '_');
        }
    }

    return sudoku;
}