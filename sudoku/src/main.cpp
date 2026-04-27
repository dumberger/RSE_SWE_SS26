#include <filesystem>
#include <iomanip>
#include <cstdlib>
#include <random>
#include "sudoku.hpp"
#include "solver.hpp"
#include "generator.hpp"

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    string sudoku_file;
    sudoku_file = directory.string() + "/input.txt";

    std::mt19937 rand(std::random_device{}());
    Generator generator;
    generator.generateSudoku(sudoku_file, 42, rand);

    //load sudoku
    Solver solver;
    if (!solver.loadSudoku(sudoku_file)) {
        std::cout << "Failed to load input.txt to solver\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    if (!solver.solve(-1)) {
        std::cout << "Keine Lösung gefunden\n";
        return -2;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Dauer: "
      << std::fixed << std::setprecision(3)
      << elapsed.count() << " ms\n";

    printf("Mindestens eine Lösung gefunden\n");
    //if solved print to cout

    return 0;
}
