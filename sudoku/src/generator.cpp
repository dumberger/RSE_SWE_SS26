#include "generator.hpp"

#include "solver.hpp"
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>


bool Generator::fill_random(Sudoku<9>& board, std::mt19937& rng)
{
	auto [row, col] = board.next();
	if (row == 9 || col == 9)
	{
		return true;
	}

	std::array<int, 9> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::shuffle(digits.begin(), digits.end(), rng);

	for (int d : digits)
	{
		char symbol = Sudoku<9>::SYMBOLS[d];
		if (!board.set(row, col, symbol))
		{
			continue;
		}

		if (fill_random(board, rng))
		{
			return true;
		}

		board.set(row, col, Sudoku<9>::SYMBOLS[0]);
	}

	return false;
}

std::size_t Generator::count_filled(Sudoku<9>& board)
{
	const char empty = Sudoku<9>::SYMBOLS[0];
	std::size_t filled = 0;

	for (std::size_t r = 0; r < 9; ++r)
	{
		for (std::size_t c = 0; c < 9; ++c)
		{
			if (board.get(r, c) != empty)
			{
				++filled;
			}
		}
	}

	return filled;
}

std::size_t Generator::generate()
{
	std::cout << "generating sudoku..." << std::endl;

	std::random_device rd;
	std::mt19937 rng(rd());

	const char empty = Sudoku<9>::SYMBOLS[0];

	for (int restart = 0; restart < 20; ++restart)
	{
		sudoku = Sudoku<9>{};
		solutions = 0;

		// 1) Vollstandiges gültiges Sudoku erzeugen
		if (!fill_random(sudoku, rng))
		{
			continue;
		}

		// 2) Alle Zellen in zufälliger Reihenfolge durchgehen
		std::vector<int> cells(81);
		std::iota(cells.begin(), cells.end(), 0);
		std::shuffle(cells.begin(), cells.end(), rng);

		// 3) Entfernen nur wenn weiterhin genau eine Lösung existiert
		for (int idx : cells)
		{
			std::size_t row = static_cast<std::size_t>(idx / 9);
			std::size_t col = static_cast<std::size_t>(idx % 9);

			char old_value = sudoku.get(row, col);
			if (old_value == empty)
			{
				continue;
			}

			sudoku.set(row, col, empty);

			Solver solver;
			solver.loadSudoku(sudoku, std::filesystem::current_path());
			std::size_t s = solver.solve();

			if (s != 1)
			{
				// Nicht eindeutig oder unlösbar -> rückgangig
				sudoku.set(row, col, old_value);
			}
		}

		solutions = 1;
		std::cout << "generation complete!" << std::endl;
		return count_filled(sudoku);
	}

	solutions = 0;
	std::cout << "generation failed!" << std::endl;
	return 0;
}

bool Generator::saveSudoku(std::filesystem::path file)
{
	std::ofstream out(file);
	if (!out.good())
	{
		return false;
	}
	printf("saving sudoku to %s...\n", file.string().c_str());

	out << sudoku << std::endl;
	return out.good();
}