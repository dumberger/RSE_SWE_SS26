cmake_minimum_required(VERSION 3.22)

project(pyblind_test)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(adder adder.cpp)
