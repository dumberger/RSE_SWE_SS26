#include "solver.hpp"

#include <cstdlib>
#include "generator.hpp"

using namespace std;

int main() {
    Generator generator;
    generator.generate();

    Solver solver;
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    if(solver.loadSudoku(directory / "input.txt"))
    {
        std::cout << solver.solve() << std::endl;
    }
    return 0;
}