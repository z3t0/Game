//
//  MeshData.cpp
//  Game
//
//  Created by Rafi Khan on 2017-01-10.
//
//

#include "MeshData.hpp"

void MeshData::addVertex(float x, float y, float z) {
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
    
    vert_count++;
}

void MeshData::addIndices() {
    
    indices.push_back(vert_count - 4);
    indices.push_back(vert_count - 1);
    indices.push_back(vert_count - 3);
    
    // Triangle 2
    indices.push_back(vert_count - 3);
    indices.push_back(vert_count - 2);
    indices.push_back(vert_count - 1);
  
}
