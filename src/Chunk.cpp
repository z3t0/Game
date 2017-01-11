#include "Chunk.hpp"

int Flat(int x, int y, int z) {
    return (x + Chunk::CHUNK_SIZE * (y + Chunk::CHUNK_SIZE * z));

}

Chunk::Chunk() {
	// Create the blocks
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                blocks.push_back(Block(x, y, z));
            }
        }
    }
    
    blocks[Flat(0, 0, -3)].setType(BlockType_Stone);
    
    
	rebuild = true;
}

void Chunk::buildMesh() {
    
    for(int x = 0; x < CHUNK_SIZE; x++) {
        
        for(int y = 0; y < CHUNK_SIZE; y++) {
         
            for(int z = 0; z < CHUNK_SIZE; z++) {
                auto block = blocks[Flat(x, y, z)];
                
                if (block.getType() == BlockType_Air)
                    continue;
                
                block.buildMesh(mesh_data);
            }
        }
    }
    
    rebuild = false;
}

void Chunk::setBlock(int x, int y, int z, BlockType block_type) {
    blocks[(Flat(x, y, z))].setType(block_type);
}
