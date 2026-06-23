#include "sudoku.hpp"
#include <cmath>
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

using namespace std;

TEST(Halaa222, field_empty_at_first) {
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0,0), '_'); //oben
    EXPECT_EQ(sudoku.get(0,1), '_');
    EXPECT_EQ(sudoku.get(1,0), '_');
    EXPECT_EQ(sudoku.get(4,4), '_'); //mitte
    EXPECT_EQ(sudoku.get(3,4), '_');
    EXPECT_EQ(sudoku.get(4,5), '_');
    EXPECT_EQ(sudoku.get(8,8), '_'); //unten
    EXPECT_EQ(sudoku.get(7,8), '_');
    EXPECT_EQ(sudoku.get(8,7), '_');
}

TEST(Halaa222, set_get_functions) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_TRUE(sudoku.set(1,2,'3'));
    EXPECT_EQ(sudoku.get(1,1), '8');
    EXPECT_EQ(sudoku.get(1,2), '3');
}

TEST(Halaa222, cell_does_not_affect_others) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    EXPECT_EQ(sudoku.get(1,1), '8');
    EXPECT_EQ(sudoku.get(1,2), '_');
    EXPECT_EQ(sudoku.get(3,2), '_');
}

TEST(Halaa222, overwrite_cell) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_TRUE(sudoku.set(1,1,'3'));
    EXPECT_EQ(sudoku.get(1,1), '3');
}

TEST(Halaa222, valid_symbol) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_TRUE(sudoku.set(4,4,'5'));
}

TEST(Halaa222, invalid_symbol) {
    Sudoku<9> sudoku;
    ASSERT_FALSE(sudoku.set(2,2,'x'));
    ASSERT_FALSE(sudoku.set(1,3,'.'));
    EXPECT_EQ(sudoku.get(2,2), '_');
}

TEST(Halaa222, invalid_symbol_cannot_overwrite_cell) {
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(1,1,'8'));
    ASSERT_FALSE(sudoku.set(1,1,'x'));
    ASSERT_FALSE(sudoku.set(1,1,'.'));
    EXPECT_EQ(sudoku.get(1,1), '8');
}

TEST(Halaa222, out_of_cell_index) {
    Sudoku<9> sudoku;
    ASSERT_FALSE(sudoku.set(9, 0, '5'));
    ASSERT_FALSE(sudoku.set(0, 9, '5'));
}

TEST(Halaa222, alphabetic_for_larger_sudoku) {
    Sudoku<16> sudoku;

    ASSERT_TRUE(sudoku.set(0, 0, 'A'));
    EXPECT_EQ(sudoku.get(0, 0), 'A');
}

TEST(adrianbier, initialize) { //neues sudoku korrekt mit dem symbol für 0 gefüllt ist.
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0, 0), '_');
    EXPECT_EQ(sudoku.get(8, 8), '_');
}


TEST(adrianbier, set_and_get_value) { //gültige werte setzen und abfragen, set()=true wenn richtig
    Sudoku<9> sudoku;
    EXPECT_TRUE(sudoku.set(0, 0, '5')); 
    EXPECT_EQ(sudoku.get(0, 0), '5');
}


TEST(adrianbier, reject_invalid) {// set() sollte das erkennen und 'false' zurückgeben.
    Sudoku<9> sudoku;  
    EXPECT_FALSE(sudoku.set(0, 0, 'Z'));
    EXPECT_EQ(sudoku.get(0, 0), '_');
}


TEST(adrianbier, out_of_grid) {// index 9 ist bei größe 9 ungültig, da 0-8
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(9, 0, '1'));
    EXPECT_FALSE(sudoku.set(0, 9, '1'));
}


TEST(adrianbier, template_16x16) {//template-flexibilität prüfen
    Sudoku<16> sudoku;
    EXPECT_TRUE(sudoku.set(15, 15, 'F'));
    EXPECT_EQ(sudoku.get(15, 15), 'F');
}

TEST(Edadom, empty_field_returns_underscore) {
    // Neues Sudoku ist an allen Positionen leer ('_').
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0, 0), '_');
    EXPECT_EQ(sudoku.get(8, 8), '_');
}

TEST(Edadom, set_and_get_valid_value) {
    // Gueltigen Wert setzen und korrekt wieder auslesen.
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(0, 0, '5'));
    EXPECT_EQ(sudoku.get(0, 0), '5');
}

TEST(Edadom, set_rejects_out_of_bounds_position) {
    // Ungueltige Koordinaten (>= 9) muessen abgelehnt werden.
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(9, 0, '1'));
    EXPECT_FALSE(sudoku.set(0, 9, '1'));
}

