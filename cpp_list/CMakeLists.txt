file(GLOB SOURCES "src/*.cpp")

add_executable(list ${SOURCES})
target_include_directories(list PRIVATE include)
target_compile_options(list PRIVATE -g3 -O0 -fno-omit-frame-pointer -fno-inline)

add_executable(test_list src/list.cpp test/list.cpp)
target_include_directories(test_list PRIVATE include)
target_link_libraries(test_list GTest::gtest_main)
target_compile_options(test_list PRIVATE -g3 -O0 -fno-omit-frame-pointer -fno-inline)
gtest_discover_tests(test_list)

