//
//  Game.hpp
//  Game
//
//  Created by Rafi Khan on 2016-12-29.
//
//

#ifndef Game_hpp
#define Game_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Game {
    
    public:
        Game(int window_width, int window_height, const char* title);
        void update();
        GLFWwindow* window;
    
        int width;
        int height;
        void destroy();
};

#endif /* Game_hpp */