TEST(Edadom, set_rejects_invalid_symbol) {
    // Nicht erlaubtes Symbol darf nicht gesetzt werden.
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(0, 0, 'X'));
    EXPECT_EQ(sudoku.get(0, 0), '_');
}

TEST(Edadom, set_rejects_row_conflict) {
    // Gleiche Zahl in derselben Zeile muss einen Konflikt ausloesen.
    Sudoku<9> sudoku;
    ASSERT_TRUE(sudoku.set(0, 0, '7'));
    EXPECT_FALSE(sudoku.set(0, 4, '7'));
}

// Test 1: Prüfen, ob ein neues Sudoku-Feld erstellt und mit 0 ("_") befüllt wird
TEST(PeterGrininger, InitialFieldIsEmpty) {
    Sudoku<9> s;
    for (size_t r = 0; r < 9; r++) {
        for (size_t c = 0; c < 9; c++) {
            EXPECT_EQ(s.get(r, c), '_'); //Erwartung "_" = 0 an jedem Platz
        }
    }
}

// Test 2: Setzen und Lesen eines gültigen Wertes   ----> muss noch in der sudoku.hpp implementiert werden
TEST(PeterGrininger, SetAndGetValidValue) {
    Sudoku<9> s;
    EXPECT_TRUE(s.set(0, 0, '5'));
    EXPECT_EQ(s.get(0, 0), '5');
}

// Test 3: Ungültige Symbole
TEST(PeterGrininger, RejectInvalidSymbol) {
    Sudoku<9> s;
    EXPECT_FALSE(s.set(1, 1, '!')); // Bspw. ein ! soll nicht eingegeben werden
}

// Test 4: Out-of-Bounds Zugriff (Reihe/Spalte außerhalb von N)
TEST(PeterGrininger, OutOfBoundsAccess) {
    Sudoku<9> s;
    // Reihe 10 existiert bei einem 9x9 Sudoku nicht
    EXPECT_FALSE(s.set(10, 0, '1'));
    EXPECT_FALSE(s.set( 0, 10, '1'));
}

// Test 5: Überschreiben eines Wertes
TEST(PeterGrininger, OverwriteValue) {
    Sudoku<9> s;
    // Wert schreiben
    s.set(4, 4, '1');
    EXPECT_EQ(s.get(4, 4), '1');
    // Wert wieder überschreiben
    s.set(4, 4, '9');
    EXPECT_EQ(s.get(4, 4), '9');
}

TEST (BastHalb, SET)
{
    Sudoku<9> sudoku;
    EXPECT_TRUE(sudoku.set(0, 0, '4'));
    EXPECT_TRUE(sudoku.set(0, 1, '3'));
    EXPECT_TRUE(sudoku.set(0, 0, '5')); // Cell already occupied
    EXPECT_FALSE(sudoku.set(0, 2, '5')); // Duplicate in row
    EXPECT_FALSE(sudoku.set(1, 0, '5')); // Duplicate in column
    EXPECT_FALSE(sudoku.set(1, 1, '5')); // Duplicate in box
}
TEST (BastHalb, GET)
{
    Sudoku<9> sudoku;
    sudoku.set(0, 0, '5');
    sudoku.set(0, 1, '3');
    EXPECT_EQ(sudoku.get(0, 0), '5');
    EXPECT_EQ(sudoku.get(0, 1), '3');
    EXPECT_EQ(sudoku.get(0, 2), '_'); // Empty cell
}
TEST (BastHalb, InvalidInput)
{
    Sudoku<9> sudoku;
    EXPECT_FALSE(sudoku.set(0, 0, '0')); // Invalid symbol
    EXPECT_FALSE(sudoku.set(0, 0, 'A')); // Invalid symbol for 9x9
    EXPECT_FALSE(sudoku.set(9, 0, '5')); // Out of bounds
    EXPECT_FALSE(sudoku.set(0, 9, '5')); // Out of bounds
}
TEST (BastHalb, EmptyCells)
{
    Sudoku<9> sudoku;
    EXPECT_EQ(sudoku.get(0, 0), '_'); // Empty cell
    EXPECT_EQ(sudoku.get(8, 8), '_'); // Empty cell
}
// only set and get tests
TEST (BastHalb, initialization)
{
    Sudoku<9> sudoku;
    for (size_t row = 0; row < 9; ++row) {
        for (size_t col = 0; col < 9; ++col) {
            EXPECT_EQ(sudoku.get(row, col), '_'); // All cells should be empty
        }
    }
}
TEST (BastHalb, Valid_input)
{
    Sudoku<9> sudoku;
 for(size_t i = 0; i < 9; ++i) {
        EXPECT_TRUE(sudoku.set(0, i, '1' + i)); // Set valid symbols in the first row
    }
}

