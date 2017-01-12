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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GLUtil.hpp"
#include "World.hpp"


class Game {

	public:
		Game(int window_width, int window_height, const char* title);
		void init();
		void update();
		void render();
		GLFWwindow* window;


		int width;
		int height;
        int window_width;
        int window_height;
		void destroy();
        World world;

};

#endif /* Game_hpp */
