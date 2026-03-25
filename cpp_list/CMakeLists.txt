file(GLOB SOURCES "src/*.cpp")
add_executable(list ${SOURCES})
target_include_directories(list PRIVATE include)


add_executable(test_list src/list.cpp test/list.cpp)
target_include_directories(test_list PRIVATE include)
target_link_libraries(test_list GTest::gtest_main)
gtest_discover_tests(test_list)