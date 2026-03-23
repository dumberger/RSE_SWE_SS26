cmake_minimum_required(VERSION 3.15)

project(RSE_SWE_SS26)

#set(MODULE cpp_list) #wenn ich den Namen (cpp_list) ändere, kann ich eine anderes Projekt starten
set(MODULE cpp_list_homework)

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

add_subdirectory(${MODULE})


