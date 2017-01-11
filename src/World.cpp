#include "World.hpp"

 World::World() { 
     chunk.setBlock(0,0,0, BlockType_Stone);
 } 

void World::update() {
    
	if(chunk.rebuild) {
		println("Need to rebuild mesh");
        chunk.buildMesh();
        mesh_data = chunk.mesh_data;
    }

}

void World::render() {

    println("render");
}
