//
//  GLUtil.cpp
//  Game
//
//  Created by Rafi Khan on 2016-12-29.
//
//

#include "GLUtil.hpp"

GLuint load_vertex_shader(const char* path) {
    GLuint shader;
    shader = glCreateShader(GL_VERTEX_SHADER);
    std::string source = read_file("basic.vert");
    const GLchar *s = (const GLchar *)source.c_str();
    
    glShaderSource(shader, 1, &s, NULL);
    glCompileShader(shader);
    
    return shader;
}
