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

    string sudoku_file;
    sudoku_file = directory.string() + "/input.txt";

    //generator to generate new sudoku
    std::mt19937 rand(std::random_device{}());
    Generator generator;
    generator.generateSudoku(sudoku_file, 42, rand);

    //load sudoku
    Solver solver;
    if (!solver.loadSudoku(sudoku_file)) {
        std::cout << "Failed to load input.txt to solver\n";
        return -1;
    }

    //find all solutions, should be only one due to generator
    if (!solver.solve(-1)) {
        std::cout << "Keine Lösung gefunden\n";
        return -2;
    }

    //if solved print to cout
    printf("Mindestens eine Lösung gefunden\n");
    std::ifstream input(directory.string() + "/results/0.txt");
    Sudoku<9> sudoku;
    input >> sudoku;

    std::cout << "Sudoku Solution:\n" << sudoku << std::endl;

    return 0;
}
