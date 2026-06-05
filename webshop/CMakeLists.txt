file(GLOB SOURCES "src/*.cpp")
add_executable(webshop ${SOURCES})
target_include_directories(webshop PRIVATE include)

add_executable(test_webshop test/webshop.cpp)
target_include_directories(test_webshop PRIVATE include)
target_link_libraries(test_webshop GTest::gtest_main)
gtest_discover_tests(test_webshop)
