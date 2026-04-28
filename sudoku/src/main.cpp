#include "solver.hpp"
#include <random>

using namespace std;

int main() {
    //std::filesystem::path directory(__FILE__);
    //directory = directory.parent_path();
    //Solver solver;
    //if(solver.loadSudoku(directory/"input.txt")){
    //    solver.solve();
    //}
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1,1000);
    cout << distrib(gen) << endl;
    cout << rand()<< endl;
    cout << rand()<< endl;
    cout << rand()<< endl;
    return 0;
}