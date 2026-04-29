#include "creator.hpp"
#include "solver.hpp"
#include <algorithm>
#include <fstream>

bool Creator::setupFromTemplate(std::filesystem::path path) {
  if (!std::filesystem::exists(path))
    return false;

  std::ifstream stream(path);
  if (!(stream >> grid))
    return false;

  work_dir = path.parent_path();
  return true;
}

bool Creator::setupFromReference(const Sudoku<9> &ref,
                                 std::filesystem::path output_path) {
  grid = ref;
  work_dir = output_path;

  // WICHTIG: Erstelle den results-Ordner, damit der Solver dort hineinschreiben
  // kann
  std::error_code ec;
  std::filesystem::create_directory(work_dir / "results", ec);

  return true;
}

void Creator::build() {
  generateBasics(); // Erst vollmachen
  removeNumbers();  // Dann so viel wie möglich löschen
  saveResult();     // Speichern
}

bool Creator::tryFill(std::array<int, 9> &nums) {
  auto [r, c] = grid.next();

  // Wenn r == 9 fertig
  if (r >= 9)
    return true;

  // Zahlen mischen
  for (size_t i = 0; i < 9; ++i) {
    std::uniform_int_distribution<size_t> dist(i, 8);
    std::swap(nums[i], nums[dist(prng)]);
  }

  for (int val : nums) {
    // SYMBOLS[val] entspricht der Zahl (1-9)
    if (grid.set(r, c, Sudoku<9>::SYMBOLS[val])) {
      if (tryFill(nums))
        return true;

      // Backtracking: Feld wieder leeren
      grid.set(r, c, Sudoku<9>::SYMBOLS[0]);
    }
  }
  return false;
}

void Creator::generateBasics() {
  std::array<int, 9> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  tryFill(digits);
}

void Creator::removeNumbers() {
  // Zufällig Zahlen entfernen, bis die Eindeutigkeit kippt
  bool keepRemoving = true;
  while (keepRemoving) {
    std::uniform_int_distribution<int> coord(0, 8);
    int r = coord(prng);
    int c = coord(prng);

    char backup = grid.get(r, c);
    if (backup == Sudoku<9>::SYMBOLS[0])
      continue;

    // Versuchsweise löschen
    grid.set(r, c, Sudoku<9>::SYMBOLS[0]);

    Solver check;
    check.loadSudoku(grid, work_dir);

    // Sobald mehr als eine Lösung existiert, war es zu viel
    if (check.solve() > 1) {
      grid.set(r, c, backup);
      keepRemoving = false; // Abbruch
    }
  }
}

void Creator::saveResult() {
  std::string fileName = "output.txt";
  std::filesystem::path outputPath = work_dir / "results" / fileName;

  std::ofstream out(outputPath);

  out << grid;
}