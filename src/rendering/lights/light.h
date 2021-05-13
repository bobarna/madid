#ifndef MADID_LIGHT_H
#define MADID_LIGHT_H

#include <glm/glm.hpp>

class Light {
    // homogenous coordinates, can be at ideal point

    void Animate(float t);

public:
    glm::vec3 La;
    glm::vec3 Le;
    glm::vec4 wLightPos;
};


#endif //MADID_LIGHT_H
