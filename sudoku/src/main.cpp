#include "solver.hpp"

#include <cstdlib>
#include <random>

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

