#include "../include/generator.hpp"
#include "../include/solver.hpp"

Sudoku<9> Generator::generate()
{  
    Generator gen;
    return gen.run();
}

Sudoku<9> Generator::run()
{   
    int currentSolutions = 0;
    
    while (currentSolutions != 1)
    {
        auto [row, col] = getRandomEmptyCell();

        if (row == 9) 
        {
            m_sudoku = Sudoku<9>(); 
            currentSolutions = 0;
            continue;
        }

        char val = getRandomSymbol();

        if (m_sudoku.set(row, col, val))
        {
            currentSolutions = countSolutions();
            if (currentSolutions == 0)
            {
                m_sudoku.set(row, col, m_sudoku.SYMBOLS[0]);
            }
        }
    }

    return m_sudoku;
}

Generator::CellPos Generator::getRandomEmptyCell()
{
    std::vector<Generator::CellPos> emptyCells;

    for (std::size_t row = 0; row < 9; row++)
    {
        for (std::size_t col = 0; col < 9; col++)
        {
            if (m_sudoku.get(row, col) == '_')
            {
                emptyCells.emplace_back(row, col);
            }
        }
    }

    if (emptyCells.empty())
    {
        return {9,9};
    }

    std::uniform_int_distribution<int> dist(0, emptyCells.size() - 1);
    return emptyCells[dist(rng)];
}
    
// würde mit einem getter für die bitsets viel performanter werden
int Generator::getRandomSymbol() 
{
    std::uniform_int_distribution<int> dist(1, 9);
    return m_sudoku.SYMBOLS[dist(rng)];
}

int Generator::countSolutions()
{
    Solver solver;
    solver.loadSudoku(m_sudoku);
    return solver.solve(false);
}
    