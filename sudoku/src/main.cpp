#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include "sudoku.hpp"

using namespace std;

int main() {
    Sudoku<9> test;

    test.set(0, 0, '1');
    test.set(0, 1, '2');
    test.set(0, 0, '2');
    test.set(0, 3, '4');

    //__FUNCTION__; // says which function is that
    //__FILE__; // absolute path to this file

    std::filesystem::path directory(__FILE__);
    std::cout << directory.parent_path();

    std::ofstream output = directory.parent_path();
    output << test;
    std::ifstream input("input.txt");
    Sudoku<9> copy;

    input >> copy;
    std::cout << copy;
    
    if(!input.good())
    {
        std::cout << "error reading file\n";
    }



    return 0;
}

// myint operator+(myint a, myint b){ example of overloading a operator. Could be done for any operator, when used this class (????)
//     return a - b;
// }