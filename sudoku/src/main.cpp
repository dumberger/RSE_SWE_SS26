#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include "sudoku.hpp"

using namespace std;

int main() {
    Sudoku<9> test;

    //__FUNCTION__; // says which function is that
    //__FILE__; // absolute path to this file

    std::filesystem::path directory(__FILE__);
    std::cout << directory.parent_path() << "\n"; // cout -> character output. Displays everything, what is thrown at it. << is insertion operator

    Sudoku<9> sudoku_template;
    std::ofstream output(directory.parent_path().string() + "/template.txt"); // output file stream. Write
    output << sudoku_template; // insert data iinto the stream

    std::ifstream input(directory.parent_path().string() + "/input.txt"); // file stream. Read
    input >> test; // extract data from the stream and store it in copy
    std::cout << test;

    if(input.fail())
    {
        std::cout << "error reading file\n";
    }

    test.next();

    return 0;
}

// myint operator+(myint a, myint b){ example of overloading a operator. Could be done for any operator, when used this class (????)
//     return a - b;
// }