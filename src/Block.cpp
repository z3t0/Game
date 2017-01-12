// Block
// by Rafi Khan

#include "Block.hpp"

Block::Block(int posX, int posY, int posZ) {
    // FIXME: change to air
    type = BlockType_Air;
    x = posX;
    y = posY;
    z = posZ;
}

BlockType Block::getType() {
	return type;
}

void Block::setType(BlockType block_type) {
    type = block_type;
}

void Block::buildMesh(MeshData &mesh_data) {
    
    // Up
    mesh_data.addVertex(x - 0.5f, y + 0.5f, z + 0.5f);
    mesh_data.addVertex(x + 0.5f, y + 0.5f, z + 0.5f);
    mesh_data.addVertex(x + 0.5f, y + 0.5f, z - 0.5f);
    mesh_data.addVertex(x - 0.5f, y + 0.5f, z - 0.5f);
    
    mesh_data.addIndices();
    
    // Down
    mesh_data.addVertex(x - 0.5f, y - 0.5f, z + 0.5f);
    mesh_data.addVertex(x + 0.5f, y - 0.5f, z + 0.5f);
    mesh_data.addVertex(x + 0.5f, y - 0.5f, z - 0.5f);
    mesh_data.addVertex(x - 0.5f, y - 0.5f, z - 0.5f);
    
    mesh_data.addIndices();
    
    // Left
    mesh_data.addVertex(x - 0.5f, y - 0.5f, z + 0.5f);
    mesh_data.addVertex(x - 0.5f, y + 0.5f, z + 0.5f);
    mesh_data.addVertex(x - 0.5f, y + 0.5f, z - 0.5f);
    mesh_data.addVertex(x - 0.5f, y - 0.5f, z - 0.5f);
    
    mesh_data.addIndices();
    
    // Right
    mesh_data.addVertex(x + 0.5f, y - 0.5f, z + 0.5f);
    mesh_data.addVertex(x + 0.5f, y + 0.5f, z + 0.5f);
    mesh_data.addVertex(x + 0.5f, y + 0.5f, z - 0.5f);
    mesh_data.addVertex(x + 0.5f, y - 0.5f, z - 0.5f);

    
    // Front
    mesh_data.addVertex(x - 0.5, y + 0.5, z - 0.5);
    mesh_data.addVertex(x + 0.5, y + 0.5, z - 0.5);
    mesh_data.addVertex(x + 0.5, y - 0.5, z - 0.5);
    mesh_data.addVertex(x - 0.5, y - 0.5, z - 0.5);
    
    mesh_data.addIndices();
    
    // Back
    mesh_data.addVertex(x - 0.5, y + 0.5, z + 0.5);
    mesh_data.addVertex(x + 0.5, y + 0.5, z + 0.5);
    mesh_data.addVertex(x + 0.5, y - 0.5, z + 0.5);
    mesh_data.addVertex(x - 0.5, y - 0.5, z + 0.5);
    
    mesh_data.addIndices();

}
