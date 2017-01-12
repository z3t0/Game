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

GLfloat rotationX = 0;
GLfloat rotationY = 0;
GLfloat rotationZ = 0;

int keyState[4] = {0 , 0, 0, 0};
float speed = 0.1;

void key_up(int action) {
    if (action == GLFW_PRESS || keyState[0] == 1) {
        keyState[0] = 1;
        rotationX += speed;
    }
    
    else
        keyState[0] = 0;
}

void key_down(int action) {
    if (action == GLFW_PRESS || keyState[1] == 1) {
        keyState[1] = 1;
        rotationX -= speed;
    }
    
    else
        keyState[1] = 0;}

void key_left(int action) {
    if (action == GLFW_PRESS || keyState[2] == 1) {
        keyState[2] = 1;
        rotationZ += speed;
    }
    
    else
        keyState[2] = 0;}

void key_right(int action) {
    if (action == GLFW_PRESS || keyState[3] == 1) {
        keyState[3] = 1;
        rotationY += speed;
    }
    
    else
        keyState[3] = 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_UP)
        key_up(action);
    
    if(key == GLFW_KEY_DOWN)
        key_down(action);
    
    if(key == GLFW_KEY_LEFT)
        key_left(action);
    
    if(key == GLFW_KEY_RIGHT)
        key_right(action);
}


// Variables


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

Game::Game(int ww, int wh, const char* title) {
    std::cout << "Creating Game..." << std::endl;
    
    // GLFW
    
    window_width = ww;
    window_height = wh;
    
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
    glfwSetKeyCallback(window, key_callback);
    
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
    
//    glEnable(GL_DEPTH_TEST); // Depth Testing
//    glDepthFunc(GL_LEQUAL);
//    glDisable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
    
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
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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

void Game::render() {
    
    glUseProgram(shader_program);

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    
//    model = glm::rotate(model, rotationX, glm::vec3(1, 1, 1.0));
//    model = glm::translate(model, glm::vec3(0, rotationX, rotationY));
     model = glm::rotate(model, rotationX, glm::vec3(1.0f, 0.0f, 0.0f));
     model = glm::rotate(model, rotationY, glm::vec3(0.0f, 1.0f, 0.0f));
     model = glm::rotate(model, rotationZ, glm::vec3(0.0f, 0.0f, 1.0f));

//    model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
//    model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
//    model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
    projection = glm::perspective(45.0f, (GLfloat)window_width / (GLfloat)window_height, 0.1f, 100.0f);
    
    // Get their uniform location
    GLint modelLoc = glGetUniformLocation(shader_program, "model");
    GLint viewLoc = glGetUniformLocation(shader_program, "view");
    GLint projLoc = glGetUniformLocation(shader_program, "projection");
    
    // Pass them to the shaders
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    
    
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, world.mesh_data.indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Game::destroy() {
    glfwTerminate();
}
