#include "creator.hpp"
#include "sudoku.hpp"
#include "solver.hpp"

#include <filesystem>
#include <fstream>
#include <random>

bool Creator::loadSudoku(std::filesystem::path file) { 
    if(!std::filesystem::exists(file)) {
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

bool Creator::loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path)
{
    sudoku = reference;
    base_directory = base_path;
    return true;
}

void Creator::create()
{
    fill_randomly();
    erode_sudoku();
    write_creation();
}

bool Creator::fill_cell_valid(std::mt19937& rng, std::array<int,9>& order)
{
    auto [row, col] = sudoku.next();
    if (row == 9) return true; // fertig

    std::shuffle(order.begin(), order.end(), rng);
    for (int i : order) {
        if (sudoku.set(row, col, Sudoku<9>::SYMBOLS[i+1])) {
            if (fill_cell_valid(rng, order)) return true;
            sudoku.set(row, col, Sudoku<9>::SYMBOLS[0]);
        }
    }
    return false;
}

void Creator::fill_randomly()
{
    std::mt19937 rng(std::random_device{}());
    std::array<int,9> order = {0,1,2,3,4,5,6,7,8};

    fill_cell_valid(rng, order);
}

    
void Creator::erode_sudoku()
{
    std::mt19937 rng(std::random_device{}());

    while (true)
    {
        int row = rng() % 9, col = rng() % 9;
        char current = sudoku.get(row, col);
        if (current == '_') continue;

        sudoku.set(row, col, '_');

        Solver solver;
        solver.loadSudoku(sudoku, base_directory);

        if (solver.solve() > 1)
        {
            sudoku.set(row, col, current);
            break;
        }
    }
}

void Creator::write_creation()
{
    std::stringstream creation_name;
    creation_name << "random_generated" << ".txt";
    std::ofstream file(base_directory / creation_name.str());
    file << sudoku;
}