cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-fmodules-ts")

project(muslib)
add_library(muslib STATIC implementation.cpp)

add_custom_target(muslib_modules)
add_custom_command(TARGET muslib_modules PRE_BUILD COMMAND g++ -std=c++20 -fmodules-ts -x c++-system-header string)
add_dependencies(muslib muslib_modules)