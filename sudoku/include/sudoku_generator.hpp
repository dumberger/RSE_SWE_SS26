#pragma once

#include "sudoku.hpp"
#include "solver.hpp"
#include <fstream>
#include <iostream>

class Sudoku_generator{
    private:
        //Sudoku<9> Sudoku_generated;

    public:
        Sudoku<9> Sudoku_generated;
        bool generate_start_Sudoku (){
            //printf("ich bin da");
            std::random_device rd;
            std::mt19937 gen(rd());
            std::string numbers = "123456789";
            
            std::shuffle(numbers.begin(), numbers.end(), gen);
        
            // Erste Zeile setzen
            for (int row = 0; row < 9; ++row) {
                if(!Sudoku_generated.set(row, 0, numbers[row]))
                {
                    return false;
                }
            }
            
            std::uniform_int_distribution<int> variable(0, 8);

            
            std::filesystem::path tempDir = std::filesystem::temp_directory_path() / "sudoku_gen";
            std::filesystem::create_directories(tempDir / "results");

            Solver gen_solver;
            gen_solver.loadSudoku(Sudoku_generated, tempDir);

            gen_solver.solve();

            std::filesystem::path solution = tempDir/"results"/"0.txt";

             if (!std::filesystem::exists(solution)) {
                std::cout << "Fehler: Keine Lösung gefunden!\n";
                return false;
            }

            std::ifstream in(solution);
            in >> Sudoku_generated;

            int deleted=0;
            while(deleted<81)
            {
                int row=variable(gen);
                int col=variable(gen);

                if(Sudoku_generated.get(row, col)=='_'){
                    continue;
                }

                char val_before=Sudoku_generated.get(row, col);

                Sudoku_generated.set(row, col, Sudoku_generated.SYMBOLS[0]);
                Solver gen_solver;
                gen_solver.loadSudoku(Sudoku_generated, tempDir);

                gen_solver.solve();

                if(gen_solver.solutions>1){
                    Sudoku_generated.set(row, col, val_before);
                    break;
                }else {
                    deleted++;
                }
            }

            return true;
            
        }





};