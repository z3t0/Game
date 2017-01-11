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
    println("Building Mesh Data...");
    
    // Up
//    mesh_data.addVertex(x - 0.5f, y + 0.5f, z + 0.5f);
//    mesh_data.addVertex(x + 0.5f, y + 0.5f, z + 0.5f);
//    mesh_data.addVertex(x + 0.5f, y + 0.5f, z - 0.5f);
//    mesh_data.addVertex(x - 0.5f, y + 0.5f, z - 0.5f);
//    mesh_data.addIndices();
    
    // Down
    
    // Left
    
    // Right
    
    // Front
    
    // Back
//    mesh_data.addVertex(x - 0.5, y + 0.5, z + 0.5);
//    mesh_data.addVertex(x + 0.5, y - 0.5, z + 0.5);
//    mesh_data.addVertex(x + 0.5, y + 0.5, z + 0.5);
//    mesh_data.addVertex(x - 0.5, y - 0.5, z + 0.5);
    
      // 0, 2, 1
      // 3, 2, 1
      mesh_data.addVertex(x - 0.5, y + 0.5, z + 0.5);
      mesh_data.addVertex(x + 0.5, y + 0.5, z + 0.5);
      mesh_data.addVertex(x + 0.5, y - 0.5, z + 0.5);
      mesh_data.addVertex(x - 0.5, y - 0.5, z + 0.5);
    
      mesh_data.addIndices();
    
    // repeated
//    mesh_data.addVertex(x + 0.5, y - 0.5, z + 0.5);
//    mesh_data.addVertex(x - 0.5, y + 0.5, z + 0.5);
    
    
//    mesh_data.addVertex(x - 0.5f, y - 0.5f, z + 0.5f);  // 0
//    mesh_data.addVertex(x + 0.5f, y - 0.5f, z + 0.5f);    // 3
//
//    mesh_data.addVertex(x - 0.5f, y + 0.5f, z + 0.5f);  // 1
//    mesh_data.addVertex(x + 0.5f, y + 0.5f, z + 0.5f);  // 2
//    mesh_data.addIndices();

}
