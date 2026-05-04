#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>
#include "sudoku.hpp"


PYBIND11_MODULE(sudoku_py, m) {
    m.doc() = "Sudoku wrapper for Python"; // optional module docstring

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init<>())
        .def("set", &Sudoku<9>::set, "Set a cell value")
        .def("get", &Sudoku<9>::get, "Get a cell value")
        .def("next", &Sudoku<9>::next);
    

}

// HÜ GUI in Python get set etc pygame oder so 