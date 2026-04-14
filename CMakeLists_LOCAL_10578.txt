
cmake_minimum_required(VERSION 3.15)

project(RSE_SWE_SS26)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")

set(MODULE cpp_list)

# Fix für FetchContent auf Filesystemen mit Umbenennungsproblemen
cmake_policy(SET CMP0135 NEW)

include(FetchContent)
FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG 03597a01ee50ed33e9dfd640b249b4be3799d395
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

add_subdirectory(${MODULE})

