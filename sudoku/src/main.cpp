#include <filesystem>
#include <iomanip>
#include "sudoku.hpp"
#include "solver.hpp"

#include <cstdlib>
#include <random>

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    //load sudoku
    Solver solver;
    if (!solver.loadSudoku(directory.string() + "/input.txt")) {
        std::cout << "Failed to load input.txt to solver\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    if (!solver.solve()) {
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
