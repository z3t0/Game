cmake_minimum_required (VERSION 2.6)
project (Game)
set (CMAKE_CXX_STANDARD 11)
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

## Libraries
### GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/glfw)
include_directories(libraries/glfw/include)

### GLEW
add_subdirectory(libraries/glew-cmake)
include_directories(libraries/glew-cmake/include)

### GLM
include_directories(libraries/glm)

## Source
add_subdirectory(src bin)
