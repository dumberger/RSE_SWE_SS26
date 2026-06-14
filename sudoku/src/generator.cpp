#include "generator.hpp"
#include <numeric>
#include "solver.hpp"

Generator::Generator() : gen(std::random_device{}()) {}

bool Generator::LoadSudoku(const Sudoku<9>& reference, std::filesystem::path path) {
    sudoku = reference;
    base_dir = path;
    return true;
}

bool Generator::fillRecursive() {
    auto [row, col] = sudoku.next();

    if (row == 9 || col == 9) return true; // board is full

    std::vector<int> nums(9);
    std::iota(nums.begin(), nums.end(), 1); // is equal to nums = list(range(1, 10)) in python
    std::shuffle(nums.begin(), nums.end(), gen);

    for (int num : nums) {
        if (sudoku.set(row, col, sudoku.SYMBOLS[num])) { // try valid move
            if (fillRecursive()) return true;

            sudoku.set(row, col, sudoku.SYMBOLS[0]);
        }
    }
    return false;
}

bool Generator::GenerateSudoku() {
    // Сlear the board
    for(int r=0; r<9; ++r) 
        for(int c=0; c<9; ++c) 
            sudoku.set(r, c, sudoku.SYMBOLS[0]);

    if (!fillRecursive()) return false;

    
    std::vector<std::pair<std::size_t, std::size_t>> cells;
    for (std::size_t r = 0; r < 9; ++r)
        for (std::size_t c = 0; c < 9; ++c) 
            cells.push_back({r, c});
    
    std::shuffle(cells.begin(), cells.end(), gen);

    for (auto [row, col] : cells) {
        char backup = sudoku.get(row, col);
        sudoku.set(row, col, sudoku.SYMBOLS[0]);
        
        Solver solver;
        solver.LoadSudoku(sudoku, ""); 
        
        if (solver.solve(false) != 1) {
            sudoku.set(row, col, backup);
        }
    }
    return true;
}