// Check cell after creation
TEST(KissEmil_RSE, empty_at_init)
{
    Sudoku<9> test;
    for(std::size_t row = 0; row < 9; row++) {
        for(std::size_t col = 0; col < 9; col++) {
            EXPECT_EQ(test.get(row, col), '_');
        }
    }
}

// Set a cell and get the cell
TEST(KissEmil_RSE, set_and_get)
{
    Sudoku<9> test;
    EXPECT_TRUE(test.set(4, 4, '9'));
    EXPECT_EQ(test.get(4, 4), '9');
}

// Set something that is valid/invalid for Sudoku
TEST(KissEmil_RSE, set_for_sudoku)
{
    Sudoku<9> test;
    EXPECT_FALSE(test.set(0, 0, 'x'));
    EXPECT_FALSE(test.set(1, 1, '!'));

    EXPECT_TRUE(test.set(1, 1, '1'));
    EXPECT_TRUE(test.set(1, 1, '9'));
}

// Set cells that are out of set bounds
TEST(KissEmil_RSE, set_out_of_bounds)
{
    Sudoku<16> test;
    EXPECT_FALSE(test.set(16, 0, '5'));
    EXPECT_FALSE(test.set(0, 16, '5'));
    EXPECT_FALSE(test.set(16, 16, '5'));
}

// Change the same cell multiple times, also check directly after creation
TEST(KissEmil_RSE, change_entry_multiple)
{
    Sudoku<9> test;
    EXPECT_EQ(test.get(4, 4), '_');

    test.set(4, 4, '5');
    EXPECT_EQ(test.get(4, 4), '5');

    test.set(4, 4, '1');
    EXPECT_EQ(test.get(4, 4), '1');

    test.set(4, 4, '9');
    EXPECT_EQ(test.get(4, 4), '9');
}

// checking if sudoku has correctly initialized. All field should be equal to "_"
TEST(DenisTheStudentAT, CheckInitialEmptyField){
    Sudoku<3> s;
    EXPECT_EQ(s.get(0, 0), '_');
    EXPECT_EQ(s.get(0, 1), '_');
    EXPECT_EQ(s.get(0, 2), '_');
    
    EXPECT_EQ(s.get(1, 0), '_');
    EXPECT_EQ(s.get(1, 1), '_');
    EXPECT_EQ(s.get(1, 2), '_');
    
    EXPECT_EQ(s.get(2, 0), '_');
    EXPECT_EQ(s.get(2, 1), '_');
    EXPECT_EQ(s.get(2, 2), '_');
    
}

// checkin if a value is set if the get method gets the right value back
TEST(DenisTheStudentAT, SetAndGetValidValue) {
    Sudoku<9> s;
    EXPECT_TRUE(s.set(0, 0, '5')); 
    EXPECT_EQ(s.get(0, 0), '5');
}

// checking if the symbols are working correctly 
TEST(DenisTheStudentAT, LargeSudokuWithLetters){
    Sudoku<16> s;

    EXPECT_TRUE(s.set(15, 15, 'A'));
    EXPECT_EQ(s.get(15, 15), 'A');
}

// checking out of boundary szenario
TEST(DenisTheStudentAT, OutOfBoundsHandling){
    Sudoku<9> s;

    EXPECT_FALSE(s.set(9, 0, '1'));
    EXPECT_FALSE(s.set(0, 9, '1'));
}

// checking if sudoku allows to enter symols which are meant for bigger fields or doesn't even exist
TEST(DenisTheStudentAT, InvalidSymbolProtection) {
    Sudoku<9> s;
    EXPECT_FALSE(s.set(0, 0, 'Z')); // field too small for this letter
    EXPECT_FALSE(s.set(0, 0, '#')); // not existing
    EXPECT_EQ(s.get(0, 0), '_'); // value in this row and col should stay the same
}

TEST(schaetztho, get_on_empty) {
  Sudoku<9> sudoku;
  ASSERT_EQ(sudoku.get(0, 0), '_');
}

TEST(schaetztho, get_on_filled) {
  Sudoku<9> sudoku;
  sudoku.set(0, 0, '5');
  ASSERT_EQ(sudoku.get(0, 0), '5');
}

TEST(schaetztho, get_out_of_bounds) {
  Sudoku<9> sudoku;
  ASSERT_EQ(sudoku.get(0, 10), '_');
  ASSERT_EQ(sudoku.get(10, 0), '_');
}

