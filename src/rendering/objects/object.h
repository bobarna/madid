#ifndef MADID_OBJECT_H
#define MADID_OBJECT_H

#include <glm/glm.hpp>
#include "../../utility/custom_math.h"
#include "../geometry.h"
#include "../shaders/shader.h"
#include "../materials/material.h"

using namespace glm;

class Object {
protected:
    vec3 scale, translation, rotationAxis;
    float rotationAngle;

    Geometry *geometry;
    Shader *shader;
    Material *material;
    Texture *texture;
public:
    Object(Shader *_shader, Geometry *_sim, Material *_material = nullptr, Texture *_texture = nullptr);

    virtual void SetModelingTransform(mat4 &M, mat4 &Minv);

    void render(RenderState state);

    virtual void update(float delta_t);

    void Scale(vec3 s);

    void Translate(vec3 t);

    void Rotate(vec3 axis, float angle);
};


#endif //MADID_OBJECT_H
