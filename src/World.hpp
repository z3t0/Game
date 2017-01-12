#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "Chunk.hpp"
#include "io.hpp"
#include "MeshData.hpp"
#include "Player.hpp"

class Game;

class World {

	public:
        World(Game *game_reference);
		void update();
		void render();
        MeshData mesh_data;
        std::vector <Chunk> chunks;
        Player player;
        Game *game;
    
};

static int CHUNK_LENGTH = 4;

#endif
