#include <iostream>
#include "../includes/sudoku.hpp"
using namespace std;


int main() {
    Sudoku<9> test;
    test.set(0, 0, '5');
    cout << "Sudoku initialized" << endl;
    return 0;
}   

// HÜ: in list ccp tamplatess ergänzen * 5unit tests für sudoku
// masterbranch in edadom branch konflikte lösen und dann in master mergen undheaderfils? 