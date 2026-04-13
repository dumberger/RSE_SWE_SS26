cmake_minimum_required(VERSION 3.15)

project(C_List LANGUAGES C)

add_executable(list list.c main.c)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER gcc)