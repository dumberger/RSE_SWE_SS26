file(GLOB SOURCES "src/*.cpp")
add_executable(sudoku ${SOURCES})
target_include_directories(sudoku PRIVATE include)

add_executable(test_sudoku test/sudoku.cpp)
target_include_directories(test_sudoku PRIVATE include)
target_link_libraries(test_sudoku GTest::gtest_main)
gtest_discover_tests(test_sudoku)

set(PYBIND11 FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(sudoku_py python/python_wrapper.cpp)
target_include_directories(sudoku_py PRIVATE include)

set_target_properties(sudoku_py PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../sudoku/python
)