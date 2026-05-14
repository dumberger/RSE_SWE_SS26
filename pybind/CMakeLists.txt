cmake_minimum_required(VERSION 3.16)

project(pybind_test)

set(PYBIND11 FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(adder adder.cpp)

set_target_properties(adder PROPERTIES 
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../pybind)
