#include <filesystem>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "../include/sudoku.hpp"
#include <fstream>
#include <iterator>
#include <regex>
#include <sstream>
#include <filesystem>

using namespace std;

int main() {
   
    Sudoku<9> test;

    test.set(0,0,'5');
    test.set(0,1,'4');
    test.set(0,3,'4');
    test.set(1,0,'6');
    test.set(1,1,'7');
    char symbol=test.get(0,0);

    std:: filesystem::path directory(__FILE__);
    directory= directory.parent_path();


    std::ifstream file(directory.string()+"/input.txt");
    std::ofstream output(directory.string()+"/output.txt");
    output<<test;
    std::stringstream ss;
    ss<< test << "/n";
    Sudoku<9> sudoku_template;
    file >> sudoku_template;
    std::cout << sudoku_template;





    return 0;


    
}
