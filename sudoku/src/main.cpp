#include "solver.hpp"

#include "creator.hpp"
#include <cstdlib>

using namespace std;

int main() {
  Creator creator;
  int holes = 40;
  Sudoku<9> sudoku = creator.create(holes);

  /*std::filesystem::path directory(__FILE__);
  directory = directory.parent_path();
  Solver solver;
  if (solver.loadSudoku(directory / "input.txt")) {
    solver.solve();
  } */

  return 0;
}