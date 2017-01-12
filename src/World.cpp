#include "World.hpp"

int FlatWorld(int x, int y, int z) {
    return (x + CHUNK_LENGTH * (y + CHUNK_LENGTH * z));
    
}

World::World(Game *game_reference) : player("Player 1", this) {
     
    game = game_reference;
    
     // Set up Chunks
     for (int x = 0; x < CHUNK_LENGTH; x++) {
         for (int y = 0; y < CHUNK_LENGTH; y++) {
             for (int z = 0; z < CHUNK_LENGTH; z++) {
                 
                 chunks.push_back(Chunk(x, y, z));
                 
             }
         }
     }
     
     chunks[FlatWorld(0,0,0)].setBlock(0, 0, 0, BlockType_Stone);
     
 }

void World::update() {
    
    for (int x = 0; x < CHUNK_LENGTH; x++) {
        for (int y = 0; y < CHUNK_LENGTH; y++) {
            for (int z = 0; z < CHUNK_LENGTH; z++) {
                
                auto chunk = chunks[FlatWorld(x, y, z)];
                
                if(chunk.rebuild) {
                    chunk.buildMesh();
                    mesh_data.vertices.insert(mesh_data.vertices.end(), chunk.mesh_data.vertices.begin(), chunk.mesh_data.vertices.end());
                    mesh_data.indices.insert(mesh_data.indices.end(), chunk.mesh_data.indices.begin(), chunk.mesh_data.indices.end());
                    mesh_data.vert_count += chunk.mesh_data.vert_count;
                }
                
            }
        }
    }

}

void World::render() {

    println("render");
}
