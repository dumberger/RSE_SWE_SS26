#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>
#include "sudoku.hpp"
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
        .def(pybind11::init())
        .def("load_sudoku", pybind11::overload_cast<std::filesystem::path>(&Solver::loadSudoku))
        .def("solve", &Solver::solve)
        .def("get_sudoku", &Solver::getSudoku)
        // Also include the attributes for muting and target solutions
        .def("mute_solver", &Solver::mute_solver)
        .def_readwrite("target_solutions", &Solver::target_solutions);
 
    pybind11::class_<Generator>(m, "generator")
        .def(pybind11::init())
        .def("load_sudoku", pybind11::overload_cast<std::filesystem::path>(&Generator::loadSudoku))
        .def("generate", &Generator::generate)
        .def("get_sudoku", &Generator::getSudoku);
}
