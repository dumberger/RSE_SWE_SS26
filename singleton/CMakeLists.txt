file(GLOB SOURCES "src/*.cpp")

add_executable(singleton ${SOURCES})
target_include_directories(singleton PRIVATE include)
