#include <pybind11/pybind11.h>
#include "sudoku.hpp"

#include <pybind11/stl/filesystem.h>
#include "solver.hpp"
#include "generator.hpp"


PYBIND11_MODULE(sudoku_py, m){
    m.doc() = "Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);

    pybind11::class_<Solver>(m, "solver")
        .def(pybind11::init<>())
        .def("loadSudokuFromObject",
             pybind11::overload_cast<const Sudoku<9>&, std::filesystem::path>(&Solver::loadSudoku))
        .def("solve", &Solver::solve)
        .def("getSudoku", &Solver::getSudoku)
        .def("solveOne", &Solver::solveOne);

    pybind11::class_<Generator>(m, "generator")
        .def(pybind11::init<>())
        .def("generateSudoku", &Generator::generateSudoku);
}