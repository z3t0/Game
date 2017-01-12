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
    0.5f,  0.5f, 0.0f,  // Top Right
    0.5f, -0.5f, 0.0f,  // Bottom Right
    -0.5f, -0.5f, 0.0f,  // Bottom Left
    -0.5f,  0.5f, 0.0f   // Top Left
};

GLuint indices[] = {  // Note that we start from 0!
    0, 3, 1,   // First Triangle
    1, 2, 3    // Second Triangle
};

GLuint vbo;
GLuint vao;
GLuint ebo;
GLuint shader_program;

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
    
    world.update();
    
    
    // Shaders
    // TODO: error checking
    GLuint vertex_shader = load_shader("basic.vert", GL_VERTEX_SHADER);
    GLuint fragment_shader = load_shader("basic.frag", GL_FRAGMENT_SHADER);

    
    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    glUseProgram(shader_program);
    
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    
    // Transformations

    
    
    // Buffers
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    
    glGenVertexArrays(1, &vao);
    
    // VAO
    glBindVertexArray(vao);
    
    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 3 * world.mesh_data.vert_count * sizeof(GLfloat), world.mesh_data.vertices.data(), GL_DYNAMIC_DRAW);
    
    // EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, world.mesh_data.indices.size() * sizeof(GLuint), &world.mesh_data.indices[0], GL_DYNAMIC_DRAW);
    
    
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

void Game::update () {
    while(!glfwWindowShouldClose(window))
    {
        world.update();
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        render();
        
        glfwSwapBuffers(window);
    }
    
    
}

GLfloat rotation = 0;

void Game::render() {
    glm::vec4 vec(0.0f, 0.0f, 0.0f, 1.0f);
    glm::mat4 trans;
    trans = glm::rotate(trans, rotation, glm::vec3(1.0, 1.0, 1.0));
    vec = trans * vec;
    std::cout << vec.x << vec.y << vec.z << std::endl;
    
    rotation +=0.01;
    
    GLuint transformLoc = glGetUniformLocation(shader_program, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
    
    glUseProgram(shader_program);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Game::destroy() {
    glfwTerminate();
}
