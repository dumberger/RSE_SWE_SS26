#include "solver.hpp"

#include <cstdlib>
#include "generator.hpp"
#include <fstream>

using namespace std;

int main() {

    //__FUNCTION__; // says which function is that
    //__FILE__; // absolute path to this file
    // cout -> character output. Displays everything, what is thrown at it. << is insertion operator


    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
    Generator generator;

    if (generator.GenerateSudoku()) {        
        std::ofstream outputFile(directory / "input.txt"); // output file stream. Write

        if (outputFile.is_open()) {
            outputFile << generator.getSudoku();
            outputFile.close();
        }
        std::cout << generator.getSudoku(); 
    } else {
        std::cout << "error" << std::endl;
    }


    Solver solver;
    if(solver.LoadSudoku(directory / "input.txt"))
    {
        solver.solve();
    }

    
    return 1;
}