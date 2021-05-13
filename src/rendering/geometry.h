#ifndef MADID_GEOMETRY_H
#define MADID_GEOMETRY_H

#include <glm/glm.hpp>

#include <GL/glew.h>
#include <vector>
#include "vertex_data.h"

class Geometry {
protected:
    GLuint vao, vbo;

public:
    std::vector<VertexData> vtxData;    // vertices on the CPU

    Geometry();

    virtual void render() = 0;

    ~Geometry();
};


#endif //MADID_GEOMETRY_H
