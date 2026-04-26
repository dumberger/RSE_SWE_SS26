#include "creator.hpp"
#include "solver.hpp"
#include <filesystem>
#include <fstream>
#include <random>

Sudoku<9> Creator::create(int holes) {

  // Random Generator
  std::random_device rd;
  std::mt19937 g(rd());
  std::uniform_int_distribution<> dist(0, 8);

  // Pfad für temporäre Dateien des Solvers
  std::filesystem::path temp_path =
      std::filesystem::current_path() / "temp_gen";
  std::filesystem::create_directories(temp_path / "results");

  // Suche nach einem vollständigen Sudoku
  Sudoku<9> full_sudoku;
  bool found_full = false;

  while (!found_full) {
    // KORREKTUR 1: Objekt INSIDE die Schleife, damit es immer leer startet
    Sudoku<9> full_sudoku_attempt;
    Sudoku<9> start_grid;

    // KORREKTUR 2: Sicherstellen, dass dist(0, 8) genutzt wird (falls oben
    // definiert)
    int row = dist(g);
    int col = dist(g);
    char symbol = Sudoku<9>::SYMBOLS[1 + (g() % 9)];
    start_grid.set(row, col, symbol);

    Solver solver;
    solver.loadSudoku(start_grid, temp_path);

    if (solver.solve() > 0) {
      std::filesystem::path sol_path = temp_path / "results/0.txt";

      // Kurz warten oder sicherstellen, dass Datei existiert
      if (std::filesystem::exists(sol_path)) {
        std::ifstream sol_file(sol_path);
        if (sol_file >> full_sudoku_attempt) {
          full_sudoku = full_sudoku_attempt; // Zuweisung an die äußere Variable
          found_full = true;
          std::cout << "Erfolg: Volles Sudoku geladen!" << std::endl;
        } else {
          std::cerr << "Fehler: Konnte 0.txt nicht in Sudoku-Objekt lesen!"
                    << std::endl;
        }
      }
    }

    // WICHTIG: Erst nach dem Einlesen loeschen!
    std::filesystem::remove_all(temp_path / "results");
    std::filesystem::create_directory(temp_path / "results");

    if (!found_full) {
      std::cout << "Neuer Versuch..." << std::endl;
    }
  }

  // Entferne zufällige Zahlen
  bool visited[9][9] = {false};
  int removed = 0;
  int attempts = 0;

  while (removed < holes && attempts < 81) {
    int row = dist(g);
    int col = dist(g);

    std::cout << "\nwhile schleife removed" << std::endl;

    if (!visited[row][col]) {
      visited[row][col] = true;
      attempts++;

      char original_value = full_sudoku.get(row, col);
      full_sudoku.set(row, col, '_');

      Solver solver;
      solver.loadSudoku(full_sudoku, temp_path);

      if (solver.solve() == 1) {
        removed++;
      } else {
        full_sudoku.set(row, col, original_value);
      }
    }
  }

  std::filesystem::path output_dir =
      std::filesystem::current_path() / "created";
  std::filesystem::create_directories(output_dir);
  std::filesystem::path file_path = output_dir / "created_sudoku.txt";
  std::ofstream out_file(file_path);

  if (out_file.is_open()) {
    out_file << full_sudoku;
    out_file.close();
  }

  std::filesystem::remove_all(temp_path);
  return full_sudoku;
}