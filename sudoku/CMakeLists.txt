file(GLOB SOURCES "src/*.cpp")
add_executable(sudoku ${SOURCES})
target_include_directories(sudoku PRIVATE include)

add_executable(test_sudoku test/sudoku.cpp)
target_include_directories(test_sudoku PRIVATE include)
target_link_libraries(test_sudoku GTest::gtest_main)
gtest_discover_tests(test_sudoku)

set(PYBIND11 FINDPYTHON ON)

# pybind11 wird nur für das Python-Modul benötigt.
# Das native Sudoku-Programm und die C++-Tests sollen davon unabhängig bleiben.
find_package(pybind11 CONFIG REQUIRED)

# Das Python-Modul wird aus dem Wrapper sowie den C++-Implementierungen von
# Solver und Generator gebaut. Dadurch benutzt Python exakt dieselbe Logik wie
# das native Programm.
pybind11_add_module(sudoku_py 
    python/python_wrapper.cpp
    src/solver.cpp
    src/generator.cpp
)
target_include_directories(sudoku_py PRIVATE include)

# Das erzeugte Shared Module landet direkt im Python-Ordner, damit es von
# `sudoku.py` ohne zusätzliche Kopier-Schritte importiert werden kann.
set_target_properties(sudoku_py PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../sudoku/python
)