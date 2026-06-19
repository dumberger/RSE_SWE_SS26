#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>
#include "sudoku.hpp"
#include "solver.hpp"
#include "creator.hpp"

namespace py = pybind11;

PYBIND11_MODULE(sudoku_py, m){
    m.doc() = "Sudoku wrapper for python";

    // Sudoku Klasse
    py::class_<Sudoku<9>>(m, "sudoku")
        .def(py::init<>())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);

    //Solver Klasse
    py::class_<Solver>(m, "Solver")
        .def(py::init<>())
        .def_readwrite("sudoku", &Solver::sudoku) // Für Zugriff auf das Sudoku Feld
        .def("loadSudoku", py::overload_cast<const Sudoku<9>&, std::filesystem::path>(&Solver::loadSudoku))
        .def("solve", &Solver::solve);

    
    //Creator Klasse
    py::class_<Creator>(m,"Creator")
        .def(py::init<>())
        .def("create", &Creator::create);
    
}