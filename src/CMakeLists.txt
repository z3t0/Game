file(GLOB SOURCES *.cpp)

add_executable(Game ${SOURCES})
target_link_libraries(Game glfw libglew_static)
