#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>
#include "solver.hpp"
#include "sudoku.hpp"
#include "sudoku_generator.hpp"

PYBIND11_MODULE(sudoku_py, m){
    m.doc()="Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);
    
    pybind11::class_<Solver>(m, "Solver")
        .def(pybind11::init())
        .def("solve", &Solver::solve)
        .def("loadSudoku", pybind11::overload_cast<std::filesystem::path>(&Solver::loadSudoku))
        .def("loadSudoku", pybind11::overload_cast<const Sudoku<9>&, std::filesystem::path>(&Solver::loadSudoku))
        .def("solve_cell", &Solver::solve)
        .def_readwrite("solutions", &Solver::solutions);

    pybind11::class_<Sudoku_generator>(m, "Sudoku_generator")
        .def(pybind11::init())
        .def("generate_start_Sudoku", &Sudoku_generator::generate_start_Sudoku)
        .def_readwrite("Sudoku_generated", &Sudoku_generator::Sudoku_generated);


}       