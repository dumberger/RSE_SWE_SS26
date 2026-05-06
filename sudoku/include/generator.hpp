#pragma once

#include "sudoku.hpp"
#include <random>

class Generator {
public:
    Generator();
    
    // Erzeugt ein Sudoku-Rätsel mit genau einer eindeutigen Lösung.
    // Das Ergebnis ist ein teilweise gefülltes Sudoku, das anschließend
    // von einem Solver überprüft werden kann.
    Sudoku<9> generate();
    
private:
    std::mt19937 rng;
    
    // Baut zunächst ein vollständig gültiges Sudoku auf, bevor daraus
    // durch Entfernen einzelner Zahlen ein Rätsel gemacht wird.
    Sudoku<9> generateCompleteSudoku();
    
    // Entfernt Zahlen schrittweise aus dem vollständigen Sudoku und prüft
    // nach jedem Schritt, ob weiterhin genau eine Lösung übrig bleibt.
    Sudoku<9> removeNumbersUntilUnique(const Sudoku<9>& completed);
    
    // Ermittelt, wie viele Lösungen ein bestimmtes Sudoku besitzt.
    // Diese Information nutzt der Generator, um nur eindeutige Rätsel
    // weiterzuverarbeiten.
    std::size_t countSolutions(const Sudoku<9>& sudoku);
};
