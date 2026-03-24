file(GLOB SOURCES "src/*.cpp")
add_executable(cpp_double_list ${SOURCES})
target_include_directories(cpp_double_list PRIVATE include)

add_executable(test_cpp_double_list src/cpp_double_list.cpp test/test_cpp_double_list.cpp)
target_include_directories(test_cpp_double_list PRIVATE include)
target_link_libraries(test_cpp_double_list GTest::gtest_main)
gtest_discover_tests(test_cpp_double_list)