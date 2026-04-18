#include <filesystem>
#include <iostream>
#include "../include/sudoku.hpp"
#include <fstream>
#include <strstream>
#include <strstream>
#include <system_error>

using namespace std;

int main() {
    // Sudoku<9> test;

    // test.set(0, 0, '1');
    // test.set(0, 1, '2');
    // test.set(0, 0, '2');
    // test.set(0, 3, '4');
    // char symbol = test.get(0, 0);
    // printf("%c\n\n",symbol);

    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    std::ofstream output(directory.string()+"/template.txt");
    Sudoku<9> sudoku_template;
    output << sudoku_template;

    std::ifstream file(directory.string()+"/input.txt");
    // std::strstream ss;
    // ss << test << "\n";
    Sudoku<9> copy;
    file >> copy;
    std::cout << copy;
    if(!file.good()){
        std::cout<<"error reading file \n";
    }

    return 0;
}
