# ...existing code...
add_library(list_lib src/list.cpp)
target_include_directories(list_lib PUBLIC include)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test_list test/list.cpp)
target_link_libraries(test_list PRIVATE list_lib GTest::gtest_main)
gtest_discover_tests(test_list)
# ...existing code...