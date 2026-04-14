file(GLOB SOURCES "src/*.cpp")
add_executable(sudoku ${SOURCES})
target_include_directories(sudoku PRIVATE include)


add_executable(test_sudoku src/sudoku.cpp test/sudoku.cpp)
target_include_directories(test_sudoku PRIVATE include)
target_link_libraries(test_sudoku GTest::gtest_main)
gtest_discover_tests(test_sudoku)