cmake_minimum_required(VERSION 3.1)
project(library)
add_compile_options(-Wall -g -pedantic -pedantic-errors)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
include_directories(./include)
add_subdirectory(src)
add_executable(exec ./src/main.cpp)
target_link_libraries(exec library)
add_custom_target(valgrind COMMAND valgrind ./exec DEPENDS exec)
