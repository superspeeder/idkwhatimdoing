cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE KATENGINE_SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.c src/*.cc src/*.cxx)
file(GLOB_RECURSE KATENGINE_HEADERS CONFIGURE_DEPENDS include/*.hpp include/*.h include/*.hxx)

add_library(katengine ${KATENGINE_SOURCES} ${KATENGINE_HEADERS})
target_include_directories(katengine PUBLIC include/)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${KATENGINE_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${KATENGINE_HEADERS})


add_library(kat::engine ALIAS katengine)