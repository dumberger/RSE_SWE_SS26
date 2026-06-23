#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>
#include "generator.hpp"
#include "solver.hpp"
#include "sudoku.hpp"

PYBIND11_MODULE(sudoku_py, m){
    m.doc() = "Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);

    pybind11::class_<Generator>(m, "Generator")
        .def(pybind11::init<>())
        .def("generate", &Generator::generate,
             pybind11::arg("prefilled"))
        /*.def("generateSudoku", [](Generator &self, int prefilled, unsigned int seed) {
            std::mt19937 gen(seed);
            return self.generateSudoku(prefilled, gen);
        }, pybind11::arg("prefilled"), pybind11::arg("seed") = 42)*/;

    pybind11::class_<Solver>(m, "Solver")
        .def(pybind11::init<>())
        .def("loadThenSolve", &Solver::loadThenSolve,
            pybind11::arg("reference"))
        .def("solve", &Solver::solve,
            pybind11::arg("searchLimit"),pybind11::arg("writeSolutions") = false)
        .def("solve_one",&Solver::solve_one)
        .def("setSudoku", &Solver::setSudoku,
            pybind11::arg("reference"))
        .def("loadSudoku", &Solver::loadSudoku,
            pybind11::arg("file"))
        .def("setSolutionFolder", &Solver::setSolutionFolder,
            pybind11::arg("base_path"));
}