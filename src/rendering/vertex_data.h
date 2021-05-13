
#ifndef MADID_VERTEX_DATA_H
#define MADID_VERTEX_DATA_H

#include <glm/glm.hpp>

struct VertexData {
    // needed for GetVertexByUV function
    bool valid = true;
    glm::vec3 position, normal;
    glm::vec2 texcoord;
    VertexData();
    VertexData(glm::vec3 p, glm::vec3 n, glm::vec2 uv);
    explicit VertexData(bool valid, glm::vec3 p = {0,0,0}, glm::vec3 n = {0,0,0}, glm::vec2 uv = {0,0}){};
};

#endif //MADID_VERTEX_DATA_H
