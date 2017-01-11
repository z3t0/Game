// Block.hpp

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "MeshData.hpp"
#include "io.hpp"

enum BlockType {
	BlockType_Air,
	BlockType_Grass,
	BlockType_Stone
};

class Block {
	public:
		Block(int x, int y, int z);
		
        BlockType getType();
    
        void setType(BlockType block_type);
        void buildMesh(MeshData &mesh_data);
    
        int x;
        int y;
        int z;
    
		BlockType type;
};

#endif /* io_hpp */
