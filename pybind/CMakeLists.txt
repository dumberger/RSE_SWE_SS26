cmake_minimum_required(VERSION 3.22)

project(pybind_test)

set (PYBIND11 FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)