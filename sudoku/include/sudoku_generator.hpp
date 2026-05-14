#pragma once

#include "sudoku.hpp"
#include "solver.hpp"
#include <random>
#include <vector>
#include <algorithm>

class SudokuGenerator {
public:
    Sudoku<9> generate() {
        Sudoku<9> current_sudoku;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::string chars = "123456789";

        while(true) { //Felder die leer sind befüllen
            std::vector<std::pair<int, int>> empty_cells;
            for(int row = 0; row < 9; ++row) {
                for(int col = 0; col < 9; ++col) {
                    if(current_sudoku.get(row, col) == Sudoku<9>::SYMBOLS[0]) {
                        empty_cells.push_back({row, col});
                    }
                }
            }
            if(empty_cells.empty()) break; // Wenn kein leeres Feld --> aufhören

            //Feldwahl
            int random_index = gen() % empty_cells.size(); // gen() = Zufallszahl; % Modulo
            int row = empty_cells[random_index].first;
            int col = empty_cells[random_index].second;

            //Mischen
            std::shuffle(chars.begin(), chars.end(), gen);
            bool value_placed = false;
            
            //Zahlen nacheinander ausprobieren
            for (int i = 0; i < 9; i++) {
                char c = chars[i];
                
                if (current_sudoku.set(row, col, c)) { // Prüfen auf Sudoku-Regeln 
                    
                    Solver solver;// Solver starten
                    solver.loadSudoku(current_sudoku, "results"); 
                    int sol = solver.solve();

                    if (sol == 1) {
                        return current_sudoku; //Deffinierte Lösung, gut! 
                    } 
                    
                    if (sol > 1) {
                        value_placed = true; //lösbar, aber nicht eindeutig
                        break; 
                    } 
                    
                    current_sudoku.set(row, col, Sudoku<9>::SYMBOLS[0]); //keine Lösung, 0 setzen
                }
            }
            
            if (value_placed == false) {
                current_sudoku = Sudoku<9>(); // Leeres Sudoku erzeugen
            }
        }

        return current_sudoku; 
        
    } 
};