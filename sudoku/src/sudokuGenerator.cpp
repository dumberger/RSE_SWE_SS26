#include "sudokuGenerator.hpp"
#include "solver.hpp"
#include <array>
#include <fstream>
#include <random>
#include <filesystem>
#include <sudoku.hpp>
#include <utility>

bool SudokuGenerator::loadSudoku(std::filesystem::path file)
{
    if(!std::filesystem::exists(file))
    {
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    if(input.good())
    {
        base_path = file.parent_path();
        return true;
    }
    return false;           
}

bool SudokuGenerator::loadSudoku(const Sudoku<9>& reference, std::filesystem::path base_path)
{
    this->sudoku = reference;
    this->base_path = base_path;
    return true;
}

void SudokuGenerator::generate()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    fill_random(rng);
    remove_random(rng);
    write_to_file();

    
}

void SudokuGenerator::fill_random(std::mt19937& rng)
{
    auto[row, col] = sudoku.next();
    if (row == 9 && col == 9) {
        return;
    }

    std::array<int,9> indices{1,2,3,4,5,6,7,8,9};
    std::shuffle(indices.begin(), indices.end(), rng);

    for (int index : indices) {
        if (sudoku.set(row, col, sudoku.SYMBOLS[index])) {
            fill_random(rng);
            auto[next_row, next_col] = sudoku.next();
            if (next_row == 9 && next_col == 9) {
                return;
            }
            sudoku.set(row, col, '_');
        }
    }
}

void SudokuGenerator::remove_random(std::mt19937& rng)
{
    std::array<std::pair<int, int>,81> cells;
    int i = 0;
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[i++] = {row, col};
        }
    }
    std::shuffle(cells.begin(), cells.end(), rng);  
    
    // Try to remove each cell
    for(auto [row, col] : cells)
    {
        char current = sudoku.get(row, col);

        // skip if the cell is already empty 
        if(current == '_')
        {
            continue;
        }   
        // remove the cell
        sudoku.set(row, col, '_');
        // check if the sudoku is still solvable
        Solver solver;
        solver.mute_solver(true);
        solver.target_solutions = 2; // find up to two solutions to check uniqueness
        solver.loadSudoku(sudoku, base_path);

        if (solver.solve() != 1)
        {
            // if there are no solutions or more than one solution, restore the cell
            sudoku.set(row, col, current);
        }
    }
}

void SudokuGenerator::write_to_file()
{
    std::stringstream filename;
    filename << "random_generated.txt";
    std::ofstream file(base_path / filename.str());
    file << sudoku;
}

