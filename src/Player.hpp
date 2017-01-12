//
//  Player.hpp
//  Game
//
//  Created by Rafi Khan on 2017-01-12.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>


class World;

class Player {
public:
    Player(std::string player_name, World *player_world);
    
    std::string name;
    World *world;
    

};


#endif /* Player_hpp */
