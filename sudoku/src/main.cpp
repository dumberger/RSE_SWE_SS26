
#include "creator.hpp"

#include <cstdlib>

using namespace std;

int main() {
    std::cout << "Geben Sie bitte die gewünschte Schwierigkeit Ihres Sudokus an (1-10):" << std::endl;
    int difficulty;
    std::cin >> difficulty;

    std::cout << "Eingabe war: " << difficulty << std::endl;
    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();
    Creator creator(directory);
    creator.create();
    
    creator.trim_Sudoku(difficulty);
    return 0;
}