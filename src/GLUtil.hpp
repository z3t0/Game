//
//  GLUtil.hpp
//  Game
//
//  Created by Rafi Khan on 2016-12-29.
//
//

#ifndef GLUtil_hpp
#define GLUtil_hpp


#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "io.hpp"

GLuint load_shader(const char* path, GLenum shader_type);

#endif /* GLUtil_hpp */
