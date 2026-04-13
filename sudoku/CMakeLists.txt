file(GLOB SOURCES "src/*.cpp")
add_executable(sudoku ${SOURCES})
target_include_directories(sudoku PUBLIC includes)

add_executable(test_sudoku test/sudoku.cpp)
target_include_directories(test_sudoku PRIVATE includes)
target_link_libraries(test_sudoku GTest::gtest_main)
gtest_discover_tests(test_sudoku)
