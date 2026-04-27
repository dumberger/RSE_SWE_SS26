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
    solver.loadSudoku(directory.string() + "/input.txt");

    auto start = std::chrono::high_resolution_clock::now();

    if (solver.solve())
    {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Dauer: "
          << std::fixed << std::setprecision(3)
          << elapsed.count() << " ms\n";

        printf("Mindestens eine Lösung gefunden\n");
        //if solved print to cout

        //std::cout << solver.sudoku;
        // std::ofstream output(directory.string() + "/solution.txt", std::ios::trunc);
        // if (output.is_open()) {
        //     output << copy;
        //     output.close();
        // }

    }
    else
    {
        std::cout << "Keine Lösung gefunden\n";
    }
    return 0;
}
