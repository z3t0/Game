#ifndef WORLD_HPP
#define WORLD_HPP

#include "Chunk.hpp"
#include "io.hpp"
#include "MeshData.hpp"

class World {

	public:
        World();
		void update();
		void render();
        MeshData mesh_data;
		Chunk chunk;
};

#endif
