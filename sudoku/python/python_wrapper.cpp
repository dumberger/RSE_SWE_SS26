#include <pybind11/pybind11.h>
#include "sudoku.hpp"
#include "generator.hpp"
#include "solver.hpp"

PYBIND11_MODULE(sudoku_py, m){
    m.doc() = "Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next)
        .def("solve", [](Sudoku<9>& sudoku){
            Solver solver;
            solver.loadSudoku(sudoku, std::filesystem::current_path());
            solver.solve_for_ui();
            sudoku = solver.getSudoku();
        })
        .def("generate", [](Sudoku<9>& sudoku){
            Generator generator;
            generator.generate();
            sudoku = generator.getSudoku();
        });
}