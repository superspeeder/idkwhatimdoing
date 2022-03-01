cmake_minimum_required (VERSION 3.8)

project ("katengine")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)


add_subdirectory ("engine")
add_subdirectory ("app")

set_target_properties(katengine app PROPERTIES CXX_STANDARD 20)
set_target_properties(katengine app PROPERTIES CXX_STANDARD_REQUIRED TRUE)