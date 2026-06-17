#include <pybind11/pybind11.h>
#include <pybind11/stl/filesystem.h>

#include "sudoku.hpp"
#include "solver.hpp"
#include "generator.hpp"

namespace py = pybind11;

PYBIND11_MODULE(sudoku_py, m)
{
    m.doc() = "Sudoku wrapper for python";

    py::class_<Sudoku<9>>(m, "sudoku")
        .def(py::init<>())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);

    py::class_<Solver>(m, "solver")
        .def(py::init<>())
        .def("solve", &Solver::solve, py::arg("save_solutions") = false)
        .def("loadSudoku",
             py::overload_cast<std::filesystem::path>(&Solver::loadSudoku))
        .def("loadSudoku",
             py::overload_cast<const Sudoku<9>&,std::filesystem::path>(&Solver::loadSudoku),
             py::arg("reference"),
             py::arg("base_path") = std::filesystem::path{})

        .def("getFirstSolution", &Solver::getFirstSolution);

    m.def("generate", &Generator::generate);
}