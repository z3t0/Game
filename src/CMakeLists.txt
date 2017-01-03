file(GLOB SOURCES *.cpp)
file(GLOB HEADER *.hpp)
file(GLOB RES_FILES *.frag *.vert *.glsl)

add_executable(Game ${SOURCES} ${HEADER} ${RES_FILES})
target_link_libraries(Game glfw libglew_static)
add_custom_command(TARGET Game POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:Game>)