// set() Tests
TEST(schaetztho, set_out_of_bounds) {
  Sudoku<9> sudoku;
  char value = '5';
  ASSERT_FALSE(sudoku.set(10, 9, value));
  ASSERT_FALSE(sudoku.set(9, 10, value));
}

TEST(schaetztho, set_not_a_symbol) {
  Sudoku<9> sudoku;
  char value = '!';
  ASSERT_FALSE(sudoku.set(0, 0, value));
  ASSERT_FALSE(sudoku.set(0, 0, value));
}

TEST(erikst21, set_value)
{
    Sudoku<9> sudoku;

    EXPECT_TRUE(sudoku.set(2, 3, '7'));
}

TEST(erikst21, get_value)
{
    Sudoku<9> sudoku;
    sudoku.set(2, 3, '7');

    EXPECT_EQ(sudoku.get(2, 3), '7');
}

TEST(erikst21, initialize)
{
    Sudoku<9> sudoku;

	for (std::size_t row = 0; row < 9; ++row)
	{
		for (std::size_t col = 0; col < 9; ++col)
		{
			EXPECT_EQ(sudoku.get(row, col), '_');
		}
	}
}

TEST(erikst21, out_of_bounds)
{
	Sudoku<9> sudoku;

	EXPECT_FALSE(sudoku.set(9, 0, '1'));
}

TEST(erikst21, invalid_symbol)
{
	Sudoku<9> sudoku;

	EXPECT_FALSE(sudoku.set(1, 1, '0'));
	EXPECT_EQ(sudoku.get(1, 1), '_');
}

///get a value
TEST(madtic, get_value) {
    Sudoku<9> sudoku;
    char c = sudoku.get(8,8);
    ASSERT_EQ(c, '_');
}

///set a value
TEST(madtic, set_value) {
    Sudoku<9> sudoku;
    char c = '7';
    ASSERT_TRUE(sudoku.set(8,8,c));
    EXPECT_EQ(sudoku.get(8,8), c);
}

///print the sudoku
/*TEST(madtic, print_sudoku) {
    Sudoku<9> sudoku;
    std::ostringstream oss;
    soduku.print(oss);
    EXPECT_EQ(oss.str(), "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n"
                         "123456789\n");
}*/

///test is solved row
TEST(madtic, check_solved_row) {
    constexpr int size = 9;
    Sudoku<size> sudoku;
    for (int i = 0; i < size; i++) {
        ASSERT_TRUE(sudoku.set(0,i,'1'+i));
    }
}


///test is solved
TEST(madtic, check_solved) {
    constexpr int size = 9;
    Sudoku<size> sudoku;

    std::filesystem::path directory(__FILE__);
    directory = directory.parent_path();

    std::ifstream input(directory.string() + "/valid9x9.txt");
    input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    ASSERT_TRUE(input.good());

    Sudoku<9> completed;
    input >> completed;
    //ASSERT_TRUE(completed.solve());
}

TEST(christoph08, init_empty)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    for (std::size_t row = 0; row < N; row++) 
    {
        for (std::size_t col = 0; col < N; col++) 
        {
            EXPECT_EQ(sudoku.get(row, col), '_');
        }
    }    
}

// setting a cell to a valid character should return true and getting it should return the same character
TEST(christoph08, set_get_char)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(2, 2, '5'));
    EXPECT_EQ(sudoku.get(2, 2), '5'); 
}

// setting multiple cells with valid characters and getting it should return the last character set
TEST(christoph08, multiple_set_get)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    for (std::size_t i = 1; i < 6; i++)
    {
        ASSERT_TRUE(sudoku.set(i, i, '0' + i));   
    }

    for (std::size_t i = 1; i < 6; i++)
    {
        EXPECT_EQ(sudoku.get(i, i), '0' + i);
    }
    EXPECT_EQ(sudoku.get(0, 0), '_');
}

// setting a cell to a valid character at the edge of the Sudoku should work correctly
TEST(christoph08, set_get_edge_index)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(0, 0, '1'));
    ASSERT_TRUE(sudoku.set(N - 1, N - 1, '9'));

    EXPECT_EQ(sudoku.get(0, 0), '1');
    EXPECT_EQ(sudoku.get(N - 1, N - 1), '9');
}

// setting a cell to a valid character and then overwriting it with another valid character should update the value correctly
TEST(christoph08, overwrite_value)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(1, 1, '3'));
    ASSERT_TRUE(sudoku.set(1, 1, '7'));

    EXPECT_EQ(sudoku.get(1, 1), '7');
}

// setting a cell to a valid character should not affect other cells
TEST(christoph08, set_independent)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    ASSERT_TRUE(sudoku.set(4, 4, '8'));

    EXPECT_EQ(sudoku.get(4, 4), '8');
    EXPECT_EQ(sudoku.get(4, 5), '_');
    EXPECT_EQ(sudoku.get(5, 4), '_');
}

