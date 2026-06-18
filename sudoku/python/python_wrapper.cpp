#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>

#include "sudoku.hpp"
#include "generator.hpp"
#include "solver.hpp"

namespace py = pybind11;

namespace {

// helper: solve a given Sudoku and return the solved board (reads solver output)
Sudoku<9> solve_sudoku_copy(const Sudoku<9>& reference) {
    Solver solver;
    const auto base_path = std::filesystem::temp_directory_path() / "sudoku_pybind";
    std::filesystem::create_directories(base_path / "results");

    solver.loadSudoku(reference, base_path);
    solver.solve();

    Sudoku<9> solved = reference;
    std::ifstream solution_file(base_path / "results" / "0.txt");
    if (solution_file) {
        solution_file >> solved;
    }
    return solved;
}

} // namespace

PYBIND11_MODULE(sudoku_py, m) {
    m.doc() = "Sudoku wrapper for python";

    // Sudoku<9> binding
    py::class_<Sudoku<9>>(m, "sudoku")
        .def(py::init<>())
        .def("get", [](const Sudoku<9>& s, std::size_t r, std::size_t c){
            return std::string(1, s.get(r, c));
        })
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next)
        .def("__str__", [](const Sudoku<9>& s){
            std::ostringstream os;
            os << const_cast<Sudoku<9>&>(s);
            return os.str();
        });

    // Solver binding
    py::class_<Solver>(m, "solver")
        .def(py::init<>())
        .def("load_sudoku_from_file", [](Solver& solver, const std::filesystem::path& file){
            return solver.loadSudoku(file);
        })
        .def("load_sudoku", [](Solver& solver, const Sudoku<9>& reference, const std::filesystem::path& base_path){
            return solver.loadSudoku(reference, base_path);
        })
        .def("solve", &Solver::solve);

    // Generator binding
    py::class_<SudokuGenerator>(m, "generator")
        .def_static("generate_solved", &SudokuGenerator::generateSolved)
        .def_static("generate_puzzle", &SudokuGenerator::generatePuzzle, py::arg("difficulty") = 40)
        .def_static("write_to_file", &SudokuGenerator::writeToFile);

    // convenience functions
    m.def("solve_sudoku", &solve_sudoku_copy, "Solve a Sudoku and return the solved board");
    m.def("generate_solved", &SudokuGenerator::generateSolved, "Generate a solved Sudoku");
    m.def("generate_puzzle", &SudokuGenerator::generatePuzzle, py::arg("difficulty") = 40, "Generate a Sudoku puzzle");
}

