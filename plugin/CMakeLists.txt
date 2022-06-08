cmake_minimum_required(VERSION 3.22)

# set(PROJECT_SOURCE_DIR "..")

include("${PROJECT_SOURCE_DIR}/pd.build/pd.cmake")
include_directories("${PROJECT_SOURCE_DIR}/libmus/src")
set_pd_sources("${PROJECT_SOURCE_DIR}/pure-data/src")
set_pd_external_path("${PROJECT_SOURCE_DIR}/externals")

add_pd_external(pdplugin libmus "")
target_sources(pdplugin PRIVATE
"libmus.cpp"
"PitchClass.cpp"
)
# file(GLOB cpp_files *.cpp)
# add_library(pdplugin ${cpp_files})

# set_pd_external_path(${PROJECT_SOURCE_DIR}/externals/)
# add_pd_external(pdplugin mniak ${PROJECT_SOURCE_DIR}/plugin/mniak.cpp)
# target_link_libraries(pdplugin PUBLIC libmus)

# add_custom_target(test-pd DEPENDS test-hello.pd pdplugin)
# add_custom_command(TARGET test-pd PRE_BUILD COMMAND pd ../test-hello.pd)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS "-fmodules-ts")
# set(PROJECT_SOURCE_DIR "..")

# project(pdplugin)
# target_link_libraries(pdplugin PUBLIC mniaklib)

# add_custom_target(test-pd DEPENDS test-hello.pd pdplugin)
# add_custom_command(TARGET test-pd PRE_BUILD COMMAND pd ../test-hello.pd)

# find_package(Catch2 2 REQUIRED)
# target_link_libraries(pdplugin Catch2::Catch2)

# include(Catch)
# catch_discover_tests(pdplugin)

