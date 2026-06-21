#include "creator.hpp"
#include "solver.hpp"
#include "sudoku.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>

PYBIND11_MODULE(sudoku_py, m) {
  m.doc() = "Sudoku wrapper for python";

  pybind11::class_<Sudoku<9>>(m, "sudoku")
      .def(pybind11::init())
      .def("get", &Sudoku<9>::get)
      .def("set", &Sudoku<9>::set)
      .def("next", &Sudoku<9>::next);

  // Solver Klasse
  pybind11::class_<Solver>(m, "solver")
      .def(pybind11 ::init())
      .def("solve", &Solver::solve)
      // Wir nutzen die Überladung für das direkte Laden eines Sudoku-Objekts
      .def("loadSudoku",
           pybind11::overload_cast<const Sudoku<9> &, std::filesystem::path>(
               &Solver::loadSudoku))
      .def("get_sudoku", &Solver::getSolution);

  // Generator (Creator) Klasse
  pybind11::class_<Creator>(m, "creator")
      .def(pybind11::init())
      .def("setupFromReference", &Creator::setupFromReference)
      .def("build", &Creator::build)
      .def("get_grid", &Creator::getGrid);
}
