//
//  Game.cpp
//  Game
//
//  Created by Rafi Khan on 2016-12-29.
//
//

// Includes
#include "Game.hpp"

#include <iostream>

GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};

GLuint vbo;

Game::Game(int window_width, int window_height, const char* title) {
    std::cout << "Creating Game..." << std::endl;

    // GLFW

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    #if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    // Create Window

    window = glfwCreateWindow(window_width , window_height, title, nullptr, nullptr);

    if(window == nullptr)
    {
        std::cout << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        throw "Failed to initialize GLFW";
    }

    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        throw "Failed to initialize GLEW";
    }

    // Get and Set Viewport Dimensions
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    init();
}

void Game::init() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint vertex_shader = load_shader("basic.vert", GL_VERTEX_SHADER);
    GLuint fragment_shader = load_shader("basic.frag", GL_FRAGMENT_SHADER);

		// TODO: error checking
		GLuint shader_program = glCreateProgram();
		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, fragment_shader);
		glLinkProgram(shader_program);
		glUseProgram(shader_program);

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) 0);
		glEnableVertexAttribArray(0);

}

void Game::update () {
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
    }
}

void Game::render() {

}

void Game::destroy() {
    glfwTerminate();
}
