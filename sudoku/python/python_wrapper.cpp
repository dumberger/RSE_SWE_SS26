#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <filesystem>
#include "sudoku.hpp"
#include "solver.hpp"
#include "generator.hpp"

PYBIND11_MODULE(sudoku_py, m){
    // Beschreibung des Python-Moduls, sichtbar z. B. über `help(sudoku_py)`.
    m.doc() = "Sudoku wrapper for python";

    // Python-Wrapper für die C++-Klasse Sudoku<9>.
    // Die Klasse wird unter dem Namen `sudoku` exportiert, damit die GUI mit
    // denselben Datenstrukturen arbeiten kann wie die C++-Implementierung.
    pybind11::class_<Sudoku<9>>(m, "sudoku")
        .def(pybind11::init())
        .def("get", &Sudoku<9>::get)
        .def("set", &Sudoku<9>::set)
        .def("next", &Sudoku<9>::next);

    // Python-Wrapper für den Solver.
    // `solve()` liefert die Anzahl der gefundenen Lösungen.
    // `loadSudoku(...)` existiert in zwei Varianten:
    // - Laden aus einer Datei
    // - Übernahme eines bereits vorhandenen Sudoku-Objekts
    pybind11::class_<Solver>(m, "solver")
        .def(pybind11::init())
        .def("solve", &Solver::solve)
        .def("loadSudoku", (bool (Solver::*)(std::filesystem::path)) &Solver::loadSudoku)
        .def("loadSudoku", [](Solver& self, const Sudoku<9>& sudoku, const std::string& path) {
            // Python übergibt den Pfad als String. Der C++-Solver erwartet aber
            // einen `std::filesystem::path`, daher wird hier sauber konvertiert.
            return self.loadSudoku(sudoku, std::filesystem::path(path));
        });

    // Python-Wrapper für den Generator.
    // Über `generate()` wird ein neues Sudoku-Rätsel erzeugt, das anschließend
    // direkt in der GUI angezeigt oder an den Solver übergeben werden kann.
    pybind11::class_<Generator>(m, "generator")
        .def(pybind11::init())
        .def("generate", &Generator::generate);
}