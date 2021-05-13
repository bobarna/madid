#ifndef MADID_MATERIAL_H
#define MADID_MATERIAL_H

#include <glm/glm.hpp>

struct Material {
    glm::vec3 kd, ks, ka;
    float shininess;
};


#endif //MADID_MATERIAL_H