// setting a cell to an invalid character should return false and not change the value of the cell
TEST(christoph08, set_invalid_char)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    EXPECT_FALSE(sudoku.set(0, 0, '!'));
    EXPECT_FALSE(sudoku.set(0, 0, ';'));   
    EXPECT_FALSE(sudoku.set(0, 0, 'c'));

    EXPECT_EQ(sudoku.get(0, 0), '_');
}

// setting a cell to a character that is valid for a smaller Sudoku but not for the current size should return false and not change the value of the cell
TEST(christoph08, set_char_out_of_range)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;

    EXPECT_FALSE(sudoku.set(0, 0, 'A'));
    EXPECT_FALSE(sudoku.set(0, 0, 'B'));
    EXPECT_EQ(sudoku.get(0, 0), '_');
}

// setting a cell out of bounds should return false
TEST(christoph08, set_index_out_of_bounds)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;
    
    EXPECT_FALSE(sudoku.set(N, 0, '5'));
    EXPECT_FALSE(sudoku.set(0, N, '5'));
    EXPECT_FALSE(sudoku.set(N, N, '5'));
}

// getting a cell out of bounds should throw an exception
TEST(christoph08, get_index_out_of_bounds)
{
    constexpr int N = 9;
    Sudoku<N> sudoku;
    
    EXPECT_THROW(sudoku.get(N, 0), std::out_of_range);
    EXPECT_THROW(sudoku.get(0, N), std::out_of_range);
    EXPECT_THROW(sudoku.get(N, N), std::out_of_range);
}

// setting and getting values in a larger Sudoku should work correctly
TEST(christoph08, set_get_16x16)
{
    Sudoku<16> sudoku;

    ASSERT_TRUE(sudoku.set(0, 0, 'A'));
    EXPECT_EQ(sudoku.get(0, 0), 'A');

    ASSERT_TRUE(sudoku.set(15, 15, 'G'));
    EXPECT_EQ(sudoku.get(15, 15), 'G');
}

TEST(dumberger, different_sudoku_sizes)
{
    Sudoku<1> sudoku1;
    Sudoku<2> sudoku2;
    Sudoku<3> sudoku3;
    Sudoku<4> sudoku4;
    Sudoku<5> sudoku5;
    Sudoku<6> sudoku6;
    Sudoku<7> sudoku7;
    Sudoku<8> sudoku8;
    Sudoku<9> sudoku9;
    Sudoku<16> sudoku16;
    Sudoku<25> sudoku25;
    Sudoku<36> sudoku36;
    Sudoku<49> sudoku49;    
    SUCCEED();
}

template <typename T>
class dumberger_diff_size : public ::testing::Test {};

using Sizes = ::testing::Types<
    std::integral_constant<int, 1>,
    std::integral_constant<int, 4>,
    std::integral_constant<int, 9>,
    std::integral_constant<int, 16>,
    std::integral_constant<int, 25>
>;

TYPED_TEST_SUITE(dumberger_diff_size, Sizes);

TYPED_TEST(dumberger_diff_size, empty_on_init) {
    constexpr int N = TypeParam::value;
    Sudoku<N> cud;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            EXPECT_EQ(cud.get(r, c), '_');
        }
    }
}

std::string valid_symbol_list = "_123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

TYPED_TEST(dumberger_diff_size, accept_all_valid_symbols) {
    constexpr int N = TypeParam::value;
    Sudoku<N> cud;

    for (int i = 0; i < N+1; ++i) {
        EXPECT_TRUE(cud.set(0, 0, valid_symbol_list[i]));
    }
}

TYPED_TEST(dumberger_diff_size, reject_invalid_symbols) {
    constexpr int N = TypeParam::value;
    Sudoku<N> cud;

    std::string invalid_symbols = "abcdefghijklmnopqrstuvwxyz,.!()[]{}\n ";

    invalid_symbols += &valid_symbol_list[N+1]; //some pointer magic

    for (auto c : invalid_symbols) {
        EXPECT_FALSE(cud.set(0, 0, c));
    }
}

TYPED_TEST(dumberger_diff_size, solves_correctly) {
    constexpr int N = TypeParam::value;
    Sudoku<N> cud;

    constexpr int k = sqrt(N);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            int solve = (r * k + r / k + c) % N + 1;
            EXPECT_TRUE(cud.set(r, c, valid_symbol_list[solve]));
            EXPECT_EQ(cud.get(r, c), valid_symbol_list[solve]);
        }
    }
}
