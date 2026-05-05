#include "generator.hpp"
#include "solver.hpp"

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

bool Generator::one_solution_only(std::filesystem::path path_directory) {
    Solver solver;

    if (!solver.loadSudoku(sudoku, path_directory)) {
        return false;
    }

    std::size_t amount_solutions = solver.solve();

    if (amount_solutions == 1) {
        return true;
    } else {
        return false;
    }
}

Sudoku<9> Generator::generateSudoku(std::filesystem::path path_directory) {
    while (!one_solution_only(path_directory) && has_empty_cell()) {
        auto [row, col] = empty_cell_random();

        char value = symbol_random();

        if (!sudoku.set(row, col, value)) {
            continue;
        }
    }

    return sudoku;
}