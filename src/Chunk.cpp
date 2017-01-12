#include "Chunk.hpp"

int Flat(int x, int y, int z) {
    return (x + Chunk::CHUNK_SIZE * (y + Chunk::CHUNK_SIZE * z));

}

Chunk::Chunk(int px, int py, int pz) {
	// Create the blocks
    for (int x = px; x < px + CHUNK_SIZE; x++) {
        for (int y = py; y < py + CHUNK_SIZE; y++) {
            for (int z = pz; z < pz + CHUNK_SIZE; z++) {
                blocks.push_back(Block(x, y, z));
            }
        }
    }
   
    x = px;
    y = py;
    z = pz;
    
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
