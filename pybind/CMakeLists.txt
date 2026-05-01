cmake_minimum_required(VERSION 3.15)

project(pybind_Test)

set(PYBIND11 FINDPYTHON ON) 
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(adder adder.cpp)