#include "generator.hpp"
#include <iostream>
#include <iterator>
#include <random>
#include "sudoku.hpp"
#include "solver.hpp"
#include <fstream>

bool Generator::generate(){
    Solver solver;
    std::mt19937 mt(time(nullptr));
    int randNumber = 1 + mt() % 8;

    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    prefillSudoku();
    int failedAttempts = 0;
    int solutions = solver.solve();
    while(solutions == 0){
        sudoku.clear();
        prefillSudoku();
        solver.loadSudoku(sudoku);
        //std::cout << sudoku << std::endl;
        solutions = solver.solve();
        
    }
    //solver.loadSudoku(directory / "input.txt");
    std::cout << sudoku << std::endl;
    if(loadSudoku(directory / "results" / "0.txt")){
        std::cout << "loaded sudoku 0.txt correctly" << std::endl;
    }
    std::cout << sudoku << std::endl;
    
    writeGeneratedSudoku();
    return true;
}

void Generator::writeGeneratedSudoku(){
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    std::ofstream file(directory / "input.txt");
    file << sudoku;
}

void Generator::prefillSudoku(){
    std::mt19937 mt(time(nullptr));
        for(int fieldsSet = 0; fieldsSet < 25; fieldsSet++){
        char value = sudoku.SYMBOLS[1 + mt() % 9];
        if(!sudoku.set(mt() % 9, mt() % 9, value)){
            fieldsSet--;
        }
    }
}


std::pair<std::size_t, std::size_t> Generator::next(){
    std::pair<std::size_t, std::size_t> resultField = {9,9};
    std::vector<std::pair<int, int>> missing;
    std::array<int, 9> freeInRows{};
    std::array<int, 9> freeInCols{};
    std::array<int, 9> freeInBlks{};
    int blkID;
    
    int blkSize = std::sqrt(9);
    unsigned int counter = 0;
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(sudoku.get(r, c) == '_'){
                counter++;
                freeInCols[c]++;
                blkID = (r / blkSize) * blkSize + (c / blkSize);
                freeInBlks[blkID]++;
                missing.push_back({r,c});
            }
        } 
        freeInRows[r] = counter;
        counter = 0;
    }

    int bestField = 1;
    for(auto field : missing){
        int fR = freeInRows[field.first];
        int fC = freeInCols[field.second];
        int fB = freeInBlks[(field.first / blkSize) * blkSize + (field.second / blkSize)];
        int fieldValue = fR + fC + fB;
        if(fieldValue >= bestField && fieldValue != 0){
            bestField = fieldValue;
            resultField = {field.first, field.second};
        }
    }
    return resultField;
}

bool Generator::loadSudoku(std::filesystem::path file) { 
    if(!std::filesystem::exists(file)) {
        return false;
    }
    std::ifstream input(file);
    input >> sudoku;
    if (!input.fail()) {
        // base_directory = file.parent_path();
        // std::filesystem::create_directory(base_directory / "results");
        return true;
    }
    return false;
 }