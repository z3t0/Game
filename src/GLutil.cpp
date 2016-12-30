// OpenGL Utilities
#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "GLutil.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// Close when ESC is pressed
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
