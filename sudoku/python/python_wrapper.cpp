#include <pybind11/pybind11.h>
#include "solver.hpp"
#include "sudoku.hpp"
#include "generator.hpp"

PYBIND11_MODULE(sudoku_py, m){ // because of the version pybind11::mod_gll_not_used() is not used. Earlier version had to use that
    m.doc() = "Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init<>())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);
    
    pybind11::class_<Solver>(m, "solver")
        .def(pybind11::init<>())
        .def("solve", &Solver::solve)
        .def("getSudoku", &Solver::getSudoku)
        .def("setSudoku", &Solver::setSudoku);

    pybind11::class_<Generator>(m, "generator")
        .def(pybind11::init<>())
        .def("getSudoku", &Generator::getSudoku)
        .def("generate", &Generator::GenerateSudoku);
}
