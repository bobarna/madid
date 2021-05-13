#include "vertex_data.h"

VertexData::VertexData(glm::vec3 p, glm::vec3 n, glm::vec2 uv) :
        position(p), normal(n), texcoord(uv) {
}

VertexData::VertexData() {
}