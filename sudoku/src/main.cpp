#include <random> 
#include "solver.hpp"
#include "sudoku.hpp"
#include "sudoku_generator.hpp"
using namespace std;

int main() {
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    Solver solver;
    Sudoku_generator generatesudoku;
    generatesudoku.generate_start_Sudoku();
    
    //if(solver.loadSudoku(directory / "input.txt"))
    //{
    //    solver.solve();
    //}

    //uniform_int_distribution<int> random;
    //cout<<random.a();
    directory = directory.parent_path();
    std::ofstream output(directory.string() + "/template.txt");
    std::cout << generatesudoku.Sudoku_generated;
    /*std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    
    std::ofstream output(directory.string() + "/template.txt");
    Sudoku<9> sudoku_template;
    output << sudoku_template;

    std::ifstream input(directory.string() + "/input.txt");
    Sudoku<9> copy;
    input >> copy;
    std::cout << copy;
    if(!input.good())
    {
        std::cout << "error reading file\n";
    }*/
    return 0;
}