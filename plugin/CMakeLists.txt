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
"mytgl.c"
)
target_link_libraries(pdplugin libmus)

add_custom_target(test-pd DEPENDS pdplugin "${PROJECT_SOURCE_DIR}/test.pd")
add_custom_command(TARGET test-pd PRE_BUILD COMMAND pd "${PROJECT_SOURCE_DIR}/test.pd")

add_custom_target(test-purr-data DEPENDS pdplugin "${PROJECT_SOURCE_DIR}/test.pd")
add_custom_command(TARGET test-purr-data PRE_BUILD COMMAND purr-data "${PROJECT_SOURCE_DIR}/test.pd")