//
//  GLUtil.cpp
//  Game
//
//  Created by Rafi Khan on 2016-12-29.
//
//

#include "GLUtil.hpp"

GLuint load_shader(const char* path, GLenum shader_type) {
    GLuint shader;
    shader = glCreateShader(shader_type);

    std::string source = read_file(path);
    const GLchar *s = (const GLchar *)source.c_str();

    glShaderSource(shader, 1, &s, NULL);
    glCompileShader(shader);

		// Check for errors
		GLint success;
		GLchar infoLog[512];

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if(!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "Shader failed to compile at :'" << path << "'" << infoLog << std::endl;
		}

    return shader;
}
