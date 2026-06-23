#include <filesystem>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <random>
#include "sudoku.hpp"
#include "solver.hpp"
#include "generator.hpp"

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    //generator to generate new sudoku
    Generator generator;
    Sudoku<9> new_sudoku = generator.generate(42);

    //find all solutions, should be only one due to generator
    Solver solver;
    auto solved = solver.loadThenSolve(new_sudoku);
    if (!solved) {
        std::cout << "Keine Lösung gefunden\n";
        return -1;
    }

    //if solved print to cout
    printf("Mindestens eine Lösung gefunden\n");
    Sudoku<9> sudoku = *solved;

    std::cout << "Sudoku Solution:\n" << sudoku << std::endl;

    return 0;
}
