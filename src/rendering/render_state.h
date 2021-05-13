#ifndef MADID_RENDER_STATE_H
#define MADID_RENDER_STATE_H

#include "materials/material.h"
#include "lights/light.h"
#include "textures/texture.h"

using namespace glm;

struct RenderState {
    mat4 MVP, M, Minv, V, P;
    vec3 wEye;
    Texture *texture;
    Material *material;

    std::vector<Light> lights;
};


#endif //MADID_RENDER_STATE_H
