#include "generator.hpp"
#include "solver.hpp"
#include <algorithm>
#include <chrono>
#include <vector>

Generator::Generator() {
    // Der Zufallszahlengenerator wird mit der aktuellen Zeit initialisiert,
    // damit bei jedem Start unterschiedliche Sudokus entstehen.
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    rng.seed(seed);
}

Sudoku<9> Generator::generate() {
    // Schritt 1: Zuerst wird ein komplett gültiges, vollständig gefülltes
    // Sudoku erzeugt.
    Sudoku<9> completed = generateCompleteSudoku();
    
    // Schritt 2: Danach werden Zahlen wieder entfernt, bis nur noch ein
    // Rätsel mit genau einer eindeutigen Lösung übrig bleibt.
    return removeNumbersUntilUnique(completed);
}

Sudoku<9> Generator::generateCompleteSudoku() {
    Sudoku<9> sudoku;
    
    
    // Es wird so lange ein neuer Versuch gestartet, bis ein vollständig
    // gültiges Sudoku ohne Regelverletzungen aufgebaut wurde.
    bool success = false;
    while (!success) {
        // Jede neue Runde beginnt mit einem komplett leeren Raster.
        sudoku = Sudoku<9>();
        
        // Danach werden die freien Felder der Reihe nach gefüllt.
        std::pair<std::size_t, std::size_t> pos = sudoku.next();
        while (pos.first < 9 && pos.second < 9) {
            std::uniform_int_distribution<int> dis(1, 9);
            std::vector<int> candidates;
            
            // Für die aktuelle Zelle werden zunächst alle Zahlen von 1 bis 9
            // getestet. Nur Zahlen, die die Sudoku-Regeln einhalten, kommen als
            // Kandidaten in Frage.
            for (int num = 1; num <= 9; num++) {
                char symbol = sudoku.SYMBOLS[num];
                if (sudoku.set(pos.first, pos.second, symbol)) {
                    candidates.push_back(num);
                    // Nach dem Test wird das Feld wieder geleert, damit die
                    // nächste Zahl unter denselben Bedingungen geprüft werden kann.
                    sudoku.set(pos.first, pos.second, '_');
                }
            }
            
            if (candidates.empty()) {
                // Wenn keine Zahl passt, ist der aktuelle Versuch in einer
                // Sackgasse gelandet. Dann wird das komplette Sudoku neu
                // aufgebaut.
                break;
            }
            
            // Aus den gültigen Kandidaten wird zufällig eine Zahl ausgewählt,
            // damit das Ergebnis nicht immer gleich aussieht.
            std::uniform_int_distribution<> pick(0, candidates.size() - 1);
            int chosen = candidates[pick(rng)];
            char symbol = sudoku.SYMBOLS[chosen];
            sudoku.set(pos.first, pos.second, symbol);
            
            pos = sudoku.next();
        }
        
        // Ist keine freie Zelle mehr vorhanden, ist ein vollständiges Sudoku
        // entstanden und der aktuelle Versuch war erfolgreich.
        if (pos.first == 9 && pos.second == 9) {
            success = true;
        }
    }
    
    return sudoku;
}

Sudoku<9> Generator::removeNumbersUntilUnique(const Sudoku<9>& completed) {
    Sudoku<9> puzzle = completed;
    std::vector<std::pair<std::size_t, std::size_t>> cells;
    
    // Alle Zellen werden in eine Liste geschrieben, damit sie später in
    // zufälliger Reihenfolge bearbeitet werden können.
    for (std::size_t row = 0; row < 9; row++) {
        for (std::size_t col = 0; col < 9; col++) {
            cells.push_back({row, col});
        }
    }
    
    // Die Reihenfolge wird gemischt, damit nicht immer dieselben Felder
    // entfernt werden.
    std::shuffle(cells.begin(), cells.end(), rng);
    
    // Nun wird jede Zahl testweise entfernt und anschließend überprüft,
    // ob das Rätsel weiterhin eindeutig lösbar bleibt.
    for (auto [row, col] : cells) {
        char original = puzzle.get(row, col);
        
        // Das aktuelle Feld wird vorübergehend geleert.
        puzzle.set(row, col, '_');
        
        // Danach zählt der Solver, wie viele Lösungen die neue Stellung hat.
        std::size_t solutions = countSolutions(puzzle);
        
        if (solutions == 1) {
            // Genau eine Lösung bleibt erhalten: Das Entfernen ist erlaubt,
            // und das Feld bleibt leer.
            continue;
        } else {
            // Es gibt keine eindeutige Lösung mehr. Deshalb wird die Zahl
            // wieder eingesetzt.
            puzzle.set(row, col, original);
        }
    }
    
    return puzzle;
}

std::size_t Generator::countSolutions(const Sudoku<9>& sudoku) {
    // Für die Prüfung wird eine Kopie des aktuellen Sudokus an den Solver
    // übergeben, damit der Generator selbst unverändert bleibt.
    Solver solver;
    solver.loadSudoku(sudoku, "/tmp");
    
    // Der Solver wird anschließend ausgeführt und liefert die Anzahl der
    // gefundenen Lösungen zurück.
    return solver.solve();
}
