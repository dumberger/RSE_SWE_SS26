file(GLOB SOURCES "src/*.cpp")
add_executable(double_linked_cpplist ${SOURCES})
target_include_directories(double_linked_cpplist PRIVATE include)


add_executable(test_list src/d_list.cpp test/d_list.cpp)
target_include_directories(test_list PRIVATE include)
target_link_libraries(test_list GTest::gtest_main)
gtest_discover_tests(test_list)