//
//  MeshData.hpp
//  Game
//
//  Created by Rafi Khan on 2017-01-10.
//
//

#ifndef MeshData_hpp
#define MeshData_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

class MeshData {
    
public:
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    GLuint vert_count = 0;
    
    void addVertex(float x, float y, float z);
    void addIndices();
};

#endif /* MeshData_hpp */
