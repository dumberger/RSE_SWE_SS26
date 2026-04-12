file(GLOB SOURCES "src/*.cpp")

set(TEST_SOURCES ${SOURCES})
list(REMOVE_ITEM TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_executable(list ${SOURCES})
target_include_directories(list PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_executable(test_list ${TEST_SOURCES} test/list.cpp)
target_include_directories(test_list PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(test_list PRIVATE GTest::gtest_main)
gtest_discover_tests(test_list)