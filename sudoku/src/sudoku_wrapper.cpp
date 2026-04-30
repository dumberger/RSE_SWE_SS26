#include <pybind11/pybind11.h>
#include "../include/sudoku.hpp"

PYBIND11_MODULE(sudoku_py, m) {
    m.doc() = "pybind11 python -> sudoku c++";
    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init<>());
}