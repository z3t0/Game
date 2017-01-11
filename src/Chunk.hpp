#ifndef CHUNK_HPP
#define CHUNK_HPP

#include "Block.hpp"
#include "MeshData.hpp"

class Chunk {

	public:
		Chunk();
		void buildMesh();
        void setBlock(int x, int y, int z, BlockType block_type);
    
		static const int CHUNK_SIZE = 16;
        bool rebuild;
        MeshData mesh_data;
    

	private:
        std::vector<Block> blocks;

};

#endif
