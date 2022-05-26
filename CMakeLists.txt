cmake_minimum_required(VERSION 3.23)

# set(CMAKE_SUPPRESS_REGENERATION true)
# set(CMAKE_MACOSX_RPATH Off)
# set(CMAKE_OSX_DEPLOYMENT_TARGET 10.4)
# set(CMAKE_OSX_ARCHITECTURES "i386;x86_64")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-fmodules-ts")
set(PROJECT_SOURCE_DIR "..")

project(mniaklib)
include(pd.build/pd.cmake)

set_pd_external_path(${PROJECT_SOURCE_DIR}/externals/)
add_pd_external(pd_plugin mniak ${PROJECT_SOURCE_DIR}/lib/mniak.cpp)

add_custom_target(modules)
add_custom_command(TARGET modules PRE_BUILD COMMAND g++ -std=c++20 -fmodules-ts -x c++-system-header string)
add_dependencies(pd_plugin modules)

add_custom_target(test-pd DEPENDS test-hello.pd pd_plugin)
add_custom_command(TARGET test-pd PRE_BUILD COMMAND pd ../test-hello.pd)
