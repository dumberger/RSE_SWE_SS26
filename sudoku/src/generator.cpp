#include "generator.hpp"
#include "sudoku.hpp"
#include "solver.hpp"

#include <filesystem>
#include <fstream>
#include <random>

// Same like Solver
bool Generator::loadSudoku(std::filesystem::path file) {
    if (!std::filesystem::exists(file)) {
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    if (input.good()) {
        base_directory = file.parent_path();
        return true;
    }
    return false;
}

// Same like Solver
bool Generator::loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path)
{
    sudoku = reference;
    base_directory = base_path;
    return true;
}

// This will generate a random-filled sudoku, erodite until targeted-solutions are present, then write out the solution(s)
void Generator::generate()
{
    std::mt19937 rng(std::random_device{}());

    fill_random(rng);
    erode(rng);

    write_creation();
}

// This will fill the sudoku random
void Generator::fill_random(std::mt19937& rng)
{
    // Determine next empty cell
    auto [row, col] = sudoku.next();
    if (row == 9 && col == 9)
    {
        return;     // is filled
    }

    // Use a list of all possible entries and shuffle it
    // NOTE: Did not know shuffle, KI Claude Sonnet 4.6 suggested it, Normally i would have just skipped shuffle, but this makes it "more random"
    std::array<int, 9> entries = {1,2,3,4,5,6,7,8,9};
    std::shuffle(entries.begin(), entries.end(), rng);

    // Try all entries for cell in accordance with sudoku-rules
    for (int e : entries)
    {
        if (sudoku.set(row, col, Sudoku<9>::SYMBOLS[e]))
        {
            fill_random(rng);
            auto [next_row, next_col] = sudoku.next();

            // Recursive call until the next targeted cell would already be full
            if (next_row == 9 && next_col == 9)
            {
                return;
            }

            sudoku.set(row, col, '_');
        }
    }
}

void Generator::erode(std::mt19937& rng)
{
    // Build a list of all 81 cells and shuffle for random erosion order
    std::array<std::pair<int,int>, 81> cells;
    int idx = 0;
    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            cells[idx++] = {r, c};
        }
    }
        
    std::shuffle(cells.begin(), cells.end(), rng);

    // Try to remove each cell
    for (auto [row, col] : cells)
    {
        char current = sudoku.get(row, col);

        // Skip already empty cells
        if (current == '_') 
        {
            continue;
        }
        
        // Remove the cell
        sudoku.set(row, col, '_');

        // Check if sudoku still has exactly one solution
        Solver solver;
        solver.mute_solver(true);
        solver.target_solutions = 1;
        solver.loadSudoku(sudoku, base_directory);

        // If not solvable anymore, restore the cell
        if (solver.solve() != 1)
        {
            sudoku.set(row, col, current);
        }
    }
}

void Generator::write_creation()
{
    std::ofstream file(base_directory / "random_generated.txt");
    file << sudoku;
}