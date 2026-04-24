#include"solver.hpp"
#include<chrono>
using namespace std;

int main() {
    Solver solver;
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    if(solver.loadSudoku(directory / "input.txt")){
        auto start = std::chrono::high_resolution_clock::now();
        
        solver.solve();

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        std::cout << "Lösungszeit: " << duration.count() << " ms" << std::endl;
    }
    return 0;
}