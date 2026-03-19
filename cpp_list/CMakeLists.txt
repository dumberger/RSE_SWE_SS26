file(GLOB SOURCES "src/*.cpp")
add_executable(list ${SOURCES})
target_include_directories(list PRIVATE include)