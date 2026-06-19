#include "solver.hpp"
#include "creator.hpp"
#include "sudoku.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <random>
#include "fstream"

using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    Solver solver;
    if(solver.loadSudoku(directory / "input.txt"))
    {
        solver.solve();
    }
    return 0;
}


//Zum testen des sudoku creators 
// int main() {
//     Creator creator;
//     Solver solver;

//     Sudoku<9> mySudoku = creator.create(20); //Sudoku erzeugen

//     //Pfad
//     std::filesystem::path directory(__FILE__);
//     directory = directory.parent_path();
//     std::filesystem::path outputPath = directory / "input_random.txt";

//     // Sudoku in die Datei schreiben
//     std::ofstream outFile(outputPath);
//     if (outFile.is_open()) {
//         outFile << mySudoku;
//         outFile.close();
//     }

//     if(solver.loadSudoku(outputPath)) {
//         solver.solve();
//     }

//     return 0;
// }