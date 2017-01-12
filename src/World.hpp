#ifndef WORLD_HPP
#define WORLD_HPP

#include "Chunk.hpp"
#include "io.hpp"
#include "MeshData.hpp"

#include <vector>

class World {

	public:
        World();
		void update();
		void render();
        MeshData mesh_data;
        std::vector <Chunk> chunks;
    
    
};

static int CHUNK_LENGTH = 4;

#endif
