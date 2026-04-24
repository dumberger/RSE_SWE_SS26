#include <filesystem>
#include "sudoku.hpp"
#include "solver.hpp"

using namespace std;

int main() {
    Sudoku<9> test;
    char symbol = test.get(0, 0);
    //printf("%c\n\n", symbol);

    //get parent dir
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    //load sudoku
    Solver solver;
    solver.loadSudoku(directory.string() + "/input.txt");

    if (solver.solve())
    {
        printf("Lösung gefunden\n");
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