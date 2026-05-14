#include <pybind11/pybind11.h>
#include "sudoku.hpp"
#include "solver.hpp"
#include "sudoku_generator.hpp"

PYBIND11_MODULE(sudoku_py, m){
    m.doc() = "Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);

    
    pybind11::class_<Solver>(m, "solver")
        .def(pybind11::init())
        .def("solve", &Solver::solve)
        // Lambda-Funktion, um den Dateipfad für base_directory zu vereinfachen
        .def("loadSudoku", [](Solver& s, const Sudoku<9>& ref) {
            return s.loadSudoku(ref, "results");
        });

    
    pybind11::class_<SudokuGenerator>(m, "generator")
        .def(pybind11::init())
        .def("generate", &SudokuGenerator::generate);
}