include_directories(${PROJECT_SRC_DIR}/src/)

add_executable(Game main.cpp)
target_link_libraries(Game glfw libglew_static)
