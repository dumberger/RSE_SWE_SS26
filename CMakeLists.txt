cmake_minimum_required(VERSION 3.15)

project(RSE_SWE_SS26_CM CXX)

set(MODULE cpp_list)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

add_executable(ListWithTests 
    ${MODULE}/src/list.cpp 
    ${MODULE}/src/main.cpp
)

gtest_discover_tests(ListWithTests)

target_include_directories(ListWithTests PRIVATE ${MODULE}/include)

add_subdirectory(${MODULE})