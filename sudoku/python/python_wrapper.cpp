#include <pybind11/pybind11.h>
#include "sudoku.hpp"
#include "solver.hpp"
#include "sudokuGenerator.hpp"
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>

PYBIND11_MODULE(sudoku_py, m){
    m.doc() = "Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);

    pybind11::class_<Solver>(m, "solver") 
        .def(pybind11::init())
        .def("loadSudoku", pybind11::overload_cast<const Sudoku<9>&, std::filesystem::path>(&Solver::loadSudoku))
        .def("solve", &Solver::solve)
        .def("get_sudoku", &Solver::getSudoku) 
        .def("mute_solver", &Solver::mute_solver)
        .def_readwrite("target_solutions", &Solver::target_solutions);



    pybind11::class_<SudokuGenerator>(m, "sudoku_generator")
            .def(pybind11::init())
            .def("load_sudoku", pybind11::overload_cast<const Sudoku<9>&, std::filesystem::path>(&SudokuGenerator::loadSudoku))
            .def("generate", &SudokuGenerator::generate)
            .def("get_sudoku", &SudokuGenerator::getSudoku);   

}
