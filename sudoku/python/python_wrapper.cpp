#include <pybind11/pybind11.h>
#include "sudoku.hpp"
#include "creator.hpp"
#include "solver.hpp"

PYBIND11_MODULE(sudoku_py, m){
    m.doc() = "Sudoku wrapper for python";

    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())

        .def("get", [](Sudoku<9>& sudoku, std::size_t row, std::size_t col) {
            return std::string(1, sudoku.get(row, col));
        })
        .def("set", [](Sudoku<9>& sudoku, std::size_t row, std::size_t col, const std::string& value) {
            if (value.size() != 1) {
                return false;
            }
            return sudoku.set(row, col, value[0]);
        })
        .def("next", &Sudoku<9>::next);

    pybind11::class_<Solver>(m, "sudoku_solver")
        .def(pybind11::init<>())
        .def("solve", &Solver::solve)
        .def("get_sudoku", &Solver::getSudoku);

     pybind11::class_<Creator>(m, "sudoku_generator")
        .def(pybind11::init([](const std::string& base_path) {
            return new Creator(std::filesystem::path(base_path));
        }), pybind11::arg("base_path") = ".")
        .def("create", &Creator::create)
        .def("trim_Sudoku", &Creator::trim_Sudoku)
        .def("get_sudoku", &Creator::getSudoku);   
}