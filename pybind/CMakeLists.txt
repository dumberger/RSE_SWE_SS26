cmake_minimum_required(VERSION 3.22)

project(pybind_test)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(adder adder.cpp)

set_target_properties(adder PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../pybind
)