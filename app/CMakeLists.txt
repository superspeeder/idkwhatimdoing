cmake_minimum_required (VERSION 3.20.4)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.c src/*.cc src/*.cxx)
file(GLOB_RECURSE APP_HEADERS CONFIGURE_DEPENDS include/*.hpp include/*.h include/*.hxx)

add_executable(app ${APP_SOURCES} ${APP_HEADERS})
target_include_directories(app PRIVATE include/)
target_link_libraries(app PRIVATE kat::engine)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${APP_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${APP_HEADERS})
