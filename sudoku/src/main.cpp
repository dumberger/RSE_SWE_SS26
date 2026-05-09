#include "solver.hpp"

#include "creator.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;
#include <filesystem>

int main() {

  std::filesystem::path currentPath(__FILE__);
  currentPath = currentPath.parent_path();

  Creator gameGenerator;
  Sudoku<9> blankSudoku;

  if (!gameGenerator.setupFromReference(blankSudoku, currentPath)) {
    std::cerr << "Fehler beim Initialisieren des Generators." << std::endl;
    return 1;
  }

  gameGenerator.build();

  return 0;
}